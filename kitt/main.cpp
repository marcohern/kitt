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


struct SdlApplication
{
	SdlApplication();
	~SdlApplication();
	
	// Application state (just convenience instead of 0, 1, ...).
	enum APP_STATE
	{
		APP_OK = 0,
		APP_FAILED = 1
	};
	
	// Initialize application, called by run(), don't call manually.
	int init(int width, int height);
	
	// Destroy application, called by destructor, don't call manually.
	void destroy();
	
	// Run application, called by your code.
	int run(int width, int height);
	
	// Called to process SDL event.
	void onEvent(SDL_Event* ev);
	
	// Called to render content into buffer.
	void Render();
	
	// Whether the application is in event loop.
	bool _running;
	SDL_Window *win;
	SDL_Renderer *renderer;
    
    SDL_Surface *courier;
    SDL_Texture *couriertx;
    SDL_Rect letter;
    SDL_Rect dst;
	SDL_Texture *screen;
    void RenderText(string text, int x, int y);
};

SdlApplication::SdlApplication() :
_running(false)
{
}

SdlApplication::~SdlApplication()
{
	destroy();
}

int SdlApplication::init(int width, int height)
{
	// Initialize the SDL library.
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
		return APP_FAILED;
	}	
	win = SDL_CreateWindow(APPTITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
	screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1920, 1080);

    string path = Core::Path::get()->getFullPath("/content/fonts/myriad.png");
    this->courier = IMG_Load(path.c_str());
	//this->courier = IMG_Load("C:\\Src\\marcohern.com\\kitt\\content\\fonts\\courier.bmp");

    this->couriertx = SDL_CreateTextureFromSurface(renderer, this->courier);
    
    this->letter.x=0;
    this->letter.y=0;
    this->letter.w=64;
    this->letter.h=64;

	// Success.
	return APP_OK;
}

void SdlApplication::RenderText(string text, int x, int y) {
    this->dst.w = this->letter.w;
    this->dst.h = this->letter.h;
    this->dst.x = x;
    this->dst.y = y;
    
    for (int i=0;i<text.size();i++) {
        char c = text[i];
        int cv = (int)c;
        int sx = cv%16;
        int sy = cv/16;

		double ddx = (double)rand() / RAND_MAX;
		int tx = this->dst.x;
		int dx = ddx*8;
        
        this->letter.x = sx*64;
        this->letter.y = sy*64;
		this->dst.x += dx;
        SDL_RenderCopy(renderer, this->couriertx, &this->letter, &this->dst);
        this->dst.x= tx + 32;
    }
}

void SdlApplication::destroy()
{
	if (win)
	{
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}
}

int SdlApplication::run(int width, int height)
{
	// Initialize application.
	int state = init(width, height);
	if (state != APP_OK) return state;
	
	// Enter to the SDL event loop.
	SDL_Event ev;
	_running = true;
	while (_running) {
		if (SDL_PollEvent(&ev) != 0) {
			onEvent(&ev);
		}
		Render();

		if (_running == false)
		{
			break;
		}
	}
	
	return APP_OK;
}

void SdlApplication::onEvent(SDL_Event* ev)
{
	switch (ev->type)
	{
		case SDL_QUIT:
			_running = false;
			break;
			
		case SDL_KEYDOWN:
		{
			if (ev->key.keysym.sym == SDLK_ESCAPE)
			{
				_running = false;
			}
		}
	}
}

void SdlApplication::Render()
{
	SDL_Rect r;
	int w,h;
	SDL_GetWindowSize(win, &w, &h);
	
	r.w = 200;
	r.h = 200;
	r.x = w/2-(r.w/2);
	r.y = h/2-(r.h/2);
	
	
	//
	

	SDL_SetRenderTarget(renderer, screen);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(renderer);

    RenderText("Hello. I Love you, Wont you Tell me your name?",10,10);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0x00, 0xff);
	SDL_RenderFillRect(renderer, &r);

	
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopyEx(renderer, screen, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
	SDL_RenderPresent(renderer);
}


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
	/*
	SdlApplication app;
	return app.run(1280, 720);
	return 0;
	*/
	
}
