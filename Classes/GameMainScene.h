#ifndef __TERIS_GAME_MAIN_SCENE_H__
#define __TERIS_GAME_MAIN_SCENE_H__

#include "cocos2d.h"
#include "Tetromino.h"

#define SCORE_LABEL_TAG 101
#define PASUMENU_MENU_TAG 102


class MainScene : public cocos2d::Layer
{
public:
	MainScene();
	static cocos2d::Scene* createScene();
	static MainScene* getInstance();
	CREATE_FUNC(MainScene);
	
	cocos2d::Sprite* getSpriteWithPoint(cocos2d::Vec2 p);
	
	void produceTetromino();
	Tetromino* getCurrentTetromino();
	cocos2d::Array* getDeadTetronimo();

	void disappear();
	void lostGame();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

private:

	static MainScene* mainScene;
	cocos2d::Array* deadTetromino;
	Tetromino* currentTetromino;

	void moveCurrentTetromino(float dt);
	void addDeadTetromino(Tetromino* t);

	void update(float time);

	void updateAndShowScore();

	bool isGameOver();

	/*
	// 单个方块死亡动画
	void playBitDead(cocos2d::Sprite* bit);
	// 死亡动画播放完执行回调删除方块
	void playBitDeadCallback(cocos2d::Node* node);
	*/

	virtual ~MainScene();
};

#endif // !__TERIS_GAME_MAIN_SCENE_H__
