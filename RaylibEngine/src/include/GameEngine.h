#ifndef USE_GAMEENGINE
#define USE_GAMEENGINE
#include "Engine_Constants.h"
namespace JREngine::Engine {
	class GameEngine {
		//this class isn't intended to be used as-is
		//It is re-encapsulated by the non-class namespace functions that interact with the single instance of this class
		//TLDR: use RayLibEngine.h functions, not this class
	public:
		GameEngine();
		~GameEngine();
		void Init(int windowW = DEFAULT_WINDOW_WIDTH, int windowH = DEFAULT_WINDOW_HEIGHT, const char* windowTitle = DEFAULT_WINDOW_TITLE,int exitKey = EXIT_KEY);
		void Exit();
		void Loop();
		bool EngineQuit = false;
	private:
		bool EngineInitialised = false;
	};
}

#endif // USE_GAMEENGINE


