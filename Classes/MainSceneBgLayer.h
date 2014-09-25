#ifndef __TetrisGame_BackgroundLayer__
#define __TetrisGame_BackgroundLayer__

#include "cocos2d.h"

class MainSceneBgLayer : public cocos2d::Layer 
{
private:
	std::string bg_img = "GameSceneBg.png";

public:
	virtual bool init();
	CREATE_FUNC(MainSceneBgLayer);
};

#endif