//
//  w_rect.c
//  wash
//
//  Created by Andrew Macfarlane on 1/2/17.
//  Copyright © 2017 vaporstack. All rights reserved.
//

#include "w_rect.h"

int w_rect_within_bounds(WRect* bounds, double x, double y)
{
	return ( x > bounds->pos.x && y > bounds->pos.y && x < bounds->pos.x + bounds->size.x && y < bounds->pos.y + bounds->size.y);
	
}
