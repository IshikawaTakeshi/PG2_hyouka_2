#pragma once
#include "Entity/Entity.h"

static const int enemySpawnMax = 10;

class Player;
class Enemy: public Entity{
public:
	Enemy();
	~Enemy();

	void Init(Vector2 playerPos,Vector2 spawnerPos);
	void Update();
	void Draw()override;
	float Length(Vector2 pos2);
	void Normalize()override;

	Vector2 GetPos() { return pos_; }
	Vector2 GetSize() { return size_; }
	bool GetIsAlive()override { return isAlive_; }

	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
};

