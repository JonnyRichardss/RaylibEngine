#include "SortingScene.h"
#include "SortingBar.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>


void SortingScene::Init()
{
	Texture tex = LoadTexture("Assets/whitesquare.png");
	srand(time(NULL));
	int num_bars = DEFAULT_WINDOW_WIDTH / (BAR_WIDTH);
	for (int i = 0; i < num_bars; i++) {
		SortingBar* b = new SortingBar(i+1,tex);
		//instantiate new bar
		RegisterObject(b);
	}
	i = j = 0;
	auto rng = std::default_random_engine{};
	std::shuffle(UpdateQueue.begin(), UpdateQueue.end(), rng);
}

void SortingScene::Update()
{
	PreUpdate();
	for (int i=0;i<UpdateQueue.size();i++)
	{
		auto& obj = UpdateQueue[i];
		obj->position = { (float)i * BAR_WIDTH,obj->position.y };
		obj->UpdateAndRender(RenderQueue);

	}
	PostUpdate();
}



/// DECLARATIONS
static void BubbleStep(std::vector<std::unique_ptr<JREngine::RenderableObject>>& objects, int& i, int& j);
/// DECLARATIONS
void SortingScene::PreUpdate()
{
	//complete one step of algorithm, update queue order determines where it is drawn
	BubbleStep(UpdateQueue, i, j);
}
static void BubbleStep(std::vector<std::unique_ptr<JREngine::RenderableObject>>& objects,int& i,int& j) {
	if (j >= objects.size()-1) {
		j = 0;
		i++;
	}
	if (i >= objects.size()) return;
	SortingBar& barJ = *static_cast<SortingBar*>(objects[j].get());
	SortingBar& barK = *static_cast<SortingBar*>(objects[j+1].get());
	if (barJ.value > barK.value) {
		std::swap(objects[j],objects[j+1]);
	}
	j++;
}
