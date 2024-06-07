#include "MainScene.h"
#include "TestObject.h"
namespace JREngine
{
	void MainScene::Init()
	{
		RegisterObject(new TestObject);
	}

}