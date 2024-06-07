#ifndef RENDERABLEOBJECT_H
#define RENDERABLEOBJECT_H
#include "raylib.h"
#include "TextureWrapper.h"
#include <memory>
#include <vector>
namespace JREngine
{
	class RenderableObject
	{
	public:
		RenderableObject();
		virtual ~RenderableObject();
		const int GetID();
		std::unique_ptr<TextureWrapper> Visuals; //must be instatiated in derived class to one of the derived forms of TextureWrapper to choose the draw function to use
		virtual void UpdateAndRender(std::vector<RenderableObject*>& renderQueue);
		virtual void Start() = 0;
		bool Active;
		bool Visible;
	protected:
		const int id;
		void UpdateTextureWrapperEx(Texture newTexture, Vector2 position, float rotation = 0, float scale = 1, Color tint = { 255,255,255,255 });
		void UpdateTextureWrapperPro(Texture newTexture, Rectangle sourceRect, Rectangle destRect, Vector2 origin = { 0,0 }, float rotation = 0, Color tint = { 255,255,255,255 });
		virtual void Update(float dT) = 0;
	};
}
#endif // !RENDERABLEOBJECT_H
