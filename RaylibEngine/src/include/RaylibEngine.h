#ifndef USE_GAMENGINE
#define USE_GAMENGINE

namespace JREngine::Engine {
	//namespace contains all the functions that are intended to be used for the engine
	//Internally it references a class so that I can encapsulate its state without having to make a struct C-style
	//Theres a chance there's function call overhead but i doubt it tbh
		
	void Init(int windowW, int windowH, const char* windowTitle,int exitKey);
	void Init();

	void Loop();
		
	//Ends the game at the end of the current frame
	//cleans up properly before exiting
	void EndGame();
}

#endif // !USE_GAMENGINE
