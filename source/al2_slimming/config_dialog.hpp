#pragma once

namespace apn::slimming
{
	//
	// このクラスはコンフィグダイアログです。
	//
	inline struct config_dialog_t : my::Dialog, my::lockable_t
	{
		virtual void on_update_controls() {}
		virtual void on_update_config() {}
		virtual void on_init_dialog() {}
		virtual void on_command(UINT code, UINT id, HWND control) {}

		//
		// 初期化処理を実行します。
		//
		BOOL init()
		{
			MY_TRACE_FUNC("");

			{
				// 初期化中にエディットボックスがコマンドを発行してしまうので、
				// それを防ぐためにロックしておきます。
				my::locker_t locker(this);

				if (!__super::create(hive.instance, MAKEINTRESOURCE(idd_config), nullptr))
				{
					hive.message_box(L"コンフィグダイアログの作成に失敗しました");

					return FALSE;
				}
			}

			return TRUE;
		}

		//
		// 後始末処理を実行します。
		//
		BOOL exit()
		{
			MY_TRACE_FUNC("");

			return __super::destroy();
		}

		//
		// コンフィグでコントロールを更新します。
		//
		BOOL to_ui()
		{
			MY_TRACE_FUNC("");

			if (is_locked()) return FALSE;

			my::locker_t locker(this);

			set_check(idc_slimbar_flag_use, hive.slimbar.config.flag_use);
			set_check(idc_slimbar_flag_whole_title, hive.slimbar.config.flag_whole_title);
			set_int(idc_slimbar_button_width, hive.slimbar.config.button_width);
			set_text(idc_slimbar_title_format, hive.slimbar.config.title_format);

			return TRUE;
		}

		//
		// コントロールでコンフィグを更新します。
		//
		BOOL from_ui()
		{
			MY_TRACE_FUNC("");

			if (is_locked()) return FALSE;

			get_check(idc_slimbar_flag_use, hive.slimbar.config.flag_use);
			get_check(idc_slimbar_flag_whole_title, hive.slimbar.config.flag_whole_title);
			get_int(idc_slimbar_button_width, hive.slimbar.config.button_width);
			get_text(idc_slimbar_title_format, hive.slimbar.config.title_format);

			return TRUE;
		}

		//
		// ウィンドウプロシージャです。
		//
		virtual LRESULT on_wnd_proc(HWND hwnd, UINT message, WPARAM w_param, LPARAM l_param) override
		{
			switch (message)
			{
			case WM_CREATE:
				{
					// このウィンドウをプラグインウィンドウに設定します。
					hive.plugin_window = hwnd;

					break;
				}
			case WM_DESTROY:
				{
					break;
				}
			case WM_INITDIALOG:
				{
					// スコープ終了時(デフォルト処理の後)に実行します。
					my::scope_exit scope_exit([&]()
					{
						// 子ウィンドウを列挙します。
						::EnumChildWindows(hwnd, [](HWND child, LPARAM l_param) -> BOOL
						{
							// 子ウィンドウを翻訳します。
							::SetWindowTextW(child, tr(my::get_window_text(child)));

							return TRUE;
						},
						0);
					});

					return __super::on_wnd_proc(hwnd, message, w_param, l_param);
				}
			case WM_COMMAND:
				{
					// ロックされている場合はWM_COMMANDを処理しません。
					if (is_locked()) break;

					auto control_id = LOWORD(w_param);
					auto code = HIWORD(w_param);
					auto control = (HWND)l_param;

					switch (control_id)
					{
					case idc_slimbar_flag_use:
						{
							from_ui();

							hive.slimbar.apply_config();

							break;
						}
					case idc_slimbar_button_width:
					case idc_slimbar_title_format:
						{
							if (code != EN_UPDATE) break;

							[[fallthrough]]; // このまま処理を続けます。
						}
					case idc_slimbar_flag_whole_title:
						{
							from_ui();

							if (!hive.slimbar.config.flag_use) break;

							hive.slimbar.update_layout();

							break;
						}
					}

					break;
				}
			case WM_NOTIFY:
				{
					auto header = (NMHDR*)l_param;
					if (header->code == UDN_DELTAPOS)
					{
						auto nm = (NMUPDOWN*)header;
						auto edit_id = (UINT)header->idFrom - 1;

						switch (edit_id)
						{
						case idc_slimbar_button_width:
							{
								auto value = get_int(edit_id);
								value += (nm->iDelta > 0) ? -10 : +10;
								value = std::clamp(value, 0, +1000);
								set_int(edit_id, value);
								break;
							}
						}
					}

					return FALSE;
				}
			}

			return __super::on_wnd_proc(hwnd, message, w_param, l_param);
		}
	} config_dialog;
}
