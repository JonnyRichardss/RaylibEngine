#ifndef TEXTURE_WRAPPER_H
#define TEXTURE_WRAPPER_H
#include "raylib.h"
namespace JREngine
{
	//only supporting two levels of texture wrapping complexity for now - this way it can be expandable to support nmap or the intermediate-complexity versions
	enum TextureWrapperTarget {
		TWT_DrawTextureEx,
		TWT_DrawTexturePro
	};
	struct TextureWrapper {
		//wrapper target can be switched on to find out which fields are initialised and can therefore be used in draw calls
		TextureWrapperTarget Function;
		Texture2D Texture;
		Color Tint;
	protected:
		//base class cannot be instantiated
		TextureWrapper() = default;
	};

	struct TextureWrapperEx : TextureWrapper {
		Vector2 Position;
		float Rotation;
		float Scale;
		TextureWrapperEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint) {
			Function = TWT_DrawTextureEx;
			Texture = texture;
			Position = position;
			Rotation = rotation;
			Scale = scale;
			Tint = tint;
		}
	};
	struct TextureWrapperPro : TextureWrapper {
		Rectangle SourceRect;
		Rectangle DestRect;
		Vector2 Origin;
		float Rotation;
		TextureWrapperPro(Texture2D texture, Rectangle sourceRect, Rectangle destRect, Vector2 origin, float rotation, Color tint) {
			Function = TWT_DrawTexturePro;
			Texture = texture;
			SourceRect = sourceRect;
			DestRect = destRect;
			Origin = origin;
			Rotation = rotation;
			Tint = tint;
		}
	};
}
#endif // TEXTURE_WRAPPER_H
