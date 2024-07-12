#include <Novice.h>
#include "Player.h"
#include "InputManager.h"
#include "InputHandler.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"

const char kWindowTitle[] = "GC2B_14_ハラ_アイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player player;
	InputHandler inputHandler;
	inputHandler.Initialize();


	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		// InputManager の更新処理を実行
		InputManager::GetInstance()->Update();
		inputHandler.HandleInput(&player);
		player.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		player.Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
