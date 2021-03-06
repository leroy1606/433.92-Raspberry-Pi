/*
	Copyright (C) 2013 CurlyMo

	This file is part of the Raspberry Pi 433.92Mhz transceiver.

    Raspberry Pi 433.92Mhz transceiver is free software: you can redistribute
	it and/or modify it under the terms of the GNU General Public License as
	published by the Free Software Foundation, either version 3 of the License,
	or (at your option) any later version.

    Raspberry Pi 433.92Mhz transceiver is distributed in the hope that it will
	be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Raspberry Pi 433.92Mhz transceiver. If not, see
	<http://www.gnu.org/licenses/>
*/

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "options.h"

#define RAW			0
#define SWITCH		1
#define DIMMER		2
#define WEATHER		3

typedef struct {
	char id[25];
	char desc[50];
	int type;
	int header;
	int pulse;
	int footer;
	float multiplier[2];
	int rawLength;
	int binaryLength;
	int repeats;
	struct option *options;
	char *message;

	int bit;
	int recording;
	int raw[255];
	int code[255];
	int pCode[255];
	int binary[255];

	void (*parseRaw)();
	void (*parseCode)();
	void (*parseBinary)();
	void (*createCode)(struct options_t *options);
	void (*printHelp)();
} protocol_t;

typedef struct {
	int nr;
	protocol_t *listeners[255];
} protocols_t;

protocols_t protocols;

void protocol_register(protocol_t *proto);
void protocol_unregister(protocol_t *proto);

#endif
