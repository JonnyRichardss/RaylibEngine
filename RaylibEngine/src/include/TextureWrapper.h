#ifndef TEXTURE_WRAPPER_H
#define TEXTURE_WRAPPER_H
#include "raylib.h"
#include "Engine_Constants.h"
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
			UpdatePos(position, size);
		}
		void UpdatePos(Vector2 position,Vector2 size) {
			SourceRect = { 0.0f, 0.0f, (float)Texture.width, (float)Texture.height };
			if (ANCHOR_CENTER) {
				DestRect = { (position.x - (size.x / 4.0f)), (position.y - (size.y / 4.0f)), size.x, size.y };
				Origin = { (size.x / 4.0f), (size.y / 4.0f) };
			}
			else {
				DestRect = { position.x , position.y, size.x, size.y };
				Origin = { 0,0 };
			}
		}
		void UpdateColor(Color newColor) {
			Tint = newColor;
		}
	};
}
#endif // TEXTURE_WRAPPER_H
