#pragma once
#include "Vector2.h"
#include "Entity/Player.h"
#include "Entity/EnemySpawner.h"

//========================================================
//	円形同士の衝突判定を処理するクラス
//========================================================

class Collision_Circle {
private:
	Player* player_;
	Enemy* enemy_[enemySpawnMax];
	Vector2 direction_;
	float length_;
public:
	Collision_Circle(Player* player, Spawner* spawner);
	void OnCollision(int num);
	void Length(Vector2 pos1, Vector2 pos2);
};

