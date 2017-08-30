//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Game.hpp"

#include "../Core/Trigonometry.hpp"
#include "../Core/Vector2D.hpp"
#include "../Content/IReader.hpp"
#include "../Content/SdlFileReader.hpp"
#include "../Graphics/SdlWindow.hpp"
#include "../Input/SdlSignalManager.hpp"

#include "../Core/TimeInjector.hpp"
#include "../Exceptions/KittException.hpp"
#include "../constants.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;
	using namespace Input;
	using namespace Exceptions;
    
	Game::Game()
	{
        
    }
    
	Game::~Game() {
		delete signalm;
        delete time;
		delete reader;
		delete window;
		delete font;
		delete renderable;
    }

	void Game::init() {
		signalm = new SdlSignalManager();
        v1.setLocation(500,250);
        v1.setDirection(20, 40);
        v1.setRotationRate(PI/2);
		v1.setRotateDirection(true);
		time = TimeInjector::inject();
		window = new SdlWindow(TITLE, 1280, 720, false);
		renderer = window->getRenderer();
		reader = new SdlFileReader("/content", renderer, false);
		font = reader->readSurface("/fonts/courier.bmp");
		bullets = reader->readSpriteSheet("/sprites/bullets.sprite.json");
		explosion1_sheet = reader->readSpriteSheet("/sprites/explosion1.sprite.json");
		explosion1 = explosion1_sheet->getAnimation("explosion");
		rrb = bullets->getAnimation("rrb");
		rrb->reset();
		yrb = bullets->getAnimation("yrb");
		yrb->reset();
		grb = bullets->getAnimation("grb");
		grb->reset();
		crb = bullets->getAnimation("crb");
		crb->reset();
		rrbx = bullets->getAnimation("rrbx");
		rrbx->reset();

		bill_rizer = reader->readSpriteSheet("/sprites/bill_rizer_big.sprite.json");
		br_idle = bill_rizer->getAnimation("idle");
		br_walk = bill_rizer->getAnimation("walk");
		br_crouch = bill_rizer->getAnimation("crouch");
		br_crouch_fire = bill_rizer->getAnimation("crouch_fire");
		br_idle_fire = bill_rizer->getAnimation("idle_fire");
		br_walk_diag_up = bill_rizer->getAnimation("walk_diag_up");
		br_walk_diag_up_fire = bill_rizer->getAnimation("walk_diag_up_fire");
		br_idle_aim_up = bill_rizer->getAnimation("idle_aim_up");
		br_idle_aim_up_fire = bill_rizer->getAnimation("idle_aim_up_fire");
		br_idle_aim_down = bill_rizer->getAnimation("idle_aim_down");
		br_idle_aim_down_fire = bill_rizer->getAnimation("idle_aim_down_fire");
		br_idle_aim_diag_down = bill_rizer->getAnimation("idle_aim_diag_down");
		br_idle_aim_diag_down_fire = bill_rizer->getAnimation("idle_aim_diag_down_fire");

		renderable = new Renderable(Vector2D(0,0), Vector2D(192,192), Vector2D(0,0), Vector2D(96,96));
		renderable->setAnimation(br_walk);
		renderable->setTranslucent(5);
		//renderable->setAngle(PI/2);
		renderable->setRotationRate(PI/4);
		renderable->activate();
		
		camera = new Camera();
		camera->setOffset(-960,-540);
	}

	void Game::update() {

        v1.updateTransform(time->getDelta());
		Signal *signals = signalm->getSignals();
		if (signals[0].up) {
			camera->setLocation(camera->getLocation() + Vector2D(0,-200) * time->getDelta());
		}
		if (signals[0].down) {
			camera->setLocation(camera->getLocation() + Vector2D(0, 200) * time->getDelta());
		}
		if (signals[0].left) {
			camera->setLocation(camera->getLocation() + Vector2D(-200, 0) * time->getDelta());
		}
		if (signals[0].right) {
			camera->setLocation(camera->getLocation() + Vector2D(200, 0) * time->getDelta());
		}
		if (signals[0].zoomIn) {
			camera->addZoom(time->getDelta());
		}
		if (signals[0].zoomOut) {
			camera->addZoom(-time->getDelta());
		}
		if (signals[0].zoomReset) {
			camera->setZoom(1.0);
		}

		if (signals[0].jump) {
			renderable->setTranslucent(5);
		}
		onevent(signals);
		rrb->update(time->getDelta());
		yrb->update(time->getDelta());
		grb->update(time->getDelta());
		crb->update(time->getDelta());
		rrbx->update(time->getDelta());
		br_idle->update(time->getDelta());
		br_walk->update(time->getDelta());
		br_crouch->update(time->getDelta());
		br_crouch_fire->update(time->getDelta());
		br_idle_fire->update(time->getDelta());
		br_walk_diag_up->update(time->getDelta());
		br_walk_diag_up_fire->update(time->getDelta());
		br_idle_aim_up->update(time->getDelta());
		br_idle_aim_up_fire->update(time->getDelta());
		br_idle_aim_down->update(time->getDelta());
		br_idle_aim_down_fire->update(time->getDelta());
		br_idle_aim_diag_down->update(time->getDelta());
		br_idle_aim_diag_down_fire->update(time->getDelta());
		explosion1->update(time->getDelta());
		renderable->update(time->getDelta());
	}

	void Game::draw() {
		renderer->clear();

		renderer->texture(Vector2D(0,0),font);
        renderer->vector2d(v1.getLocation(), Color::White, v1.getDirection());
		
		renderer->animation(rrb, Vector2D(400, 20));
		renderer->animation(yrb, Vector2D(400, 40));
		renderer->animation(grb, Vector2D(400, 60));
		renderer->animation(crb, Vector2D(400, 80));
		renderer->animation(rrbx, Vector2D(400,120));

		renderer->animation(br_idle, Vector2D(32, 200));
		renderer->animation(br_walk, Vector2D(96, 200));
		renderer->animation(br_crouch, Vector2D(160, 200));
		renderer->animation(br_crouch_fire, Vector2D(224, 200));
		renderer->animation(br_idle_fire, Vector2D(288, 200));
		renderer->animation(br_walk_diag_up, Vector2D(352, 200));
		renderer->animation(br_walk_diag_up_fire, Vector2D(416, 200));
		renderer->animation(br_idle_aim_up, Vector2D(480, 200));
		renderer->animation(br_idle_aim_up_fire, Vector2D(544, 200));
		renderer->animation(br_idle_aim_down, Vector2D(608, 200));
		renderer->animation(br_idle_aim_down_fire, Vector2D(672, 200));
		renderer->animation(br_idle_aim_diag_down, Vector2D(736, 200));
		renderer->animation(br_idle_aim_diag_down_fire, Vector2D(800, 200));

		renderable->render(renderer, camera);
		renderer->animation(explosion1, Vector2D(300, 300));
		renderer->present();
	}

	void Game::onevent(Signal *signals) {
		if (signals[0].quit) {
			running = false;
		}
	}

	void Game::run() {
		this->init();

		running = true;
		while (running)
		{
			time->update();
			update();
			draw();
		}
	}
    
    Time *Game::getTime() {
        return time;
    }

	IReader *Game::getReader() {
		return reader;
	}
}
