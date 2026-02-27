#pragma once

namespace apn::slimming
{
	//
	// このクラスはコンフィグダイアログです。
	//
	inline struct config_dialog_t : config_dialog_base_t
	{
		//
		// コンフィグでコントロールを更新します。
		//
		virtual BOOL on_to_ui() override
		{
			MY_TRACE_FUNC("");

			set_check(idc_slimbar_flag_use, hive.slimbar.config.flag_use);
			set_check(idc_slimbar_flag_whole_title, hive.slimbar.config.flag_whole_title);
			set_int(idc_slimbar_button_width, hive.slimbar.config.button_width);
			set_text(idc_slimbar_title_format, hive.slimbar.config.title_format);

			return TRUE;
		}

		//
		// コントロールでコンフィグを更新します。
		//
		virtual BOOL on_from_ui() override
		{
			MY_TRACE_FUNC("");

			get_check(idc_slimbar_flag_use, hive.slimbar.config.flag_use);
			get_check(idc_slimbar_flag_whole_title, hive.slimbar.config.flag_whole_title);
			get_int(idc_slimbar_button_width, hive.slimbar.config.button_width);
			get_text(idc_slimbar_title_format, hive.slimbar.config.title_format);

			return TRUE;
		}

		//
		// WM_COMMANDを処理します。
		//
		virtual void on_command(UINT code, UINT control_id, HWND control) override
		{
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
		}

		//
		// WM_NOTIFYを処理します。
		//
		virtual void on_notify(NMHDR* nmhdr) override
		{
			switch(nmhdr->code)
			{
			case UDN_DELTAPOS:
				{
					auto nm = (NMUPDOWN*)nmhdr;
					auto edit_id = (UINT)nmhdr->idFrom - 1;

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

					break;
				}
			}
		}
	} config_dialog;
}
