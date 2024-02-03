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

void SceneManager::Run(InputKeys &input) {
    //1 前フレームのシーンナンバーをpreSceneNum_に保存する
    preSceneNum_ = currentSceneNum_;
    currentSceneNum_ = sceneArr_[currentSceneNum_]->GetSceneNum();

    /*2 preSceneNum_ != currentSceneNum なら
        sceneArr[preSceneNum_]をUnload
        sceneArr[currentScene]を初期化
     */
        if (preSceneNum_ != currentSceneNum_) {
            sceneArr_[preSceneNum_]->Unload();
            sceneArr_[currentSceneNum_]->Load();
        }

     // 3 sceneArr_[currentSceneNum_]のUpdate()
        sceneArr_[currentSceneNum_]->Update(input);

     // 4 sceneArr_[currentSceneNum_]のDraw()
        sceneArr_[currentSceneNum_]->Draw();

        Novice::ScreenPrintf(10, 10, "SceneNum:%d", currentSceneNum_);
       /* for (int i = 0; i < 20; i++) {
            Novice::DrawLine(0, i * 64, 1280, i * 64, 0xffffffff); 
            Novice::DrawLine(i * 64, 0, i * 64,720 , 0xffffffff);
        }*/
}
