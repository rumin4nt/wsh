//
//  wsh_serial.c
//  wash
//
//  Created by Andrew Macfarlane on 1/3/17.
//  Copyright © 2017 vaporstack. All rights reserved.
//

#include "wsh_serial.h"

#include <wsh/wsh_internal.h>

#include "wsh_serial_bin.h"
#include <wsh/wsh.h>

#ifdef WSH_ENABLE_SERIAL_BACKEND_JSON

#include "wsh_serial_json.h"
#endif

#include "../io/wsh_io.h"

#include <string.h>

char* w_create_version_string()
{
	char* buf = malloc(sizeof(char) * 16);
	sprintf(buf, "%d_%d_%d", WSH_VERSION_MAJOR, WSH_VERSION_MINOR,
		WSH_VERSION_PATCH);
	return buf;
}

WDocument* wsh_serial_document_unserialize(const char* path)
{
#ifdef WSH_ENABLE_SERIAL_BACKEND_JSON
	return wsh_serial_json_document_unserialize(path);
#else
	printf("Bottleneck interface not yet connected to anything! returning NULL\n");
	return NULL;
#endif
}

const char* wsh_serial_document_serialize(WDocument* doc)
{
#ifdef WSH_ENABLE_SERIAL_BACKEND_JSON
	return wsh_serial_json_document_serialize(doc);

//w_write_text_to_file(data, doc-wsh_document)
#else
	printf("Bottleneck interface not yet connected to anything! doing nothing\n");
	return NULL;
#endif
}