#pragma once
#include "Vector2.h"
#define USE_MATH_DIFINES
#include <math.h>

class Entity {
protected:
	Vector2 pos_;
	Vector2 size_;
	Vector2 direction_;
	float speed_;
	float length_;
	bool isAlive_;
public:
	Entity();
	~Entity();

	virtual void Draw();

	float Length(IntVector2 pos2);
	virtual void Normalize();
};

