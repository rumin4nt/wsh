//
//  demo.c
//  wash-demo
//
//  Created by vs on 3/20/18.
//  Copyright © 2018 ruminant. All rights reserved.
//

#include "procedural_brush.h"

#define DEMO_NAME "procedural_brush"
#define DEMO_NICENAME "Procedural Brush"
static void key(int action, int key)
{
	
}

static void init(void)
{
	printf("%s init!\n", DEMO_NICENAME);
	
}

static void deinit(void)
{
	printf("%s deinit!\n", DEMO_NICENAME);
}


static void update(void)
{
	
}


static void draw(void)
{
	
}

WashDemo procedural_brush =
{
	DEMO_NICENAME,
	1.0/60.0,
	init,
	deinit,
	update,
	draw,
	key
};
