#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"

class Missile : public SDLGameObject {
public:
	Missile(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};