#include "SortingBar.h"
#include "Engine_Constants.h"
SortingBar::SortingBar(float value,Texture tex) : value(value), tex(tex)
{
}
void SortingBar::Start()
{
	position = { 0,DEFAULT_WINDOW_HEIGHT };
	Vector2 size = { BAR_WIDTH,value *BAR_HEIGHT_MULT };
	Visuals = std::unique_ptr<JREngine::TextureWrapper>(new JREngine::TextureWrapper(tex, position, size, 0, GREEN));
}

void SortingBar::Update(float dT)
{
	Visuals->UpdatePos({position.x,position.y - value*BAR_HEIGHT_MULT}, {BAR_WIDTH,value*BAR_HEIGHT_MULT});
	Visuals->UpdateColor(color);
}
