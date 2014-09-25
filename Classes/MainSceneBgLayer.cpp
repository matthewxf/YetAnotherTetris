#include "MainSceneBgLayer.h"

USING_NS_CC;

bool MainSceneBgLayer::init() 
{
	Size visualSize = Director::getInstance()->getVisibleSize();
	Vec2 visualBoarder = Director::getInstance()->getVisibleOrigin();

	Sprite* bgSprite = Sprite::create(this->bg_img.c_str());
	bgSprite->setPosition(visualSize.width * 0.5 + visualBoarder.x, visualSize.height * 0.5 + visualBoarder.y);
	this->addChild(bgSprite);
	return true;
}