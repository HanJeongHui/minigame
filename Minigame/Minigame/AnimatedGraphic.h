#pragma once
#include "LoaderParams.h"
#include "SDLGameObject.h"

class AnimatedGraphic: public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	virtual void update();
	virtual void draw();
	virtual void clean() {};
private:
	int m_animSpeed;
	int m_numFrames;
};
