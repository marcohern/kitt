#pragma once

#include "../Testing/Test.hpp"
#include "../Graphics/Window.hpp"
#include "../Graphics/Renderer.hpp"

namespace Tests {
	using namespace Testing;
	using namespace Graphics;

	class SdlFileReaderTest;
	typedef void (SdlFileReaderTest::*SdlFileReaderTestMethod)();

	class SdlFileReaderTest : public Test {
		Window *window;
		Renderer *render;
	public:
		void setup();
		void teardown();
		void runtest(string name, SdlFileReaderTestMethod method);

		void readSpriteSheet_Test();

		void run();
	};
}