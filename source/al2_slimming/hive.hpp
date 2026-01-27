#pragma once

namespace apn::slimming
{
	//
	// このクラスは他クラスから共通して使用される変数を保持します。
	//
	inline struct Hive
	{
		//
		// このdllのインスタンスハンドルです。
		//
		HINSTANCE instance = nullptr;

		//
		// プラグインウィンドウです。
		//
		HWND plugin_window = nullptr;

		//
		// aviutl2ウィンドウです。
		//
		HWND aviutl2_window = nullptr;

		//
		// コンフィグのファイル名です。
		//
		std::wstring config_file_name;

		//
		// このクラスはaviutl2関連の変数を保持します。
		//
		struct aviutl2_t {
			CONFIG_HANDLE* config = {};
		} aviutl2;

		//
		// スリムバー(を持つウィンドウ)です。
		//
		my::slimbar_t slimbar;

		//
		// メッセージボックスを表示します。
		//
		int32_t message_box(const std::wstring& text, HWND hwnd = nullptr, int32_t type = MB_OK | MB_ICONWARNING) {
			if (!hwnd) hwnd = plugin_window;
			return ::MessageBoxW(hwnd, text.c_str(), version.information.c_str(), type);
		}
	} hive;
}
