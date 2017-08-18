// ============================================================================
// [Include Section]
// ============================================================================
#include "SDL.h"
#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include "./Tests/KittTestSuite.hpp"
#include "./Game/Game.hpp"
#include "./Core/Trigonometry.hpp"
#include "./Core/Path.hpp"
#include "./Game/Game.hpp"
#include <physfs.h>
#include "constants.hpp"
#include "Exceptions/KittException.hpp"
#include "Core/TrigonometryInjector.hpp"
#include "Core/TimeInjector.hpp"

// ============================================================================
// [SdlApplication]
// ============================================================================
#define APPTITLE "SDL Template Program"
// SdlApplication is nothing more than thin wrapper to SDL library. You need
// just to instantiate it and call run() to enter the SDL event loop.

using namespace std;



// ============================================================================
// [Entry-Point]
// ============================================================================

int main(int argc, char* argv[])
{
	
    Core::Path::get()->setRootFromArgs(argv[0]);
	Core::TrigonometryInjector::init(TRIGO_TYPE);
	Core::TimeInjector::init(0);
    PHYSFS_init(argv[0]);
    
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        throw Exceptions::KittException("Unable to initialize SDL.");
    }
	/*
	PHYSFS_mount("C:\\Src\\marcohern.com\\kitt\\content.zip", "/", 0);

	PHYSFS_File *file = PHYSFS_openRead("/fonts/courier.bmp");
	int size = PHYSFS_fileLength(file);
	
	PHYSFS_close(file);
	PHYSFS_deinit();

	Game::Game game;
	game.run();
    return 0;
	 
*/	
	cout<<"Testing"<<endl;
	Tests::KittTestSuite testSuite;
	testSuite.run();
	
	return 0;
}
