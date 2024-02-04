#include "Scene/Scene_Play.h"
#include "Scene/Scene_title.h"
#include "Scene/SceneManager.h"
#include "Novice.h"

Play_Scene::Play_Scene() {
	Load();
}

Play_Scene::~Play_Scene() {

}

void Play_Scene::Load() {
	size_ = { 1280.0f, 720.0f };
	player_ = new Player();
	spawner_ = new Spawner();
	collisionCircle_ = new Collision_Circle(player_, spawner_);
}

void Play_Scene::Unload() {

}

void Play_Scene::Update(InputKeys& input) {
	switch (player_->GetIsAlive()) {
	case true:
		Novice::GetMousePosition(&mousePos_.x, &mousePos_.y);
		player_->Update(input, mousePos_);
		spawner_->Update(player_->GetPos());
		collisionCircle_->OnCollision(0);
		collisionCircle_->OnCollision(1);

		break;
	case false:
		if (input.keys[DIK_SPACE] && input.preKeys[DIK_SPACE] == 0) {
			sceneNum_ = TITLE;
		}
		break;
	}
}

void Play_Scene::Draw() {
	Novice::DrawBox(
		0, 0,
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f, 0x000112ee, kFillModeSolid
	);

	player_->Draw();
	for (int i = 0; i < 10; i++) {
		spawner_->GetEnemy(i)->Draw();
	}

	if (player_->GetIsAlive() == false) {
		Novice::ScreenPrintf(580, 360, "GAME_OVER");
		Novice::ScreenPrintf(540, 400, "TITLE:push to SPACE");
	}
}
