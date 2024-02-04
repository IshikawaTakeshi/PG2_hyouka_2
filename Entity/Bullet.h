#pragma once
#include "Entity/Entity.h"

class Bullet: public Entity {
public:
	Bullet();
	void Init(Vector2 playerPos, IntVector2 mousePos);
	void Update();
	void Draw()override;
	void Normalize()override;
	void SetPos(Vector2 pos) { pos_ = pos; };
	void SetIsShot(bool isShot) { isAlive_ = isShot; };
	
	float Length(IntVector2 pos2);

	Vector2 GetPos() { return pos_; }
	Vector2 GetSize() { return size_;}
	bool GetIsShot() { return isAlive_; };

private:
};

