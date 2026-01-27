#pragma once

namespace apn::slimming
{
	//
	// このクラスはコンフィグの入出力を担当します。
	//
	inline struct config_io_t : my::json_io_t<hive>
	{
		//
		// 初期化処理を実行します。
		//
		BOOL init()
		{
			MY_TRACE_FUNC("");

			auto module_file_path = my::get_module_file_name(hive.instance);
			auto config_folder_path = module_file_path.parent_path() / L"config";

			path = hive.config_file_name = config_folder_path /
				module_file_path.filename().replace_extension(L".json");
			MY_TRACE_STR(hive.config_file_name);

			// コンフィグフォルダを作成しておきます。
			try { std::filesystem::create_directories(config_folder_path); } catch (...) {}

			return TRUE;
		}

		//
		// 後始末処理を実行します。
		//
		BOOL exit()
		{
			MY_TRACE_FUNC("");

			return TRUE;
		}

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
