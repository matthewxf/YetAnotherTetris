#include "GameConfig.h"
#include "GameMainScene.h"
#include "SimpleAudioEngine.h"
#include "MainSceneBgLayer.h"
#include "Tetromino.h"


USING_NS_CC;

MainScene* MainScene::mainScene = nullptr;

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
	CC_SAFE_RELEASE(this->deadTetromino);
}

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto mainLayer = MainScene::create();
	auto bgLayer = MainSceneBgLayer::create();

	scene->addChild(bgLayer);
	scene->addChild(mainLayer);

	return scene;
}

MainScene* MainScene::getInstance()
{
	if (mainScene != nullptr)
	{
		return mainScene;
	}
	return nullptr;
}

bool MainScene::init()
{
	do 
	{
		CC_BREAK_IF(!Layer::init());
		Size size = Director::getInstance()->getWinSize();

		mainScene = this;

		// 播放背景音乐
		//CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		//CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("other/gameMusic.mp3", true);

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		// 显示分数label
		auto scoreLabel = Label::createWithSystemFont("", "Helvetica-Bold", 50);
		scoreLabel->setTag(SCORE_LABEL_TAG);
		//scoreLabel->setPosition(origin.x + visibleSize.width - scoreLabel->getContentSize().width / 2, origin.y + scoreLabel->getContentSize().height / 2);
		//scoreLabel->setPosition(100, 150);
		this->addChild(scoreLabel);
		updateAndShowScore();

		// 创建暂停按钮
		//auto pasuMenu = MenuItemImage::create("pause.png", "pause.png", this, CC_CALLBACK_1(World::pauseCallback));
		//pasuMenu->setPosition(Vec2(0, 0));
		//auto menu = Menu::create(pasuMenu, NULL);
		//menu->setPosition(Vec2(size.width - pasuMenu->getContentSize().width * 0.5 - 10, size.height - pasuMenu->getContentSize().height * 0.5 - 5));
		//menu->setTag(PASUMENU_MENU_TAG);
		//this->addChild(menu);

		deadTetromino = Array::create();
		CC_SAFE_RETAIN(deadTetromino);

		produceTetromino();

		return true;
	} while (false);

	return false;
}

void MainScene::updateAndShowScore()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto scoreLabel = static_cast<Label*>(this->getChildByTag(SCORE_LABEL_TAG));
	String  scoreString = "";
	scoreString.initWithFormat("score %ld", 10000);
	scoreLabel->setString(scoreString.getCString());
	scoreLabel->setPosition(origin.x + scoreLabel->getContentSize().width / 2, origin.y + visibleSize.height - scoreLabel->getContentSize().height / 2);
}

void MainScene::produceTetromino()
{
	TetrominoSubType type;
	//O1 = 0, I1 = 1, I2 = 2, LA1 = 3, LA2 = 4, LA3 = 5, LA4 = 6, LB1 = 7, LB2 = 8, LB3 = 9, LB4 = 10, SA1 = 11, SA2 = 12, SB1 = 13, SB2 = 14, T1 = 15, T2 = 16, T3 = 17, T4 = 18
	int i = (int)(CCRANDOM_0_1() * 1000) % 19;
	//int i = arc4random() % 19;
	switch (i) 
	{
	case 0:
		type = O1;
		break;
	case 1:
		type = I1;
		break;
	case 2:
		type = I2;
		break;
	case 3:
		type = LA1;
		break;
	case 4:
		type = LA2;
		break;
	case 5:
		type = LA3;
		break;
	case 6:
		type = LA4;
		break;
	case 7:
		type = LB1;
		break;
	case 8:
		type = LB2;
		break;
	case 9:
		type = LB3;
		break;
	case 10:
		type = LB4;
		break;
	case 11:
		type = SA1;
		break;
	case 12:
		type = SA2;
		break;
	case 13:
		type = SB1;
		break;
	case 14:
		type = SB2;
		break;
	case 15:
		type = T1;
		break;
	case 16:
		type = T2;
		break;
	case 17:
		type = T3;
		break;
	case 18:
		type = T4;
		break;

	default:
		break;
	}

	Tetromino* t = Tetromino::create(type);
	this->currentTetromino = t;

	Ref* o = nullptr;
	Array * allSprite = this->currentTetromino->getBlocks();
	CCARRAY_FOREACH(allSprite, o) 
	{
		Sprite* sp = static_cast<Sprite*>(o);
		this->addChild(sp);
	}
}

void MainScene::update(float time)
{
}


void MainScene::onEnter()
{
	Layer::onEnter();
	
	this->schedule(schedule_selector(MainScene::moveCurrentTetromino), 0.5);
}

void MainScene::onExit()
{

}

Sprite* MainScene::getSpriteWithPoint(Vec2 p)
{
	Ref* o;
	Array* allDead = this->deadTetromino;

	CCARRAY_FOREACH(allDead, o) 
	{
		Sprite * sp = static_cast<Sprite *>(o);
		Vec2 oPoint = Tetromino::PointConvertToGamePoint(sp->getPosition(), sp->getContentSize());

		if (oPoint.x == p.x && oPoint.y == p.y) {
			return sp;
		}
	}

	return nullptr;
}

void MainScene::moveCurrentTetromino(float dt)
{
	if (this->currentTetromino != nullptr) 
	{
		if (!this->currentTetromino->moveTetromino()) 
		{
			addDeadTetromino(this->currentTetromino);
			currentTetromino = nullptr;
			disappear();
			produceTetromino();
 
			/*
			if (isGameOver()) {
				if (_hero->getScore() > Hero::getMaxScore()) {
					Hero::setMaxScore(_hero->getScore());
				}

				lostGame();
			}
			*/
		}
	}
}

void MainScene::addDeadTetromino(Tetromino* t)
{
	Array* blocks = t->getBlocks();
	Ref * o;

	CCARRAY_FOREACH(blocks, o) 
	{
		Sprite* sp = static_cast<Sprite *>(o);
		this->deadTetromino->addObject(sp);
	}
}

void MainScene::disappear()
{
	int rows = 0;

	for (int row = 0; row < ROWS;) 
	{
		bool canDisapear = true;
		for (int col = 0; col < COLS; col++) 
		{
			Sprite* sp = MainScene::getSpriteWithPoint(Vec2(col, row));
			if (sp == nullptr) 
			{
				canDisapear = false;
				continue;
			}
		}

		// 将第row行所有sprite移除
		// 可以消第 row 行。将 row + 1 行向下移动。
		if (canDisapear) 
		{
			rows++;

			for (int o = 0; o < COLS; o++) 
			{
				Sprite* s = MainScene::getSpriteWithPoint(Vec2(o, row));
				// 这边开始播放死亡动画(动画包含移除）
				// playBitDead(s);
				this->removeChild(s);
				this->deadTetromino->removeObject(s);
			}

			for (int row2 = row + 1; row2 < ROWS; row2++) 
			{
				for (int col2 = 0; col2 < COLS; col2++) 
				{
					Sprite * sp = MainScene::getSpriteWithPoint(Vec2(col2, row2));
					if (sp != NULL) {
						sp->setPosition(Tetromino::GamePointConvertToPoint(Vec2(col2, row2 - 1), sp->getContentSize()));
					}
				}
			}

			//_hero->goal();
		}
		else {
			row++;
		}

	}

	if (rows > 0)
	{
		log("disapear count %d", rows);
	}

	updateAndShowScore();

}

Tetromino* MainScene::getCurrentTetromino() 
{
	return currentTetromino;
}

cocos2d::Array* MainScene::getDeadTetronimo()
{
	return this->deadTetromino;
}
