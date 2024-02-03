#pragma once
#include "Vector2.h"
#include "Entity/Player.h"
#include "Entity/Bullet.h"
#include "Entity/Enemy.h"

class Collision_Circle {
private:
	Player* player_;
	Bullet* bullet_;
	Enemy* enemy_;
	Vector2 direction_;
	float length_;
public:
	Collision_Circle();
	void OnCollision(int num);
	float Length(Vector2 pos1, Vector2 pos2);
};

