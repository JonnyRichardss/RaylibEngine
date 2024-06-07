#include "RenderableObject.h"
#include "Engine.h"

namespace JREngine
{
	RenderableObject::RenderableObject() :Visible(true), Active(true), id(Engine::GetNewID())
	{
	}
	RenderableObject::~RenderableObject()
	{
	}
	const int RenderableObject::GetID()
	{
		return id;
	}
	//note: when adding sprites -- reimplement updateAndRender to update the visuals properly
	void RenderableObject::UpdateAndRender(std::vector<RenderableObject*>& renderQueue)
	{
		if (this == nullptr) return; //deleting objects during update loop can cause strange behaviour so just skip this call
		if (Active) {
			Update(GetFrameTime());

			if (Visible) {
				renderQueue.push_back(this);
			}
		}
	}
	void RenderableObject::UpdateTextureWrapperEx(Texture newTexture, Vector2 position, float rotation, float scale, Color tint)
	{
		TextureWrapperEx* newTextureWrapper = new TextureWrapperEx(newTexture, position, rotation, scale, tint);
		std::unique_ptr<TextureWrapper> newVisuals(newTextureWrapper);
		Visuals.swap(newVisuals);
	}
	void RenderableObject::UpdateTextureWrapperPro(Texture newTexture, Rectangle sourceRect, Rectangle destRect, Vector2 origin, float rotation, Color tint)
	{
		TextureWrapperPro* newTextureWrapper = new TextureWrapperPro(newTexture, sourceRect, destRect, origin, rotation, tint);
		std::unique_ptr<TextureWrapper> newVisuals(newTextureWrapper);
		Visuals.swap(newVisuals);
	}

}

