#include "EnemySpawner.h"

//コンストラクタ
Spawner::Spawner() {
	pos_ = { 0.0f,1.0f };
	speed_ = 8.0f;
	for (int i = 0; i < 10; i++) {
		enemy_[i] = new Enemy();
	}
}

//更新処理
void Spawner::Update(Vector2 playerPos) {
	pos_.x += speed_;
	if (pos_.x >= 1280.0f || pos_.x <= 0) {
		speed_ *= -1.0f;
	}

	//エネミーの更新処理
	for (int i = 0; i < enemySpawnMax; i++) {
		enemy_[i]->Update();
	}


	for (int i = 0; i < enemySpawnMax; i++) {
		spawnTimer++;
		//エネミーの復活する時の処理
		if (enemy_[i]->GetIsAlive() == false) {
			if (spawnTimer >= 120) {
				enemy_[i]->Init(playerPos, pos_);
				spawnTimer = 0;
				break;
			}
		}
	}
}
