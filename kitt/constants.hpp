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

#define PI  3.141592653589793
#define TAU 6.283185307179586

#define TRIGO_TABLE_SIZE 200000

#define TRIGO_TYPE_REALTIME 0x01
#define TRIGO_TYPE_MEMOIZED 0x02

#define TRIGO_TYPE TRIGO_TYPE_MEMOIZED

#define WDS '\\'
#define UDS '/'

#ifdef _WIN32
	#define DS WDS
#else 
	#define DS UDS
#endif

#endif /* constants_hpp */
