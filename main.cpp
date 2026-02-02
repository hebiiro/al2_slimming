#include "pch.h"
#include "resource.h"
#include "version.hpp"
#include "app_interface.hpp"
#include "hive.hpp"
#include "utils.hpp"
#include "debug.hpp"
#include "config_dialog.hpp"
#include "config_io.hpp"
#include "app.hpp"

namespace apn::slimming
{
	//
	// エントリポイントです。
	//
	EXTERN_C BOOL APIENTRY DllMain(HMODULE instance, DWORD reason, LPVOID reserved)
	{
		switch (reason)
		{
		case DLL_PROCESS_ATTACH:
			{
				::DisableThreadLibraryCalls(hive.instance = instance);

				// このdllがアンロードされないようにします。
				::LoadLibrary(my::get_module_file_name(instance).c_str());

				break;
			}
		case DLL_PROCESS_DETACH:
			{
				break;
			}
		}

		return TRUE;
	}

	//
	// aviutl2のコンフィグを取得します。
	//
	EXTERN_C void InitializeConfig(CONFIG_HANDLE* config)
	{
		hive.aviutl2.config = config;
	}

	//
	// プラグインDLL初期化関数です。
	//
	EXTERN_C bool InitializePlugin(DWORD version)
	{
		if (version < 2003000) return false;

		app->dll_init();

		return true;
	}

	//
	// プラグインDLL終了関数です。
	//
	EXTERN_C void UninitializePlugin()
	{
		app->dll_exit();

		return;
	}

	//
	// 入力プラグインの構造体を返します。
	//
	EXTERN_C INPUT_PLUGIN_TABLE* GetInputPluginTable()
	{
		//
		// 入力プラグインの構造体です。
		//
		static struct InputPluginTable : INPUT_PLUGIN_TABLE
		{
			//
			// 翻訳されたプラグイン名です。
			//
			const std::wstring name = tr(version.name);

			//
			// 翻訳されたプラグイン情報です。
			//
			const std::wstring information = my::format(L"{/}{/}",
				tr(version.information), version.revision);

			//
			// コンストラクタです。
			//
			InputPluginTable() {
				__super::name = name.c_str();
				__super::information = version.information.c_str();
				__super::flag = 0;
				__super::filefilter = L"\0";
				__super::func_config = [](HWND hwnd, HINSTANCE dll_hinst) -> bool
				{
					::ShowWindow(hive.plugin_window, SW_SHOW);
					return true;
				};
			}
		} input_plugin_table = {}; // ゼロ初期化→メンバ変数初期化→コンストラクタ呼び出しの順を想定しています。

		return &input_plugin_table;
	}
}
