#ifndef SORTINGSCENE_H
#define SORTINGSCENE_H
#include "Scene.h"
#include <random>
class SortingScene : public JREngine::Scene
{
public:
	void Init() override;
	void Update() override;
	void Reset();
protected:
	std::default_random_engine rng = std::default_random_engine{};
	void PreUpdate() override;
	int i, j;
};

#endif // !SORTINGSCENE_H

