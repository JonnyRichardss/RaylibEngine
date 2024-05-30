#include "JRExports.h"
#include "GameEngine.h"
#include "raylib.h"
#include <exception>
namespace JREngine::Engine {
	static class GameQuit : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return "Game was forced to quit!";
		}
	} QuitEx;
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
	static void ForceClean() {
		//clean up for force quit -- not sure this is necessary
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
		try {
			Instance()->Loop();
		}
		catch (const GameQuit& e) {
			TraceLog(LOG_FATAL, e.what());
			ForceClean();
		}
		DestroyInstance();

		return;
	}

	void EndGame() {
		Instance()->EngineQuit = true;
	}
	void ForceQuit() {
		throw new GameQuit();
	}
}


