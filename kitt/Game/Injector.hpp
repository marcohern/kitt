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

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;

    class Injector {
    private:
        static Injector *instance;
        Trigonometry *trigonometry;
        Time *time;
		Window *window;
		Renderer *renderer;

		IReader *reader;
        
        Injector();
        
    public:
        ~Injector();
        static Injector *get();
        
        Trigonometry *getTrigonometry();
        Time *getTime();
		
		IReader *getReader();

		Vector2D createVector2D();
		Vector2D createVector2D(double x, double y);
		Vector2D createVector2D(const Vector2D &v);
    };
}
#endif /* Injector_hpp */
