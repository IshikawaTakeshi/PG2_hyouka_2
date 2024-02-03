#pragma once
#include "Scene/IScene.h"


//=======================================
// ステージセレクトシーンのクラス
//=======================================
class Select_Scene :public IScene {
public: //オーバーライド
    Select_Scene();
    ~Select_Scene();
    void Load()override;
    void Unload()override;
    void Update(InputKeys& input)override;
    void Draw()override;

private:
    //その他 Scene特有の変数・関数
};

