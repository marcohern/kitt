#pragma once

#ifdef _WIN32
	//Windows
	#include <SDL.h>
	#include <SDL_image.h>

	#ifdef _WIN64
		//Windows 64 bit only
	#else
		//Windows 32 bit only
	#endif

#else //MAX OS
	#include <SDL2/SDL.h>
	#include <SDL2_image/SDL_image.h>
#endif