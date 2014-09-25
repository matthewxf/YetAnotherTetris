#include "StartScene.h"
#include "GameMainScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* StartScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StartScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool StartScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("other/menuMusic.mp3", true);

	//Size winSize = Director::getInstance()->getWinSize();
	Size visualSize = Director::getInstance()->getVisibleSize();
	Vec2 visualBoarder = Director::getInstance()->getVisibleOrigin();

	auto backgroundImg = Sprite::create("StartSceneBg.png");
	backgroundImg->setPosition(Vec2(visualSize.width / 2 + visualBoarder.x, visualSize.height / 2 + visualBoarder.y));
	this->addChild(backgroundImg);

	auto menuPlayLabel = Label::create("Play", "Helvetica-Bold", 60);
	auto menuPlay = MenuItemLabel::create(menuPlayLabel, CC_CALLBACK_1(StartScene::playIsPressed, this));
	menuPlay->setPosition(Vec2(visualSize.width / 2, 220));

	auto menu = Menu::create(menuPlay, NULL);
	this->addChild(menu);

	return true;
}


StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::playIsPressed(Ref* sender)
{
	Director::getInstance()->replaceScene(TransitionSplitRows::create(1.5, MainScene::createScene()));
}
