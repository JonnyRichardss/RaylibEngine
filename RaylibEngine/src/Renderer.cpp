#include "Renderer.h"
#include "raylib.h"
#include "raylib-assert.h"
namespace JREngine::Renderer {
	static void DrawWrapper(const TextureWrapper& wrapperIn) {
		switch (wrapperIn.Function) {
		//TODO? see if there is a real way to cast a ref to base class into derived
		//or if this raw pointer stuff is fine
		case TWT_DrawTexturePro:
		{
			const TextureWrapperPro& wrapper = static_cast<const TextureWrapperPro&>(wrapperIn);
			DrawTexturePro(wrapper.Texture, wrapper.SourceRect, wrapper.DestRect, wrapper.Origin, wrapper.Rotation, wrapper.Tint);
		}break;
		case TWT_DrawTextureEx:
		{
			const TextureWrapperEx& wrapper = static_cast<const TextureWrapperEx&>(wrapperIn);
			DrawTextureEx(wrapper.Texture, wrapper.Position, wrapper.Rotation, wrapper.Scale, wrapper.Tint);
		}break;	
		default:
		{
			AssertFail("Unreachable - DrawWrapper() switch on TextureWrapperTarget");
		}break;	
		}
	}
	void RenderFrame(std::vector<const RenderableObject*> &RenderQueue)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (const RenderableObject* obj : RenderQueue) {
			DrawWrapper(*(obj->Visuals));
		}
		EndDrawing();
		RenderQueue.clear();//note: clear just deletes the pointers, this is the intended behaviour
	}
}