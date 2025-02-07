#include "ultra64.h"
#include "macros.h"
/**************************************************************************
 *									  *
 *		 Copyright (C) 1994, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

extern f32 D_80110CA0;

typedef union
{
	struct
	{
		unsigned int hi;
		unsigned int lo;
	} word;

	double	d;
} du;

typedef union
{
	unsigned int	i;
	float		f;
} fu;

static const du	P[] =
{
{0x3ff00000,	0x00000000},
{0xbfc55554,	0xbc83656d},
{0x3f8110ed,	0x3804c2a0},
{0xbf29f6ff,	0xeea56814},
{0x3ec5dbdf,	0x0e314bfe},
};

static const du	rpi =
{0x3fd45f30,	0x6dc9c883};

static const du	pihi =
{0x400921fb,	0x50000000};

static const du	pilo =
{0x3e6110b4,	0x611a6263};

static const fu	zero = {0x00000000};

/* ====================================================================
 *
 * FunctionName		fsin
 *
 * Description		computes sine of arg
 *
 * ====================================================================
 */

float __sinf( float x ) {
	double	dx, xsq, poly;
	double	dn;
	int	n;
	double	result;
	int	ix, xpt;


	ix = *(int *)&x;
	xpt = (ix >> 22);
	xpt &= 0x1ff;

	/* xpt is exponent(x) + 1 bit of mantissa */

	if ( xpt < 0xff )	
	{
		/* |x| < 1.5 */

		dx = x;

		if ( xpt >= 0xe6 )
		{
			/* |x| >= 2^(-12) */

			/* compute sin(x) with a standard polynomial approximation */

			xsq = dx*dx;

			poly = ((P[4].d*xsq + P[3].d)*xsq + P[2].d)*xsq + P[1].d;

			result = dx + (dx*xsq)*poly;

			return ( (float)result );
		}

		return ( x );
	}

	if ( xpt < 0x136 )
	{
		/* |x| < 2^28 */

		dx = x;

		/*  reduce argument to +/- pi/2  */

		dn = dx*rpi.d;

		n = ROUND(dn);
		dn = n;

		dx = dx - dn*pihi.d;
		dx = dx - dn*pilo.d;	/* dx = x - n*pi */

		/* compute sin(dx) as before, negating result if n is odd
		*/

		xsq = dx*dx;

		poly = ((P[4].d*xsq + P[3].d)*xsq + P[2].d)*xsq + P[1].d;

		result = dx + (dx*xsq)*poly;


		if ( (n & 1) == 0 )
			return ( (float)result );

		return ( -(float)result );
	}

	if ( x != x )
	{
		/* x is a NaN; return a quiet NaN */

		return ( D_80110CA0 );
	}

	/* just give up and return 0.0 */

	return ( zero.f );
}
