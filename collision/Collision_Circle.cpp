#include "Collision_Circle.h"
#define USE_MATH_DIFINES
#include <math.h>

//========================================================
//	円形同士の衝突判定を処理するクラス
//========================================================

//コンストラクタ
Collision_Circle::Collision_Circle(Player* player, Spawner* spawner) {
	player_ = player;
	for (int i = 0; i < enemySpawnMax; i++) {
		enemy_[i] = spawner->GetEnemy(i);
	}
	
	direction_ = { 0,0 };
	length_ = 0;
}

//衝突判定と処理
void Collision_Circle::OnCollision(int num) {
	switch (num) {
	case 0://プレイヤーとエネミーの衝突処理
		for (int i = 0; i < 10; i++) {
			Length(player_->GetPos(), enemy_[i]->GetPos());
			if (player_->GetSize().x + enemy_[i]->GetSize().x >= length_) {
				player_->SetIsAlive(false);
			}
		}
	case 1://プレイヤー弾と敵の衝突処理
		for (int i = 0; i < 10; i++) {
			for (int a = 0; a < enemySpawnMax; a++) {
				Length(player_->GetBullet(i)->GetPos(),enemy_[a]->GetPos());
				if (player_->GetBullet(i)->GetSize().x + enemy_[a]->GetSize().x >= length_) {
					enemy_[a]->SetIsAlive(false);
					player_->GetBullet(i)->SetIsShot(false);
					break;
				}
			}
			
		}
		break;
	}
	
}

//距離を計算する関数
void Collision_Circle::Length(Vector2 pos1, Vector2 pos2) {
	direction_.x = (float)pos1.x - (float)pos2.x;
	direction_.y = (float)pos1.y - (float)pos2.y;
	length_ = sqrtf(direction_.x * direction_.x + direction_.y * direction_.y);
}
