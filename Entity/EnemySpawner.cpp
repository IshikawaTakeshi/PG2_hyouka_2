#include "EnemySpawner.h"

EnemySpawner::EnemySpawner() {
	pos_ = { 0.0f,0.0f };
	speed_ = { 8.0f,0.0f };
}

void EnemySpawner::Update() {
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	if (pos_.x >= 1280.0f) {
		speed_.x = 0;
		speed_.y = -8.0f;
	}
	if (pos_.x <= 0) {
		speed_.x = 0;
		speed_.y = 8.0f;
	}
	if (pos_.y >= 720.0f ) {
		speed_.y = 0;
		speed_.x = 8.0f;
	}
	if (pos_.y <= 0) {
		speed_.y = 0;
		speed_.x = -8.0f;
	}
}
