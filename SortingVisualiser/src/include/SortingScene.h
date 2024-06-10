#ifndef SORTINGSCENE_H
#define SORTINGSCENE_H
#include "Scene.h"
class SortingScene : public JREngine::Scene
{
public:
	void Init() override;
	void Update() override;
protected:
	void PreUpdate() override;
	int i, j;
};

#endif // !SORTINGSCENE_H

