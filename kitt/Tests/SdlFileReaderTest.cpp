
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

		render->sprite(Vector2D(330, 10), sheet->getSprite("rmntn"));
		render->sprite(Vector2D(330, 30), sheet->getSprite("rmnsm"));
		render->sprite(Vector2D(330, 50), sheet->getSprite("rmnmd"));
		render->sprite(Vector2D(330, 70), sheet->getSprite("rmnlg"));

		render->sprite(Vector2D(350, 10), sheet->getSprite("gmntn"));
		render->sprite(Vector2D(350, 30), sheet->getSprite("gmnsm"));
		render->sprite(Vector2D(350, 50), sheet->getSprite("gmnmd"));
		render->sprite(Vector2D(350, 70), sheet->getSprite("gmnlg"));

		render->sprite(Vector2D(370, 10), sheet->getSprite("ymntn"));
		render->sprite(Vector2D(370, 30), sheet->getSprite("ymnsm"));
		render->sprite(Vector2D(370, 50), sheet->getSprite("ymnmd"));
        render->sprite(Vector2D(370, 70), sheet->getSprite("ymnlg"));
        
        render->sprite(Vector2D(390, 10), sheet->getSprite("cmntn"));
        render->sprite(Vector2D(390, 30), sheet->getSprite("cmnsm"));
        render->sprite(Vector2D(390, 50), sheet->getSprite("cmnmd"));
        render->sprite(Vector2D(390, 70), sheet->getSprite("cmnlg"));
        
        render->sprite(Vector2D(410, 10), sheet->getSprite("blb"));
        render->sprite(Vector2D(410, 40), sheet->getSprite("rlb"));
        render->sprite(Vector2D(410, 70), sheet->getSprite("ylb"));
        render->sprite(Vector2D(410, 100), sheet->getSprite("glb"));
        
        render->sprite(Vector2D(430, 10), sheet->getSprite("bmb"));
        render->sprite(Vector2D(430, 40), sheet->getSprite("rmb"));
        render->sprite(Vector2D(430, 70), sheet->getSprite("ymb"));
        render->sprite(Vector2D(430, 100), sheet->getSprite("gmb"));
        
        render->sprite(Vector2D(450,  10), sheet->getSprite("gball01"));
        render->sprite(Vector2D(450,  30), sheet->getSprite("gball02"));
        render->sprite(Vector2D(450,  50), sheet->getSprite("gball03"));
        render->sprite(Vector2D(450,  70), sheet->getSprite("gball04"));
        render->sprite(Vector2D(450,  90), sheet->getSprite("gball05"));
        render->sprite(Vector2D(450, 110), sheet->getSprite("gball06"));
        render->sprite(Vector2D(450, 130), sheet->getSprite("gball07"));
        render->sprite(Vector2D(450, 150), sheet->getSprite("gball08"));
        render->sprite(Vector2D(450, 170), sheet->getSprite("gball09"));
        render->sprite(Vector2D(450, 190), sheet->getSprite("gball10"));
        render->sprite(Vector2D(450, 210), sheet->getSprite("gball11"));
        
        render->sprite(Vector2D(470,  10), sheet->getSprite("yball01"));
        render->sprite(Vector2D(470,  30), sheet->getSprite("yball02"));
        render->sprite(Vector2D(470,  50), sheet->getSprite("yball03"));
        render->sprite(Vector2D(470,  70), sheet->getSprite("yball04"));
        render->sprite(Vector2D(470,  90), sheet->getSprite("yball05"));
        render->sprite(Vector2D(470, 110), sheet->getSprite("yball06"));
        render->sprite(Vector2D(470, 130), sheet->getSprite("yball07"));
        render->sprite(Vector2D(470, 150), sheet->getSprite("yball08"));
        render->sprite(Vector2D(470, 170), sheet->getSprite("yball09"));
        render->sprite(Vector2D(470, 190), sheet->getSprite("yball10"));
        render->sprite(Vector2D(470, 210), sheet->getSprite("yball11"));
        
        render->sprite(Vector2D(490,  10), sheet->getSprite("rball01"));
        render->sprite(Vector2D(490,  30), sheet->getSprite("rball02"));
        render->sprite(Vector2D(490,  50), sheet->getSprite("rball03"));
        render->sprite(Vector2D(490,  70), sheet->getSprite("rball04"));
        render->sprite(Vector2D(490,  90), sheet->getSprite("rball05"));
        render->sprite(Vector2D(490, 110), sheet->getSprite("rball06"));
        render->sprite(Vector2D(490, 130), sheet->getSprite("rball07"));
        render->sprite(Vector2D(490, 150), sheet->getSprite("rball08"));
        render->sprite(Vector2D(490, 170), sheet->getSprite("rball09"));
        render->sprite(Vector2D(490, 190), sheet->getSprite("rball10"));
        render->sprite(Vector2D(490, 210), sheet->getSprite("rball11"));
        
        render->sprite(Vector2D(510,  10), sheet->getSprite("cball01"));
        render->sprite(Vector2D(510,  30), sheet->getSprite("cball02"));
        render->sprite(Vector2D(510,  50), sheet->getSprite("cball03"));
        render->sprite(Vector2D(510,  70), sheet->getSprite("cball04"));
        render->sprite(Vector2D(510,  90), sheet->getSprite("cball05"));
        render->sprite(Vector2D(510, 110), sheet->getSprite("cball06"));
        render->sprite(Vector2D(510, 130), sheet->getSprite("cball07"));
        render->sprite(Vector2D(510, 150), sheet->getSprite("cball08"));
        render->sprite(Vector2D(510, 170), sheet->getSprite("cball09"));
        render->sprite(Vector2D(510, 190), sheet->getSprite("cball10"));
        render->sprite(Vector2D(510, 210), sheet->getSprite("cball11"));
        
        render->sprite(Vector2D(530,  10), sheet->getSprite("sphere11"));
        render->sprite(Vector2D(530,  30), sheet->getSprite("sphere12"));
        render->sprite(Vector2D(530,  50), sheet->getSprite("sphere13"));
        render->sprite(Vector2D(530,  70), sheet->getSprite("sphere14"));
        render->sprite(Vector2D(530,  90), sheet->getSprite("sphere15"));
        render->sprite(Vector2D(530, 110), sheet->getSprite("sphere16"));
        render->sprite(Vector2D(530, 130), sheet->getSprite("sphere17"));
        
        render->sprite(Vector2D(550,  10), sheet->getSprite("sphere21"));
        render->sprite(Vector2D(550,  30), sheet->getSprite("sphere22"));
        render->sprite(Vector2D(550,  50), sheet->getSprite("sphere23"));
        render->sprite(Vector2D(550,  70), sheet->getSprite("sphere24"));
        render->sprite(Vector2D(550,  90), sheet->getSprite("sphere25"));
        render->sprite(Vector2D(550, 110), sheet->getSprite("sphere26"));
        render->sprite(Vector2D(550, 130), sheet->getSprite("sphere27"));
        
        render->sprite(Vector2D(570,  10), sheet->getSprite("sphere31"));
        render->sprite(Vector2D(570,  30), sheet->getSprite("sphere32"));
        render->sprite(Vector2D(570,  50), sheet->getSprite("sphere33"));
        render->sprite(Vector2D(570,  70), sheet->getSprite("sphere34"));
        render->sprite(Vector2D(570,  90), sheet->getSprite("sphere35"));
        render->sprite(Vector2D(570, 110), sheet->getSprite("sphere36"));
        render->sprite(Vector2D(570, 130), sheet->getSprite("sphere37"));
        
        render->sprite(Vector2D(590,  10), sheet->getSprite("sphere41"));
        render->sprite(Vector2D(590,  30), sheet->getSprite("sphere42"));
        render->sprite(Vector2D(590,  50), sheet->getSprite("sphere43"));
        render->sprite(Vector2D(590,  70), sheet->getSprite("sphere44"));
        render->sprite(Vector2D(590,  90), sheet->getSprite("sphere45"));
        render->sprite(Vector2D(590, 110), sheet->getSprite("sphere46"));
        render->sprite(Vector2D(590, 130), sheet->getSprite("sphere47"));
        
        render->sprite(Vector2D(610,  10), sheet->getSprite("spark11"));
        render->sprite(Vector2D(610,  30), sheet->getSprite("spark12"));
        render->sprite(Vector2D(610,  50), sheet->getSprite("spark13"));
        render->sprite(Vector2D(610,  70), sheet->getSprite("spark14"));
        render->sprite(Vector2D(610,  90), sheet->getSprite("spark15"));
        render->sprite(Vector2D(610, 110), sheet->getSprite("spark16"));
        
        render->sprite(Vector2D(630,  10), sheet->getSprite("spark21"));
        render->sprite(Vector2D(630,  30), sheet->getSprite("spark22"));
        render->sprite(Vector2D(630,  50), sheet->getSprite("spark23"));
        render->sprite(Vector2D(630,  70), sheet->getSprite("spark24"));
        render->sprite(Vector2D(630,  90), sheet->getSprite("spark25"));
        render->sprite(Vector2D(630, 110), sheet->getSprite("spark26"));
        
        render->sprite(Vector2D(650,  10), sheet->getSprite("spark31"));
        render->sprite(Vector2D(650,  30), sheet->getSprite("spark32"));
        render->sprite(Vector2D(650,  50), sheet->getSprite("spark33"));
        render->sprite(Vector2D(650,  70), sheet->getSprite("spark34"));
        render->sprite(Vector2D(650,  90), sheet->getSprite("spark35"));
        render->sprite(Vector2D(650, 110), sheet->getSprite("spark36"));
        
        render->sprite(Vector2D(670,  10), sheet->getSprite("spark41"));
        render->sprite(Vector2D(670,  30), sheet->getSprite("spark42"));
        render->sprite(Vector2D(670,  50), sheet->getSprite("spark43"));
        render->sprite(Vector2D(670,  70), sheet->getSprite("spark44"));
        render->sprite(Vector2D(670,  90), sheet->getSprite("spark45"));
        render->sprite(Vector2D(670, 110), sheet->getSprite("spark46"));
        
        render->sprite(Vector2D(690,  10), sheet->getSprite("ywlaser1"));
        render->sprite(Vector2D(690,  30), sheet->getSprite("ywlaser2"));
        render->sprite(Vector2D(690,  50), sheet->getSprite("ywlaser3"));
        render->sprite(Vector2D(690,  70), sheet->getSprite("ywlaser4"));
        
        render->sprite(Vector2D(730,  10), sheet->getSprite("gwlaser1"));
        render->sprite(Vector2D(730,  30), sheet->getSprite("gwlaser2"));
        render->sprite(Vector2D(730,  50), sheet->getSprite("gwlaser3"));
        render->sprite(Vector2D(730,  70), sheet->getSprite("gwlaser4"));
        
        render->sprite(Vector2D(770,  10), sheet->getSprite("bwlaser1"));
        render->sprite(Vector2D(770,  30), sheet->getSprite("bwlaser2"));
        render->sprite(Vector2D(770,  50), sheet->getSprite("bwlaser3"));
        render->sprite(Vector2D(770,  70), sheet->getSprite("bwlaser4"));
        
        render->sprite(Vector2D(810,  10), sheet->getSprite("pwlaser1"));
        render->sprite(Vector2D(810,  30), sheet->getSprite("pwlaser2"));
        render->sprite(Vector2D(810,  50), sheet->getSprite("pwlaser3"));
        render->sprite(Vector2D(810,  70), sheet->getSprite("pwlaser4"));
		render->present();
		assert.isTrue(true);
	}

	void SdlFileReaderTest::run() {
		runtest("readSpriteSheet_Test", &SdlFileReaderTest::readSpriteSheet_Test);
	}
}
