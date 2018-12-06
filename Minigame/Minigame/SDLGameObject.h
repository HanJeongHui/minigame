#pragma once
#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
	friend class PlayState;
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	int getHeight() {
		return m_height;
	}
	Vector2D getPosition()
	{
		return m_position;
	}
	int getWidth() {
		return m_width;
	}

protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	
	std::string m_textureID;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

};