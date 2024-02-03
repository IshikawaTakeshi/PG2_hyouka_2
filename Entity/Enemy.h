#pragma once
#include "Entity/Entity.h"
#include "EnemySpawner.h"

class Player;
class Enemy: public Entity{
private:
	EnemySpawner* enemySpawner_;
	int spawnTimer_ = 0;
public:
	Enemy();
	~Enemy();
	void Init();
	void Update(Vector2 playerPos);
	void Draw()override;
	float Length(Vector2 pos2);
	void Normalize()override;

	Vector2 GetPos() { return pos_; }
	Vector2 GetSize() { return size_; }
	bool GetIsAlive() { return isAlive_; }
	int GetTimer() { return spawnTimer_; }

	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
};

