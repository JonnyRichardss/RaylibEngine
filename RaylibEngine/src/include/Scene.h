#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <memory>
#include "RenderableObject.h"
namespace JREngine {
	class Scene
	{
	public:
		Scene();
		virtual ~Scene();
		virtual void Init() = 0;
		virtual void Update(); //when you override update make sure to re-implements its functionality
		void RegisterObject(RenderableObject* obj);
		void DeregisterObject(RenderableObject* obj);
		void DeregisterObject(int id);
		int GetNewID();
		std::vector<RenderableObject*> RenderQueue;
	protected:
		int highestID = 0;
		//PreUpdate and PostUpdate have no behaviour, they are optional
		virtual void PreUpdate();
		virtual void PostUpdate();
		std::vector<std::unique_ptr<RenderableObject>> UpdateQueue;

	};
}
#endif // !SCENE_H


