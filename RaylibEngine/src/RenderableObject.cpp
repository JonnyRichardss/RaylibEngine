#include "RenderableObject.h"

RenderableObject::RenderableObject()
{
}

RenderableObject::~RenderableObject()
{
}

void RenderableObject::UpdateTextureWrapperEx(Texture newTexture, Vector2 position, float rotation, float scale, Color tint)
{
	TextureWrapperEx* newTextureWrapper = new TextureWrapperEx(newTexture,position,rotation,scale,tint);
	std::unique_ptr<TextureWrapper> newVisuals (newTextureWrapper);
	Visuals.swap(newVisuals);
}

void RenderableObject::UpdateTextureWrapperPro(Texture newTexture, Rectangle sourceRect, Rectangle destRect, Vector2 origin, float rotation, Color tint)
{
	TextureWrapperPro* newTextureWrapper = new TextureWrapperPro(newTexture,sourceRect,destRect,origin,rotation,tint);
	std::unique_ptr<TextureWrapper> newVisuals(newTextureWrapper);
	Visuals.swap(newVisuals);
}


