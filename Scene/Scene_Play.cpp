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
	for (int i = 0; i < 10; i++) {
		enemy_[i] = new Enemy();
	}
	enemySpawner_ = new EnemySpawner();
	collisionCircle_ = new Collision_Circle();
}

void Play_Scene::Unload() {

}

void Play_Scene::Update(InputKeys& input) {
	Novice::GetMousePosition(&mousePos_.x, &mousePos_.y);
	player_->Update(input,mousePos_);
	enemySpawner_->Update();
	for (int i = 0; i < 10; i++) {
		enemy_[i]->Update(player_->GetPos());
	}
	for (int i = 0; i < 10; i++) {
		collisionCircle_->Length(player_->GetPos(), enemy_[i]->GetPos());
		collisionCircle_->OnCollision(0);
	}
	
	
	if (input.keys[DIK_Q] && input.preKeys[DIK_Q] == 0) {
		sceneNum_ = TITLE;
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
		enemy_[i]->Draw();
		Novice::ScreenPrintf(100, 100+i*30, "spawnTimer = %d", enemy_[i]->GetTimer());
	}

	
}
