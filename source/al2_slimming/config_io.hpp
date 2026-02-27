#pragma once

namespace apn::slimming
{
	//
	// このクラスはコンフィグの入出力を担当します。
	//
	inline struct config_io_t : config_io_base2_t
	{
		//
		// 更新処理を実行します。
		//
		virtual BOOL update() override
		{
			MY_TRACE_FUNC("");

			// スコープ終了時に実行します。
			my::scope_exit scope_exit([]() {
				return hive.slimbar.apply_config();
			});

			return __super::update();
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

			return __super::read_node(root);
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

			return __super::write_node(root);
		}
	} config_io;
}
