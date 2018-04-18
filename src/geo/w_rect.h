//
//  w_rect.h
//  wash
//
//  Created by Andrew Macfarlane on 1/2/17.
//  Copyright © 2017 vaporstack. All rights reserved.
//

#ifndef w_rect_h
#define w_rect_h

#include "w_point.h"

//	todo : kill this?
typedef struct
{
	WPoint pos;
	WPoint size;
} WRect;

void w_rect_reset(WRect* bounds);
int w_rect_within_bounds(WRect* bounds, double x, double y);

#endif /* w_rect_h */
