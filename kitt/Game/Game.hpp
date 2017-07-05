//
//  Injector.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Injector_hpp
#define Injector_hpp

#include <stdio.h>
#include "../SDL.h"
#include "../Core/Trigonometry.hpp"
#include "../Core/Time.hpp"
#include "../Core/Vector2D.hpp"
#include "../Graphics/Window.hpp"
#include "../Content/IReader.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;

    class Game {
    private:
		bool running;
        Trigonometry *trigonometry;
        Time *time;
		Window *window;
		Renderer *renderer;

		IReader *reader;
        
    public:
		Game();
        ~Game();

		void init();
		void update();
		void draw();
		void onevent(SDL_Event *ev);
		void run();

        Trigonometry *getTrigonometry();
        Time *getTime();		
		IReader *getReader();
    };
}
#endif /* Injector_hpp */
