#workaround for seg2virtual until we get something reasonably better
import os

"""
Because segmented addresses mess up symbol generaton,
this custom segtype aims to fix that.
At least by fixing vtx's.
"""

import re
from typing import Optional

from pathlib import Path

from pygfxd import (
    gfxd_buffer_to_string,
    gfxd_cimg_callback,
    gfxd_dl_callback,
    gfxd_endian,
    gfxd_execute,
    gfxd_input_buffer,
    gfxd_light_callback,
    gfxd_lookat_callback,
    gfxd_macro_dflt,
    gfxd_macro_fn,
    gfxd_mtx_callback,
    gfxd_output_buffer,
    gfxd_printf,
    gfxd_puts,
    gfxd_target,
    gfxd_timg_callback,
    gfxd_tlut_callback,
    gfxd_vp_callback,
    gfxd_vtx_callback,
    gfxd_zimg_callback,
    GfxdEndian,
    gfxd_f3d,
    gfxd_f3db,
    gfxd_f3dex,
    gfxd_f3dexb,
    gfxd_f3dex2,
)
from segtypes.segment import Segment

from util import log, options
from util.log import error

from segtypes.n64.gfx import N64SegGfx

from util import symbols

LIGHTS_RE = re.compile(r"\*\(Lightsn \*\)0x[0-9A-F]{8}")

class N64SegGfxSeg(N64SegGfx):

    def vtx_handler(self, addr, count):
        # Look for 'Vtx'-typed symbols first
        splitAdr = self.getTrueAdr(addr, True)
        addr = self.getTrueAdr(addr)
        sym = self.retrieve_sym_type(symbols.all_symbols_dict, splitAdr, "Vtx")

        if not sym:
            sym = self.create_symbol(
                addr=splitAdr,
                in_segment=self.in_segment,
                type="Vtx",
                reference=True,
                search_ranges=True,
            )

        index = int((addr - splitAdr) / 0x10)
        gfxd_printf(f"&{self.format_sym_name(sym)}[{index}]")
        return 1

    def getSplitAdr(self, line):
        args = ("0x"+(line.split("#")[0].strip().split("0x")[-1]))[:-1].split(",")
        if line.find("[") != -1:
            for a in range(len(args)): args[a] = args[a].strip()
        elif line.find("{") != -1:
            for a in range(len(args)): args[a] = args[a].replace("type: ", "").replace("name: ", "").strip()
        return int(args[0],16)

    def getTrueAdr(self, addr, split=False):
        if len(hex(addr)) <= 7 + 2:#SPECIFICALLY at the start
            yamlPath = os.getcwd()+"/chameleontwist.jp.yaml"
            yamler = open(yamlPath, "r", encoding="utf-8").readlines()
            index = hex((addr & 0x0F000000) >> 24).replace("0x", "0x0")
            otherhalf = addr & ~0x0F000000
            myself = hex(self.rom_start)
            i = 0
            mode = 0
            vram = 0x0
            baseAdr = 0x0
            new = 0x0
            while i < len(yamler):
                if mode == 0: #find the split the gfx came from
                    if yamler[i].lower().find(myself) != -1:
                        mode = 1
                    i += 1
                elif mode == 1: #go backwards until you find a rom start
                    if yamler[i].find("SEGMENT "+index):
                        for back in range(0,5):
                            line = yamler[i - back]
                            if line.startswith("  - start: ") and baseAdr == 0x0:
                                baseAdr = int(line.split(": ")[1].split("#")[0].strip(),16)
                                break
                    if baseAdr != 0x0:
                        new = baseAdr+otherhalf
                        if not split: break
                        mode = 2
                    i -= 1
                elif mode == 2: #try and find the asset in which you are calling for
                    #the only reason this mode exists is because vtx's have a bad habit of being called a specific distance into themselves, making this all worthless
                    if yamler[i].find("-") != -1 and yamler[i].find("0x") != -1:
                        yoink = self.getSplitAdr(yamler[i])
                        if yoink == new: break #is a valid split; wouldve been generated in symbol_addrs if you got to this point
                        elif yoink > new: #we definitely passed it. it must be in the middle of the one before
                            diff = (baseAdr+otherhalf)-self.getSplitAdr(yamler[i-1])
                            #print(hex(otherhalf), hex(diff), hex(myself))
                            otherhalf -= diff
                            break
                    i += 1
            return int(index+"000000",16)+otherhalf
        else: return addr
