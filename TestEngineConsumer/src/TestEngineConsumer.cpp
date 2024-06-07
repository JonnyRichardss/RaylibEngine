#include "JRExports.h"
using namespace JREngine;
#include "MainScene.h"
int main()
{
	MainScene scene;
	Engine::Init(&scene);
	Engine::StartLoop();
	return 0;
}