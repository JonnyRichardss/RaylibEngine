#ifndef RENDERABLEOBJECT_H
#define RENDERABLEOBJECT_H
#include "raylib.h"
#include "TextureWrapper.h"
#include <memory>
class RenderableObject
{
public:
	RenderableObject();
	~RenderableObject();
	std::unique_ptr<TextureWrapper> Visuals; //must be instatiated in derived class to one of the derived forms of TextureWrapper to choose the draw function to use
private:
	void UpdateTextureWrapperEx(Texture newTexture, Vector2 position, float rotation=0, float scale=1, Color tint = { 255,255,255,255 });
	void UpdateTextureWrapperPro(Texture newTexture, Rectangle sourceRect, Rectangle destRect, Vector2 origin={0,0}, float rotation = 0, Color tint = {255,255,255,255});
};

#endif // !RENDERABLEOBJECT_H

