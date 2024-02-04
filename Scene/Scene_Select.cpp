#include "Scene/Scene_Select.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene_Play.h"
#include "Novice.h"


Select_Scene::Select_Scene() {
	Load();
}

Select_Scene::~Select_Scene() {
}

void Select_Scene::Load() {
	size_ = { 1280.0f, 720.0f };
}

void Select_Scene::Unload() {

}

void Select_Scene::Update(InputKeys& input) {

	Novice::ScreenPrintf(500, 300, "WASD:move");
	Novice::ScreenPrintf(500, 350, "MOUSE LEFT PRESS:bulletShot");
	Novice::ScreenPrintf(500, 450, "START:push to SPACE");
	if (input.keys[DIK_SPACE] && input.preKeys[DIK_SPACE] == 0) {
		sceneNum_ = GAMEPLAY;
	}
}

void Select_Scene::Draw() {
	Novice::DrawBox(
		0, 0, 
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f, 0x222222aa, kFillModeSolid
	);
}
