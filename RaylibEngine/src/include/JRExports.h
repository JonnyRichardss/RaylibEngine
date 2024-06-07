#ifndef USE_ENGINE_EXPORTS
#define USE_ENGINE_EXPORTS
#include "Engine_Constants.h"
namespace JREngine {
	/// this is the header that defines the "API" for the static library
	/// technically all the headers can be accessed because its a staticlib but this is the one that is intended to be included and used
	// TODO! add functions once i have written the headers
	class Scene;
	extern class Engine {
	public:
		static void Init(Scene* initialScene, int windowW = DEFAULT_WINDOW_WIDTH, int windowH = DEFAULT_WINDOW_HEIGHT, const char* windowTitle = DEFAULT_WINDOW_TITLE, int exitKey = EXIT_KEY);
		static void StartLoop();
		static void EndGame();
	};

	//Classes defined in other headers that are designed to be derived from:
		//RenderableObject.h -- generic object that can be displayed on the screen
		//Scene.h -- every game MUST have a scene that derives from this (passed into engine on startup)
}
#endif // !USE_ENGINE_EXPORTS
