#ifndef TEXTURE_WRAPPER_H
#define TEXTURE_WRAPPER_H
#include "raylib.h"
namespace JREngine
{
	struct TextureWrapper {
		Texture2D Texture;
		Rectangle SourceRect;
		Rectangle DestRect;
		Vector2 Origin;
		float Rotation;
		Color Tint;
		//DrawTexturePro-like constructor
		TextureWrapper(Texture2D texture, Rectangle sourceRect, Rectangle destRect, Vector2 origin, float rotation, Color tint) :
			Texture(texture),
			SourceRect(sourceRect),
			DestRect(destRect),
			Origin(origin),
			Rotation(rotation),
			Tint(tint){}
		//DrawTextureEx-like constructor 
		// (a little different since I am transforming the origin to the centre of the object)
		TextureWrapper(Texture2D texture, Vector2 position, Vector2 size, float rotation, Color tint) :
			Texture(texture),
			Rotation(rotation),
			Tint(tint)
		{
			SourceRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
			DestRect = { position.x - (size.x / 2.0f), position.y - (size.y / 2.0f), size.x, size.y};
			Origin = { (size.x / 2.0f), (size.y / 2.0f) };
		}
	};
}
#endif // TEXTURE_WRAPPER_H
