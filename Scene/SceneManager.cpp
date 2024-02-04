#include "Scene/SceneManager.h"
#include "Scene/Scene_Title.h"
#include "Scene/Scene_Select.h"
#include "Scene/Scene_Play.h"
#include "Novice.h"

//コンストラクタ
SceneManager::SceneManager() {
	preSceneNum_ = 0;
	currentSceneNum_ = 0;
	sceneArr_[TITLE] = std::make_unique<Title_Scene>();
	sceneArr_[STAGESELECT] = std::make_unique<Select_Scene>();
	sceneArr_[GAMEPLAY] = std::make_unique<Play_Scene>();
}

//ディストラクタ
SceneManager::~SceneManager() {

}

//各シーンの
void SceneManager::Run(InputKeys& input) {
	preSceneNum_ = currentSceneNum_;
	currentSceneNum_ = sceneArr_[currentSceneNum_]->GetSceneNum();

	if (preSceneNum_ != currentSceneNum_) {
		sceneArr_[preSceneNum_]->Unload();
		sceneArr_[currentSceneNum_]->Load();
	}
	sceneArr_[currentSceneNum_]->Update(input);
	sceneArr_[currentSceneNum_]->Draw();

#ifdef _DEBUG
	//シーンの番号表示
	Novice::ScreenPrintf(10, 10, "SceneNum:%d", currentSceneNum_);
#endif
}
