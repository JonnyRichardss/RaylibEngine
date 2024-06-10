#include "SortingScene.h"
#include "SortingBar.h"
#include <algorithm>



void SortingScene::Init()
{
	Texture tex = LoadTexture("Assets/whitesquare.png");
	int num_bars = DEFAULT_WINDOW_WIDTH / (BAR_WIDTH);
	for (int i = 0; i < num_bars; i++) {
		SortingBar* b = new SortingBar(i+1,tex);
		//instantiate new bar
		RegisterObject(b);
	}
	Reset();
}

void SortingScene::Update()
{
	PreUpdate();
	for (int i=0;i<UpdateQueue.size();i++)
	{
		auto& obj = UpdateQueue[i];
		obj->position = { (float)i * BAR_WIDTH,obj->position.y };
		SortingBar* b = static_cast<SortingBar*>(obj.get());
		if (b->value == i + 1) b->color = GREEN;
		else b->color = LIGHTGRAY;

		if (b->changed) {
			b->color = RED;
			b->changed = false;
		}
		obj->UpdateAndRender(RenderQueue);

	}
	PostUpdate();
}

void SortingScene::Reset()
{
	i = j = 0;
	std::shuffle(UpdateQueue.begin(), UpdateQueue.end(), rng);
}



/// DECLARATIONS
static void BubbleStep(std::vector<std::unique_ptr<JREngine::RenderableObject>>& objects, int& i, int& j);
/// DECLARATIONS
void SortingScene::PreUpdate()
{
	if (IsKeyPressed(KEY_SPACE)) Reset();
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
		barJ.changed = true;
		barK.changed = true;
		std::swap(objects[j],objects[j+1]);
	}
	j++;
}
