#pragma once

namespace apn::slimming
{
	//
	// aviutl2ウィンドウを返します。
	//
	inline HWND get_aviutl2_window(HWND plugin_window)
	{
		// プラグインウィンドウの親ウィンドウを取得します。
		auto hwnd = ::GetParent(plugin_window);

		// 親ウィンドウのオーナーウィンドウを取得します。
		if (auto owner = ::GetWindow(hwnd, GW_OWNER)) hwnd = owner;

		// 取得したウィンドウを返します。
		return hwnd;
	}

	//
	// 指定された文字列を翻訳して返します。
	//
	inline LPCWSTR tr(const std::wstring& text)
	{
		return hive.aviutl2.config->translate(hive.aviutl2.config, text.c_str());
	}

	//
	// 指定された文字列を翻訳して返します。
	//
	inline LPCWSTR tr(const std::wstring& section, const std::wstring& text)
	{
		return hive.aviutl2.config->get_language_text(hive.aviutl2.config, section.c_str(), text.c_str());
	}
}
