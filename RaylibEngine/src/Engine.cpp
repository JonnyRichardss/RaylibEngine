#include "Engine.h"
#include "raylib.h"
#include "raylib-assert.h"
namespace JREngine{
	//constructor and destructor only exist to manage memory for internal class state 
	//Init() and Exit() handle raylib / other state
	// These are just for RAII of internal memory
	//IE - all paired calls for resources that aren't part of this class go in init/exit
	static Engine* _instance;
	Engine* Engine::Instance() {
		if (!_instance)
			_instance = new Engine();
		return _instance;
	}
	void Engine::DestroyInstance() {
		if (_instance)
			delete _instance;
	}
	Engine::Engine() : EngineInitialised(false),EngineQuit(false),ActiveScene(nullptr)
	{
	}
	Engine::~Engine()
	{
		//no explicit cleanup needed right now
	}
	void Engine::Init(Scene* initialScene, int windowW, int windowH, const char* windowTitle,int exitKey)
	{
	//ENGINEINSTANCE
		Instance()->EngineInitialised = true;
		Instance()->ActiveScene = initialScene;
	//RAYLIB
		InitWindow(windowW, windowH, windowTitle);
		SetTargetFPS(TARGET_FPS);
		//SetWindowIcon();
		InitAudioDevice();
		SetExitKey(KEY_ESCAPE);
		Camera2D& Camera = Instance()->MainCamera;
		Camera.target = { 0,0 };
		Camera.offset = CAMERA_OFFSET;
		Camera.rotation=0.0f;
		Camera.zoom=1.0f;
	}
	void Engine::StartLoop() {
		Instance()->Loop();
	}
	void Engine::Loop()
	{
		Assert(ActiveScene != nullptr, "Engine loop started without initialisation! Cannot launch main loop!");
		Instance()->ActiveScene->Init();//intialise scenes after window
		while (!EngineQuit) {
			//gameloop
			if (WindowShouldClose()) {
				EngineQuit = true;
				break;
			}
			//input
			ActiveScene->Update();
			RenderFrame();
		}
		Instance()->Exit();
	}
	//change all this
	//just use texturePro and transform so things are centered on their centers.
	void Engine::RenderFrame()
	{
		BeginDrawing();
		
		ClearBackground(BACK_COLOR);
		BeginMode2D(MainCamera);
		for (const RenderableObject* obj : ActiveScene->RenderQueue) {
			if (obj == nullptr) {
				TraceLog(LOG_WARNING, "Object reference in render queue was null, skipping!");
				continue;
			}
			const TextureWrapper& wrapper = *(obj->Visuals);
			DrawTexturePro(wrapper.Texture, wrapper.SourceRect, wrapper.DestRect, wrapper.Origin, wrapper.Rotation, wrapper.Tint);
			if (DRAW_DEBUG) {
				DrawCircle(obj->position.x, obj->position.y, 3, RED);
			}
		}
		EndMode2D();
		EndDrawing();
		ActiveScene->RenderQueue.clear();//note: clear just deletes the pointers, this is the intended behaviour
	}
	void Engine::Exit() {
		CloseWindow();
		CloseAudioDevice();
	}
	void Engine::EndGame() {
		Instance()->EngineQuit = true;
	}
	int Engine::GetNewID()
	{
		return Instance()->ActiveScene->GetNewID();
	}
}
