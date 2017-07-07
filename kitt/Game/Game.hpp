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
#include "../Core/Trigonometry.hpp"
#include "../Core/Time.hpp"
#include "../Core/Vector2D.hpp"
#include "../Graphics/Window.hpp"
#include "../Content/IReader.hpp"
#include "../Input/SignalManager.hpp"
#include "../Input/Signal.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;
	using namespace Input;

    class Game {
    private:
		bool running;
        Time *time;
		Window *window;
		Renderer *renderer;
		SignalManager *signalm;

		IReader *reader;
		Texture *font;
		Vector2D *v1;
        
    public:
		Game();
        ~Game();

		void init();
		void update();
		void draw();
		void onevent(Signal *signals);
		void run();

        Time *getTime();		
		IReader *getReader();
    };
}
#endif /* Injector_hpp */
