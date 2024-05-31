#ifndef RENDERER_H
#define RENDERER_H
#include <vector>
#include "RenderableObject.h"
namespace JREngine::Renderer {
	void RenderFrame(std::vector<RenderableObject*> &RenderQueue);
}
#endif // !RENDERER_H

