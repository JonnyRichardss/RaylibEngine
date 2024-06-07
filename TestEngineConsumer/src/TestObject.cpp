#include "TestObject.h"

namespace JREngine
{
	void TestObject::Start()
	{
		//initialisation stuff
		//init visuals
		Texture tex = LoadTexture("Assets/whitetriangle.png");
		Vector2 pos = { 0,0 };
		Vector2 size = { 100,100 };
		Visuals = std::unique_ptr<TextureWrapper>(new TextureWrapper(tex,pos,size,0,GREEN));
	}

	void TestObject::Update(float dT)
	{
		//do nothing atm
	}
}
