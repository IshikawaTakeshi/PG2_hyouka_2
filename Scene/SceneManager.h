#pragma once
#include "Scene/IScene.h"
#include <memory>

//=======================================
// シーンの遷移を管理するためのクラス
//=======================================
class SceneManager {
public:
	SceneManager();
	~SceneManager();
	void Run(InputKeys& input);


private:
	/*
	スマートポインタ資料：
	https://qiita.com/hmito/items/9b35a2438a8b8ee4b5af
	普通の配列でもいいが、メモリリークの心配がなくなるため
	unique_ptrなどスマートポインタがおすすめ
	*/
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNum_;
	int preSceneNum_;

};

