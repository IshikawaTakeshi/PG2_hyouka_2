#pragma once
#include "Vector2.h"
#include "Enemy.h"

//========================================================
//	エネミーのスポーン地点
//========================================================

class Spawner {
private:
	Vector2 pos_;
	float speed_;
	Enemy* enemy_[enemySpawnMax];
	int spawnTimer = 0;
public:
	Spawner();
	void Update(Vector2 playerPos);
	Vector2 GetPos() { return pos_; }
	Enemy* GetEnemy(int num) { return enemy_[num]; }
};

