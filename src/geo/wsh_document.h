//
//  wsh_document.h
//  wash
//
//  Created by Andrew Macfarlane on 1/18/17.
//  Copyright © 2017 vaporstack. All rights reserved.
//

#ifndef wsh_document_h
#define wsh_document_h

#include "wsh_object.h"
#include "wsh_sequence.h"

enum
{
	WASH_DOCUMENT_STATE_NEW,
	//WASH_DOCUMENT_STATE_NEVERSAVED,
	WASH_DOCUMENT_STATE_CLEAN,
	WASH_DOCUMENT_STATE_DIRTY,
	WASH_DOCUMENT_STATE_UNKNOWN
};

typedef struct EventList
{
	const char**       descriptions;
	double**	   times;
	unsigned long long num;
} EventList;

typedef struct WDocumentMeta
{
	//	session
	EventList* events;

	//	plugins
	//	this is probably going to just be json text for a while
	void* plugins;

	//	tools
	char** tools;
	int    tool_num;

	//	canvas
	int canvas_width;
	int canvas_height;
	WColor16 background_color;
	int orientation;
	double dpi;

	//	info
	int	 version;
	const char* version_string;
	const char* path;
	const char* name;
	const char* ref;
	double      fps;
	const char* uuid;
	const char* fps_repr;

	//	hints
	unsigned int playback_mode;
	bool animated;
	const char* theme;

} WDocumentMeta;

typedef struct WDocument
{
	int	    state;
	WDocumentMeta  meta;
	WSequenceHnd   sequence;
	WSequenceHnd** layers;
	int	    layer_num;
} WDocument;

typedef struct WDocumentHnd
{
	WDocument* src;
} WDocumentHnd;

WDocument* wsh_document_create(void);
void       wsh_document_destroy(WDocument*);

WDocument* wsh_document_copy(WDocument*);
void       wsh_document_meta_clear(WDocumentMeta* meta);

#endif /* wsh_document_h */
