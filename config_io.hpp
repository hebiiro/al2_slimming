#pragma once

namespace apn::slimming
{
	//
	// このクラスはコンフィグの入出力を担当します。
	//
	inline struct config_io_t : json_config_io_t
	{
		//
		// 更新処理を実行します。
		//
		BOOL update()
		{
			MY_TRACE_FUNC("");

			config_dialog.to_ui();

			return hive.slimbar.apply_config();
		}

		//
		// ノードからコンフィグを読み込みます。
		//
		virtual BOOL read_node(n_json& root) override
		{
			MY_TRACE_FUNC("");

			read_bool(root, "slimbar.flag_use", hive.slimbar.config.flag_use);
			read_bool(root, "slimbar.flag_whole_title", hive.slimbar.config.flag_whole_title);
			read_string(root, "slimbar.title_format", hive.slimbar.config.title_format);
			read_int(root, "slimbar.button_width", hive.slimbar.config.button_width);

			return TRUE;
		}

		//
		// ノードにコンフィグを書き込みます。
		//
		virtual BOOL write_node(n_json& root) override
		{
			MY_TRACE_FUNC("");

			write_bool(root, "slimbar.flag_use", hive.slimbar.config.flag_use);
			write_bool(root, "slimbar.flag_whole_title", hive.slimbar.config.flag_whole_title);
			write_string(root, "slimbar.title_format", hive.slimbar.config.title_format);
			write_int(root, "slimbar.button_width", hive.slimbar.config.button_width);

			return TRUE;
		}
	} config_io;
}
