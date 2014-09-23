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

	virtual bool init();

	static Scene* createScene();
	static MainScene* getInstance();
	CREATE_FUNC(MainScene);
	
	Sprite* getSpriteWithPoint(Vec2 p);

	Tetromino* getCurrentTetromino();

	Array* getDeadTetronimo();

	void lostGame();

	void produceTetromino();

	void disappear();

	virtual void onEnter();
	virtual void onExit();

private:

	Array* deadTetromino;

	Tetromino* currentTetromino;

	void addDeadTetromino(Tetromino* t);

	bool isGameOver();

	void update(float time);

	void moveCurrentTetromino();

	// 单个方块死亡动画
	void playBitDead(Sprite* bit);
	// 死亡动画播放完执行回调删除方块
	void playBitDeadCallback(Node* node);

	virtual ~MainScene();
};

#endif // !__TERIS_GAME_MAIN_SCENE_H__
