#include "Collision_Circle.h"
#define USE_MATH_DIFINES
#include <math.h>

Collision_Circle::Collision_Circle() {}

void Collision_Circle::OnCollision(int num) {
	switch (num) {
	case 0:
		if (player_->GetSize().x + enemy_->GetSize().x >= length_) {
			player_->SetIsAlive(false);
		}
	case 1:
		if (bullet_->GetSize().x + enemy_->GetSize().x >= length_) {
			enemy_->SetIsAlive(false);
			bullet_->SetIsShot(false);
		}
		break;
	}
	
}

float Collision_Circle::Length(Vector2 pos1, Vector2 pos2) {
	direction_.x = (float)pos1.x - (float)pos2.x;
	direction_.y = (float)pos1.y - (float)pos2.y;
	length_ = sqrtf(direction_.x * direction_.x + direction_.y * direction_.y);
	return length_;
}
