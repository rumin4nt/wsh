//
//  wsh_line.h
//  wash
//
//  Created by Andrew Macfarlane on 12/15/16.
//  Copyright © 2016 vaporstack. All rights reserved.
//

#ifndef wsh_line_h
#define wsh_line_h

#include <stdbool.h>

#include "../wsh_includes.h"

#include "wsh_rect.h"
#include "wsh_transform.h"

//#include "../decor/w_brush.h"

//	todo: get color out of here, this is a geometry type!
#include "../core/wsh_color.h"

#include "wsh_point.h"

//	TODO:  write feature parity code for fill, stroke, tess, and brush.  This is a core data type
//	and should not know anything about what color it is.  that should be stored separately.

typedef struct WLine
{
	bool closed;
	//bool		   has_stroke;
	//bool		   has_fill;
	int		   z;
	unsigned long      id;
	unsigned long long num;
	unsigned long long reserved;
	WPoint*		   data;
	//	swimming upstream here and adding a temporary brush width parameter
	//	to give us local strokes quickly
	//	since the big tool refactor is still some weeks away
	double width;

	//void*		   tess;
	//	todo:
	//	refactor to have the brush owned elsewhere, it is not a core
	// datatype
	//struct WBrush* brush;
	//	todo: change stroke and fill to pointers to be able to remove the has_stroke  and has_fill params?
	//	no,  remove stroke and fill, this is now a pure storage class.
	//	i changed my mind again, refactoring these to be 2 vars instead of 4 will make removing them
	//	slightly easier in the future
	WColor16*     fill;
	WColor16*     stroke;
	WRect	 bounds;
	unsigned long seed;
	//WTransform transform;
} WLine;

typedef struct WLineHnd
{
	WLine* src;

} WLineHnd;

typedef struct
{
	const WLine* src;

} WLineHndConst;

typedef unsigned long long ull;

WLineHnd*      wsh_line_hnd_create(void);
WLineHnd*      wsh_line_hnd_create_with_data(void);
WLineHndConst  wsh_line_hnd_create_with_addr(const WLine* addr);
WLineHndConst* wsh_line_hnd_ptr_create_with_addr(const WLine* addr);

WLineHnd* wsh_line_hnd_copy(WLineHnd*);

//	todo: ask people what the convention is here
void wsh_line_copy_attribs(WLine* to, WLine* from);
void wsh_line_hnd_destroy(WLineHnd*);
void wsh_line_hnd_add_point(WLineHnd*, WPoint);
void wsh_line_hnd_add_point2f(WLineHnd* hnd, double x, double y);
void wsh_line_calc_bounds(WLine* src);
void wsh_line_translate(WLine* src, double x, double y);

//	going forward, all rotation operations should be in radians unless otherwise specified
//	by the _degree suffix
void wsh_line_rotate(WLine* line, double cx, double cy, double r);
void wsh_line_rotate_d(WLine* line, double cx, double cy, double d);

void wsh_line_scale(WLine* src, double x, double y);

void    wsh_line_find_mins(WLine* src, double* x, double* y);
void    wsh_line_find_maxs(WLine* src, double* x, double* y);
WLine*  wsh_line_create(void);
WLine*  wsh_line_create_with_reserved(unsigned int num);
WLine*  wsh_line_reverse(WLine*);
WLine*  wsh_line_copy(const WLine*);
WLine*  wsh_line_copy_percentage(const WLine*, double v);
void    wsh_line_concat(WLine* dst, WLine* src);
void    wsh_line_concat_range(WLine* dst, WLine* src, long start, long end);
WPoint* wsh_line_pop_back(WLine* line);
void    wsh_line_destroy(WLine*);
void    wsh_line_add_point(WLine* line, WPoint p);
void    wsh_line_add_point2f(WLine* line, double x, double y);
void    wsh_line_normalize_time(WLine* l);

WLine* wsh_line_normalize(WLine*, double* dx, double* dy);
WLine* wsh_line_normalize_square(WLine*, double* dx, double* dy);
void   wsh_line_normalize_inplace(WLine*, double* dx, double* dy);
void   wsh_line_normalize_square_inplace(WLine*, double* dx, double* dy);
WLine* wsh_line_segment(WLine* line, double d);
double wsh_line_sum(WLine* line);

#endif /* wsh_line_h */
