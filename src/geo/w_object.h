//
//  w_object.h
//  wash
//
//  Created by Andrew Macfarlane on 12/15/16.
//  Copyright © 2016 vaporstack. All rights reserved.
//

#ifndef w_object_h
#define w_object_h

#include "../w_includes.h"

#include <r4/src/r4_platform.h>
//#include <stdbool.h>

#include "w_line.h"
#include "w_rect.h"
#include "w_transform.h"

typedef struct WObject
{
	//	todo: clean this up!
	bool normalized;
	int num_lines;
	WLine **lines;
	struct WObject *parent;
	WRect bounds;
	WTransform transform;
} WObject;


typedef struct WObjectHnd
{
	bool valid;
	WObject *src;
} WObjectHnd;


unsigned long long w_object_sum_points(WObject* obj);

WObjectHnd	w_object_hnd_create(WObject *parent);
WObjectHnd	w_object_hnd_destroy(WObjectHnd *hnd);
WObjectHnd	w_object_hnd_copy(WObjectHnd *hnd);

WObject*	w_object_create(WObject *parent);
void		w_object_destroy(WObject * obj);
void		w_object_destroy_void(void *obj);

void		w_object_add_line(WObject *, WLine *);

void		w_object_center(WObject* obj);
WObject*	w_object_copy(WObject* 	obj);
void		w_object_normalize(WObject* obj);
void		w_object_simplify(WObject*, double r);
void		w_object_douglaspeucker(WObject*, double r);

void		w_object_calc_bounds(WObject *);

/*
void		w_object_frame_next(WObject*);
void		w_object_frame_prev(WObject*);
WObject*	w_object_frame_create(WObject* obj, int pos);
void		w_object_frame_delete(WObject* obj, int pos);

*/

#endif /* w_object_h */
