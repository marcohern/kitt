
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
		render->sprite(Vector2D(100, 100), sheet->getSprite("rrb01"));
		assert.isTrue(true);
	}

	void SdlFileReaderTest::run() {
		runtest("readSpriteSheet_Test", &SdlFileReaderTest::readSpriteSheet_Test);
	}
}