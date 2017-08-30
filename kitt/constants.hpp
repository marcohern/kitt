//
//  constants.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef constants_hpp
#define constants_hpp

#include <stdio.h>

#define TITLE "kitt"

#define HALFPI		1.570796326794896
#define PI			3.141592653589793
#define THREEHALFPI	4.712388980384689
#define TAU			6.283185307179586

#define TRIGO_TABLE_SIZE 50000
#define TRIGO_QUAD_SIZE  50000
#define TRIGO_QUAD_TOTAL 4*TRIGO_QUAD_SIZE

#define	TRIGO_TYPE_NONE		0x00
#define	TRIGO_TYPE_REALTIME	0x01
#define	TRIGO_TYPE_MEMOIZED	0x02
#define	TRIGO_TYPE_QUADMEM	0x03

#define TIME_TYPE_NONE 0x00
#define TIME_TYPE_SDL  0x01

#define READER_TYPE_NONE	0x00
#define READER_TYPE_DIR		0x01
#define READER_TYPE_ZIP		0x02
#define READER_TYPE_SDLDIR	0x03
#define READER_TYPE_SDLZIP	0x04

#define WDS '\\'
#define UDS '/'

#define ANIM_TRANSLUCENT_INTERVAL 0.05

#define BLEND_ADD_SHOT 3

#ifdef _WIN32
	#define DS WDS
#else 
	#define DS UDS
#endif

#define	TRIGO_TYPE	TRIGO_TYPE_MEMOIZED
#define	TIME_TYPE	TIME_TYPE_SDL
#define READER_TYPE	READER_TYPE_SDLDIR
#endif /* constants_hpp */
