#include "Entity/Enemy.h"
#include "Entity/Player.h"
#include "Novice.h"


Enemy::Enemy() {
	Init();
}

Enemy::~Enemy() {}

//初期化
void Enemy::Init() {
	enemySpawner_ = new EnemySpawner();
	pos_ = { 100.0f,100.0f };
	size_ = { 32.0f,32.0f };
	direction_ = { 0.0f,0.0f};
	speed_ = 8.0f;
	length_ = 0;
	isAlive_ = false;
}

//更新処理
void Enemy::Update(Vector2 playerPos) {
	pos_.x -= direction_.x * speed_;
	pos_.y -= direction_.y * speed_;


	
	//場外に行ったら死ぬ
	if (pos_.x >= 1300.0f || pos_.x <= -32.0f || pos_.y >= 750.0f || pos_.y <= -32.0f) {
		isAlive_ = false;
	}

	//復活処理
	if (isAlive_ == false) {
		
		spawnTimer_++;

		pos_.x = enemySpawner_->GetPos().x;
		pos_.y = enemySpawner_->GetPos().y;
		Length(playerPos);
		Normalize();
		if (spawnTimer_ >= 30) {
			isAlive_ = true;
			spawnTimer_ = 0;
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
			0xff00aaff,
			kFillModeSolid
		);
	}
}

float Enemy::Length(Vector2 pos2) {
	direction_.x = pos_.x - (float)pos2.x;
	direction_.y = pos_.y - (float)pos2.y;
	length_ = sqrtf(direction_.x * direction_.x + direction_.y * direction_.y);
	return length_;
}

void Enemy::Normalize() {
	if (length_ != 0.0f) {
		direction_.x /= length_;
		direction_.y /= length_;
	}
}
