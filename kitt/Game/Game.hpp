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
#include "../Behaviors/Transformable.hpp"
#include "../Graphics/SpriteSheet.hpp"
#include "../Graphics/Animation.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;
	using namespace Input;
	using namespace Behaviors;

    class Game {
    private:
		bool running;
        Time *time;
		Window *window;
		Renderer *renderer;
		SignalManager *signalm;
		SpriteSheet *bullets, *bill_rizer;
		Animation *rrb, *yrb, *grb, *crb, *rrbx;
		Animation *br_idle, *br_walk, *br_crouch, *br_crouch_fire, *br_idle_fire,
			*br_walk_diag_up, *br_walk_diag_up_fire, *br_idle_aim_up, *br_idle_aim_up_fire,
			*br_idle_aim_down, *br_idle_aim_down_fire, *br_idle_aim_diag_down, *br_idle_aim_diag_down_fire;
		
		

		IReader *reader;
		Texture *font;
		Transformable v1;
        
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
