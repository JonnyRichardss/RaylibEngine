#include "JRExports.h"
#include "GameEngine.h"
#include "raylib.h"
#include <exception>
namespace JREngine::Engine {
	static GameEngine* _instance;
	static GameEngine* Instance() {
		if (!_instance)
			_instance = new GameEngine();
		return _instance;
	}
	static void DestroyInstance() {
		if (_instance)
			delete _instance;
	}

	void Init(int windowW, int windowH, const char* windowTitle,int exitKey)
	{
		Instance()->Init(windowW, windowH, windowTitle,exitKey);
	}
	void Init(){
		Instance()->Init();
	}
	void Loop()
	{
		Instance()->Loop();
		DestroyInstance();
	}
	void EndGame() {
		Instance()->EngineQuit = true;
	}
}


