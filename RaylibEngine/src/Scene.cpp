#include "Scene.h"
namespace JREngine {
	Scene::Scene() : highestID(0)
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Update()
	{
		PreUpdate();
		for (auto& obj : UpdateQueue)
		{
			obj->UpdateAndRender(RenderQueue);

		}
		PostUpdate();
	}

	void Scene::RegisterObject(RenderableObject* obj)
	{
		std::unique_ptr<RenderableObject> thisObject(obj);
		TraceLog(LOG_INFO, "Registering object with id : %i", thisObject->GetID());
		thisObject->Start();
		UpdateQueue.push_back(std::move(thisObject));
	}

	//TODO! Deregistering
	void Scene::DeregisterObject(RenderableObject* obj)
	{
	}

	void Scene::DeregisterObject(int id)
	{
	}

	int Scene::GetNewID()
	{
		return highestID++;
	}

	void Scene::PreUpdate() {}

	void Scene::PostUpdate() {}
}
