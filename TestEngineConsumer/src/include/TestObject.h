#ifndef TESTOBJECT_H
#define TESTOBJECT_H
#include "RenderableObject.h"
namespace JREngine
{
	class TestObject : public RenderableObject
	{
	public:
		void Start();
	protected:
		void Update(float dT);
	};
}

#endif // !TESTOBJECT_H

