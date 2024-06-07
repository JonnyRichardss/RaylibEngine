#include "TestObject.h"

namespace JREngine
{
	void TestObject::Start()
	{
		//initialisation stuff
		//init visuals
		Texture tex = LoadTexture("Assets/whitetriangle.png");
		Vector2 pos = { 0,0 };
		Visuals = std::unique_ptr<TextureWrapper>(new TextureWrapperEx(tex, pos, 0, 1, GREEN));
	}

	void TestObject::Update(float dT)
	{
		//do nothing atm
	}
}
