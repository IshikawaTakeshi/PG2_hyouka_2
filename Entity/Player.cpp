#include "Entity/Player.h"
#include "Novice.h"



Player::Player() {
	Init({ 640.0f,360.0f }, { 32.0f,32.0f }, 10.0f);
}

void Player::Init(Vector2 pos, Vector2 size, float speed) {
	pos_ = pos;
	size_ = size;
	speed_ = speed;
	for (int i = 0; i < 10; i++) {
		bullet_[i] = new Bullet();
	}
	isAlive_ = true;
}

void Player::Update(InputKeys& input, IntVector2 mousePos) {
	//移動
	if (input.keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (input.keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (input.keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (input.keys[DIK_D]) {
		pos_.x += speed_;
	}

	//場外に行かないようにする処理
	if (pos_.x + size_.x >= 1280.0f) {
		pos_.x = 1280.0f - size_.x;
	}
	if (pos_.x - size_.x <= 0) {
		pos_.x = size_.x;
	}
	if (pos_.y + size_.y >= 720.0f) {
		pos_.y = 720.0f - size_.y;
	}
	if (pos_.y - size_.y <= 0) {
		pos_.y = size_.y;
	}

	//射撃
	for (int i = 0; i < 10; i++) {
		bullet_[i]->Update();
	}
	timer_++;
	if (Novice::IsPressMouse(0)) {
		if (timer_ >= 10) {
			for (int i = 0; i < 10; i++) {
				if (bullet_[i]->GetIsShot() == false) {
					bullet_[i]->Init(pos_, mousePos);
					break;
				}
			}
			timer_ = 0;
		}
	}
}

void Player::Draw() {
	for (int i = 0; i < 10; i++) {
		bullet_[i]->Draw();
	}

	if (isAlive_ == true) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f,
			0xffffffff,
			kFillModeSolid
		);
	}

}

float Player::Length(IntVector2 mousePos) {
	direction_.x = pos_.x - (float)mousePos.x;
	direction_.y = pos_.y - (float)mousePos.y;
	length_ = sqrtf(direction_.x * direction_.x + direction_.y * direction_.y);
	return length_;
}

void Player::Normalize() {
	if (length_ != 0.0f) {
		direction_.x /= length_;
		direction_.y /= length_;
	}
}


