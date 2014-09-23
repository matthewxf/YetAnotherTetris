#ifndef __TETRIS_START_SCENE_H__
#define __TETRIS_START_SCENE_H__
#include "cocos2d.h"

class StartScene : public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();

	CREATE_FUNC(StartScene);
	StartScene();
	~StartScene();

private:
	void playIsPressed(Ref* sender);
};

#endif
