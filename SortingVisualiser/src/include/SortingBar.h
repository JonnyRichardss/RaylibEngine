#pragma once
#ifndef SORTINGBAR_H
#define SORTINGBAR_H
#include "RenderableObject.h"
class SortingBar : public JREngine::RenderableObject
{
public:
	SortingBar(float value,Texture tex);
	void Start() override;
	float value;
	bool changed;
protected:
	void Update(float dT) override;
	Texture tex;
};

#endif // !SORTINGBAR_H

