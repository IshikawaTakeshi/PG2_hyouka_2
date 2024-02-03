#pragma once
#include "Scene/IScene.h"

//=======================================
// タイトルシーンのクラス
//=======================================

class Title_Scene :public IScene {
public: //オーバーライド
	Title_Scene();
	~Title_Scene();
	void Load()override;
	void Unload()override;
	void Update(InputKeys& input)override;
	void Draw()override;

private:
	//その他 TitleScene特有の変数・関数

};

