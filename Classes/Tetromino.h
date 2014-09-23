#ifndef __TETRIS_GAME_MAIN_SCENE_H__
#define __TETRIS_GAME_MAIN_SCENE_H__

#include "cocos2d.h"

enum TetrominoSubType
{
    O1 = 0, I1 = 1, I2 = 2, 
	LA1 = 3, LA2 = 4, LA3 = 5, LA4 = 6, 
	LB1 = 7, LB2 = 8, LB3 = 9, LB4 = 10, 
	SA1 = 11, SA2 = 12, 
	SB1 = 13, SB2 = 14, 
	T1 = 15, T2 = 16, T3 = 17, T4 = 18
};

class Tetromino
{
    
public:
    static Tetromino* create(TetrominoSubType subType);
    
    void initTetromino();

	static Vec2 PointConvertToGamePoint(Vec2 p, Size shapeSize);
    static Vec2 GamePointConvertToPoint(Vec2 p, Size shapeSize);
    
    bool moveTetromino();
    void moveLeft();
    void moveRight();
    bool pointOnLeft(Vec2 p);
    bool pointOnRight(Vec2 p);
    bool pointOnDown(Vec2 p);
    bool pointOnTetromino(Vec2 p);
    
    void relocation();
    void deForm();
    bool collide(Tetromino* t);
    
    Array* getBlocks();

protected:
    //================私有属性定义=================
    // 各个方块
	Sprite* b1;
	Sprite* b2;
	Sprite* b3;
	Sprite* b4;
    
    int row;
    int col;
    
    TetrominoSubType subType;

    //================私有方法定义===================
    
    bool bottonHasSomething();
    bool leftHasSomething();
    bool rightHasSomething();
    
    // 每个形状的重定位方法
    void I1_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void I2_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    
    void LA1_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void LA2_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void LA3_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void LA4_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);

    void LB1_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void LB2_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void LB3_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void LB4_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);

    void O_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);

    void SA1_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void SA2_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);

    void SB1_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void SB2_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    
    void T1_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void T2_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void T3_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    void T4_relocation(Vec2* b1Point, Vec2* b2Point, Vec2* b3Point, Vec2* b4Point);
    
};

#endif
