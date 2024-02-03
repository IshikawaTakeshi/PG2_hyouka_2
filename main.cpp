#include <Novice.h>
#include "InputKeys.h"
#include "Scene/SceneManager.h"


const char kWindowTitle[] = "LC1B_02_イシカワタケシ_PG2_評価課題2";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	SceneManager* sceneManager = new SceneManager();

	// キー入力結果を受け取る箱
	InputKeys input;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(input.preKeys,input.keys, 256);
		Novice::GetHitKeyStateAll(input.keys);

		///
		/// ↓更新処理ここから
		///

		sceneManager->Run(input);
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (input.preKeys[DIK_ESCAPE] == 0 && input.keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
