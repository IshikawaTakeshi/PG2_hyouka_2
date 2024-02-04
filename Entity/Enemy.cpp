#include "Entity/Enemy.h"
#include "Entity/Player.h"
#include "Novice.h"


Enemy::Enemy() {
	pos_ = { 100.0f,0.0f };
	size_ = { 32.0f,32.0f };
	direction_ = { 0.0f,0.0f };
	speed_ = 12.0f;
	length_ = 0;
	isAlive_ = false;
}

Enemy::~Enemy() {}

//初期化
void Enemy::Init(Vector2 playerPos, Vector2 spawnerPos) {
	pos_ = spawnerPos;
	Length(playerPos);
	Normalize();
	//復活処理
	isAlive_ = true;
}

//更新処理
void Enemy::Update() {
	if (isAlive_ == true) {
		pos_.x -= direction_.x * speed_;
		pos_.y -= direction_.y * speed_;

		//場外に行ったら死ぬ
		if (pos_.x >= 1300.0f || pos_.x <= -32.0f || pos_.y >= 750.0f || pos_.y <= -32.0f) {
			isAlive_ = false;
		}
	}
}

//描画処理
void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f,
			0xaaffeeff,
			kFillModeSolid
		);
	}
}

//距離を測る関数
float Enemy::Length(Vector2 pos2) {
	direction_.x = pos_.x - (float)pos2.x;
	direction_.y = pos_.y - (float)pos2.y;
	length_ = sqrtf(direction_.x * direction_.x + direction_.y * direction_.y);
	return length_;
}

//正規化
void Enemy::Normalize() {
	if (length_ != 0.0f) {
		direction_.x /= length_;
		direction_.y /= length_;
	}
}
