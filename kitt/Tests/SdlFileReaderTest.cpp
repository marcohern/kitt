
#include "SdlFileReaderTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Content/SdlFileReader.hpp"
#include "../Graphics/SdlWindow.hpp"

namespace Tests {
	using namespace Testing;
	using namespace Core;
	using namespace Content;
	using namespace Graphics;

	void SdlFileReaderTest::setup() {
		name = "SdlFileReader";
		window = new SdlWindow("SdlFileReaderTest", 1280, 720, false);
		render = window->getRenderer();
		render->clear();
	}

	void SdlFileReaderTest::teardown() {
		delete window;
	}

	void SdlFileReaderTest::runtest(string name, SdlFileReaderTestMethod method) {
		TestRunner<SdlFileReaderTest, SdlFileReaderTestMethod>(name, this, method).run();
	}

	void SdlFileReaderTest::readSpriteSheet_Test() {
		SdlFileReader fileReader("/content", render, false);
		SpriteSheet *sheet = fileReader.readSpriteSheet("/sprites/bullets.sprite.json");
		render->sprite(Vector2D(10, 10), sheet->getSprite("rrb01"));
		render->sprite(Vector2D(10, 30), sheet->getSprite("rrb02"));
		render->sprite(Vector2D(10, 50), sheet->getSprite("rrb03"));
		render->sprite(Vector2D(10, 70), sheet->getSprite("rrb04"));

		render->sprite(Vector2D(30, 10), sheet->getSprite("grb01"));
		render->sprite(Vector2D(30, 30), sheet->getSprite("grb02"));
		render->sprite(Vector2D(30, 50), sheet->getSprite("grb03"));
		render->sprite(Vector2D(30, 70), sheet->getSprite("grb04"));

		render->sprite(Vector2D(50, 10), sheet->getSprite("yrb01"));
		render->sprite(Vector2D(50, 30), sheet->getSprite("yrb02"));
		render->sprite(Vector2D(50, 50), sheet->getSprite("yrb03"));
		render->sprite(Vector2D(50, 70), sheet->getSprite("yrb04"));

		render->sprite(Vector2D(70, 10), sheet->getSprite("crb01"));
		render->sprite(Vector2D(70, 30), sheet->getSprite("crb02"));
		render->sprite(Vector2D(70, 50), sheet->getSprite("crb03"));
		render->sprite(Vector2D(70, 70), sheet->getSprite("crb04"));

		render->sprite(Vector2D(90, 10), sheet->getSprite("rcsm"));
		render->sprite(Vector2D(90, 30), sheet->getSprite("rcmd"));
		render->sprite(Vector2D(90, 50), sheet->getSprite("rclg"));

		render->sprite(Vector2D(110, 10), sheet->getSprite("gcsm"));
		render->sprite(Vector2D(110, 30), sheet->getSprite("gcmd"));
		render->sprite(Vector2D(110, 50), sheet->getSprite("gclg"));

		render->sprite(Vector2D(130, 10), sheet->getSprite("ycsm"));
		render->sprite(Vector2D(130, 30), sheet->getSprite("ycmd"));
		render->sprite(Vector2D(130, 50), sheet->getSprite("yclg"));

		render->sprite(Vector2D(150, 10), sheet->getSprite("ccsm"));
		render->sprite(Vector2D(150, 30), sheet->getSprite("ccmd"));
		render->sprite(Vector2D(150, 50), sheet->getSprite("cclg"));

		render->sprite(Vector2D(170, 10), sheet->getSprite("rssm"));
		render->sprite(Vector2D(170, 30), sheet->getSprite("rsmd"));
		render->sprite(Vector2D(170, 50), sheet->getSprite("rslg"));

		render->sprite(Vector2D(190, 10), sheet->getSprite("gssm"));
		render->sprite(Vector2D(190, 30), sheet->getSprite("gsmd"));
		render->sprite(Vector2D(190, 50), sheet->getSprite("gslg"));

		render->sprite(Vector2D(210, 10), sheet->getSprite("yssm"));
		render->sprite(Vector2D(210, 30), sheet->getSprite("ysmd"));
		render->sprite(Vector2D(210, 50), sheet->getSprite("yslg"));

		render->sprite(Vector2D(230, 10), sheet->getSprite("bssm"));
		render->sprite(Vector2D(230, 30), sheet->getSprite("bsmd"));
		render->sprite(Vector2D(230, 50), sheet->getSprite("bslg"));

		render->sprite(Vector2D(250, 10), sheet->getSprite("rshtn"));
		render->sprite(Vector2D(250, 30), sheet->getSprite("rshsm"));
		render->sprite(Vector2D(250, 50), sheet->getSprite("rshmd"));
		render->sprite(Vector2D(250, 70), sheet->getSprite("rshlg"));

		render->sprite(Vector2D(270, 10), sheet->getSprite("gshtn"));
		render->sprite(Vector2D(270, 30), sheet->getSprite("gshsm"));
		render->sprite(Vector2D(270, 50), sheet->getSprite("gshmd"));
		render->sprite(Vector2D(270, 70), sheet->getSprite("gshlg"));

		render->sprite(Vector2D(290, 10), sheet->getSprite("yshtn"));
		render->sprite(Vector2D(290, 30), sheet->getSprite("yshsm"));
		render->sprite(Vector2D(290, 50), sheet->getSprite("yshmd"));
		render->sprite(Vector2D(290, 70), sheet->getSprite("yshlg"));

		render->sprite(Vector2D(310, 10), sheet->getSprite("cshtn"));
		render->sprite(Vector2D(310, 30), sheet->getSprite("cshsm"));
		render->sprite(Vector2D(310, 50), sheet->getSprite("cshmd"));
		render->sprite(Vector2D(310, 70), sheet->getSprite("cshlg"));
		render->present();
		assert.isTrue(true);
	}

	void SdlFileReaderTest::run() {
		runtest("readSpriteSheet_Test", &SdlFileReaderTest::readSpriteSheet_Test);
	}
}