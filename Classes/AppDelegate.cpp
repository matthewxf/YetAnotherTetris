#include "AppDelegate.h"
#include "AppMacros.h"
#include "StartScene.h"

USING_NS_CC;
#define DEVICE_WIDTH 480
#define DEVICE_HEIGHT 480

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLView::createWithRect("My Game", Rect(0, 0, DEVICE_WIDTH, DEVICE_HEIGHT));
		glview->setFrameSize(DEVICE_WIDTH, DEVICE_HEIGHT);
        director->setOpenGLView(glview);
    }

	auto screenSize = glview->getFrameSize();

	std::vector<std::string> searchPaths;
#if 0
	if (screenSize.height > mediumResource.size.height)
	{
		searchPaths.push_back(largeResource.directory);
		director->setContentScaleFactor(largeResource.size.width / designResolutionSize.width);
	}
	else if (screenSize.height > smallResource.size.height)
	{
		searchPaths.push_back(mediumResource.directory);
		director->setContentScaleFactor(mediumResource.size.width / designResolutionSize.width);
	}
	else
#endif
	{
		searchPaths.push_back(smallResource.directory);
		director->setContentScaleFactor(smallResource.size.width / designResolutionSize.width);
	}

	FileUtils::getInstance()->setSearchPaths(searchPaths);

	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_WIDTH);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = StartScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
