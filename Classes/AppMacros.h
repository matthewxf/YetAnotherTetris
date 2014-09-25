#ifndef __APP_MACROS_H__
#define __APP_MACROS_H__

#define DESIGN_RESOLUTION_480X320	0
#define DESIGN_RESOLUTION_960X640   1
#define DESIGN_RESOLUTION_1920X1080	2

//Modify this line for changing target device
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_480X320

typedef struct tagResource
{
	cocos2d::Size size;
	char directory[50];
}Resource;

static Resource smallResource = { cocos2d::Size(320, 480), "ldpi" };
static Resource mediumResource = { cocos2d::Size(640, 960), "mdpi" };
static Resource largeResource = { cocos2d::Size(1080, 1920), "hdpi" };

#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_480X320)
static cocos2d::Size designResolutionSize = cocos2d::Size(320, 480);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_960X640)
static cocos2d::Size designResolutionSize = cocos2d::Size(640, 960);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1920X1080)
static cocos2d::Size designResolutionSize = cocos2d::Size(1920, 1080);
#else
#error unknown target design resolution!
#endif

// 480*320的字体大小是24号，根据当前的分辨率来修改字体大小
#define TITLE_FONT_SIZE  (cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 24)

#endif
