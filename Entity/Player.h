#pragma once
#include "InputKeys.h"
#include "Entity/Bullet.h"
#include "Entity/Entity.h"

class Player: public Entity {
public:
	Player();
	void Init(Vector2 pos, Vector2 size, float speed);
	void Update(InputKeys& input,IntVector2 mousePos );
	void Draw()override;
	float Length(IntVector2 mousePos);
	void Normalize()override;

	Vector2 GetPos() { return pos_; }
	Vector2 GetSize() { return size_; }
	bool GetIsAlive() { return isAlive_; }

	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
private:
	Bullet *bullet_[10];
	int timer_ = 10;
};

