#pragma once
#include "Vector2.h"
#include "InputKeys.h"

//====================================================
// IScene : 各種シーンの基底クラスになる(interface class)
//====================================================

enum Scene {
	TITLE,
	STAGESELECT,
	GAMEPLAY
};

class IScene {
public:
	virtual ~IScene();
	int GetSceneNum()const;
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update(InputKeys& input) = 0;
	virtual void Draw() = 0;

protected:
	//現在のシーンを識別するための変数
	//この数字をシーンクラスの中でいじることでシーンを遷移させる
	static int sceneNum_;
	IntVector2 mousePos_;
	
	Vector2 size_;
};

