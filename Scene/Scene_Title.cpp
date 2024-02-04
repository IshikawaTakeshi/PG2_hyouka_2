#include "Scene/Scene_Title.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene_Select.h"
#include "Novice.h"

//コンストラクタ
Title_Scene::Title_Scene() {
	Load();
}

//ディストラクタ
Title_Scene::~Title_Scene() {
}

//初期化するための関数。
void Title_Scene::Load() {
	size_ = { 1280.0f, 720.0f };
}

//Load関数で入力したものを破棄する関数。
void Title_Scene::Unload() {

}

//更新処理。各オブジェクト、エンティティのUpdate関数もここに入れる。
void Title_Scene::Update(InputKeys& input) {
	if (input.keys[DIK_SPACE] && input.preKeys[DIK_SPACE] == 0) {
		sceneNum_ = STAGESELECT;
	}
}

//描画処理。各オブジェクト、エンティティのDraw関数もここに入れる。
void Title_Scene::Draw() {
	Novice::DrawBox(
		0, 0,
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f, 0x555555aa, kFillModeSolid
	);

	Novice::ScreenPrintf(580, 360, "$Xx_STG_xX$");
	Novice::ScreenPrintf(550, 400, "START:push to SPACE");
}
