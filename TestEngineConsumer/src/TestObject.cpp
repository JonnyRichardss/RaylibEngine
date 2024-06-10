#include "TestObject.h"

namespace JREngine
{
	void TestObject::Start()
	{
		//initialisation stuff
		//init visuals
		Texture tex = LoadTexture("Assets/whitetriangle.png");
		position = { 50,50 };
		Vector2 size = { 100,100 };
		Visuals = std::unique_ptr<TextureWrapper>(new TextureWrapper(tex,position,size,0,GREEN));
	}

	void TestObject::Update(float dT)
	{
		//do nothing atm
	}
}
