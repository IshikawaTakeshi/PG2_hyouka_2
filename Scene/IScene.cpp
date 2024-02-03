#include "Scene/IScene.h"
#include "Novice.h"

int IScene::sceneNum_ = TITLE;

IScene::~IScene() {
}

int IScene::GetSceneNum() const {
    return sceneNum_;
} 

void IScene::Load() {

}

void IScene::Unload() {

}

void IScene::Update(InputKeys& input) {
    input;

}

void IScene::Draw() {
}
