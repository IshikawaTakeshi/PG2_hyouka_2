#include "Entity/Bullet.h"
#define USE_MATH_DIFINES
#include <math.h>
#include "Novice.h"

Bullet::Bullet() {
	pos_ = { -20.0f,750.0f };
	size_ = { 4.0f,4.0f };
	speed_ = 16.0f;
	direction_ = { 0,0 };
	isAlive_ = false;
}

void Bullet::Init(Vector2 playerPos, IntVector2 mousePos) {
	pos_ = playerPos;
	Length(mousePos);
	Normalize();
	isAlive_ = true;
}

void Bullet::Update() {

	pos_.x -= direction_.x * speed_;
	pos_.y -= direction_.y * speed_;

	if (pos_.x >= 1280.0f || pos_.x <= -10.0f || pos_.y >= 720.0f || pos_.y <= -10.0f) {
		isAlive_ = false;
	}
}

void Bullet::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f,
		0xffff00ff,
		kFillModeSolid
	);
}

float Bullet::Length(IntVector2 pos2) {
	direction_.x = pos_.x - (float)pos2.x;
	direction_.y = pos_.y - (float)pos2.y;
	length_ = sqrtf(direction_.x * direction_.x + direction_.y * direction_.y);
	return length_;
}

void Bullet::Normalize() {
	if (length_ != 0.0f) {
		direction_.x /= length_;
		direction_.y /= length_;
	}
}
