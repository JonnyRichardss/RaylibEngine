#ifndef ENGINE_H
#define ENGINE_H
#include "Engine_Constants.h"
#include "Scene.h"
namespace JREngine{
	class Engine {
		//this class isn't intended to be used as-is
		//It is re-encapsulated by the non-class namespace functions that interact with the single instance of this class
		//TLDR: use RayLibEngine.h functions, not this class
	public:
		//Just incase you want to access the engine state directly. Shouldn't be strictly necessary.
		static Engine* Instance();
		static void Init(Scene* initialScene,int windowW = DEFAULT_WINDOW_WIDTH, int windowH = DEFAULT_WINDOW_HEIGHT, const char* windowTitle = DEFAULT_WINDOW_TITLE, int exitKey = EXIT_KEY);
		static void StartLoop();
		static void EndGame();
		static int GetNewID();
	private:
		static void DestroyInstance();
		Engine();
		~Engine();
		void Exit();
		void Loop();
		void RenderFrame();
		bool EngineQuit = false;
		bool EngineInitialised = false;
		Camera2D MainCamera;
		//TODO! Scene updating and switching
		//Also to do have engine take ownership of scenes
		Scene* ActiveScene;
		std::vector<std::unique_ptr<Scene>> AllScenes;
	};
}

#endif // GAMEENGINE_H


