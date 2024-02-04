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
	std::unique_ptr<IScene> sceneArr_[3];
	int currentSceneNum_;
	int preSceneNum_;
};

