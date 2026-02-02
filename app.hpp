#pragma once

namespace apn::slimming
{
	//
	// このクラスはアプリケーションです。
	//
	inline struct app_t : app_interface_t
	{
		//
		// dllの初期化処理を実行します。
		//
		virtual BOOL dll_init() override
		{
			MY_TRACE_FUNC("");

			// 各種開始処理を実行します。
			debug.init();
			config_io.init();
			config_dialog.init();

			// aviutl2ウィンドウを捕捉します。
			catch_aviutl2_window();

			// aviutl2ウィンドウにスリムバーをアタッチします。
			hive.slimbar.subclass(hive.aviutl2_window);

			// コンフィグをファイルから読み込みます。
			config_io.read();

			return TRUE;
		}

		//
		// dllの後始末処理を実行します。
		//
		virtual BOOL dll_exit() override
		{
			MY_TRACE_FUNC("");

			// コンフィグをファイルに書き込みます。
			config_io.write();

			// aviutl2ウィンドウからスリムバーをデタッチします。
			hive.slimbar.unsubclass();

			// 各種終了処理を実行します。
			config_dialog.exit();
			config_io.exit();
			debug.exit();

			return TRUE;
		}
	} app_impl;
}
