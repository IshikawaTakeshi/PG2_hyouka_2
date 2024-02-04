#pragma once
#include "Scene/IScene.h"
#include "Entity/Player.h"
#include "Entity/EnemySpawner.h"
#include "Collision/Collision_Circle.h"

//=======================================
// ゲームプレイシーンのクラス
//=======================================

class Play_Scene :public IScene {
public: //オーバーライド
    Play_Scene();
    ~Play_Scene();
    void Load()override;
    void Unload()override;
    void Update(InputKeys& input)override;
    void Draw()override;
  
private:
    //その他 scene特有の変数・関数
    Player* player_;
    Spawner* spawner_;
    Collision_Circle* collisionCircle_;
};

