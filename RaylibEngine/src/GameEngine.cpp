#include "GameEngine.h"
#include "raylib.h"

namespace JREngine::Engine {
	//constructor and destructor only exist to manage memory for internal class state 
	//Init() and Exit() handle raylib / other state
	// These are just for RAII of internal memory
	//IE - all paired calls for resources that aren't part of this class go in init/exit
	GameEngine::GameEngine()
	{
		EngineInitialised = false;
		EngineQuit = false;
	}
	GameEngine::~GameEngine()
	{
		//no explicit cleanup needed right now
	}
	void GameEngine::Init(int windowW, int windowH, const char* windowTitle,int exitKey)
	{
		EngineInitialised = true;
		InitWindow(windowW, windowH, windowTitle);
		SetTargetFPS(TARGET_FPS);
		//SetWindowIcon();
		InitAudioDevice();
		SetExitKey(KEY_ESCAPE);
	}
	void GameEngine::Exit() {
		CloseWindow();
		CloseAudioDevice();
	}
	void GameEngine::Loop()
	{
		if (!EngineInitialised) {
			//if init gains mandatory args this will have to crash
			TraceLog(LOG_WARNING, "Engine not initialised before running loop, initialising now with default parameters");
			Init();
		}
		while (!EngineQuit) {
			//gameloop
			if (WindowShouldClose()) {
				EngineQuit = true;
				break;
			}
			//input
			//update
			//render
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Hello, Raylib!", GetRenderWidth()/2, GetRenderHeight()/2, 20, BLACK);
			EndDrawing();
		}
	}
}
