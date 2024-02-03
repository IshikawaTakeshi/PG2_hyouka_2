#pragma once
#include "Vector2.h"

class EnemySpawner {
private:
	Vector2 pos_;
	Vector2 speed_;
public:
	EnemySpawner();
	void Update();
	Vector2 GetPos() { return pos_; }
};

