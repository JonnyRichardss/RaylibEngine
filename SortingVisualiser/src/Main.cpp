#include "JRExports.h"
using namespace JREngine;
#include "SortingScene.h"
int main() {
	SortingScene scene;
	Engine::Init(&scene);
	Engine::StartLoop();
	return 0;
}