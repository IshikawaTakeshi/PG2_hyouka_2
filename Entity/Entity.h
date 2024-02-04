#pragma once
#include "Vector2.h"
#define USE_MATH_DIFINES
#include <math.h>

//========================================================
//	各エンティティの基底クラス
//========================================================

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

	virtual void Draw() = 0;
	virtual void Normalize() = 0;

	virtual bool GetIsAlive() { return isAlive_; }
};

