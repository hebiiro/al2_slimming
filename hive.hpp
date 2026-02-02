#pragma once

namespace apn::slimming
{
	//
	// このクラスは他クラスから共通して使用される変数を保持します。
	//
	inline struct hive_t : hive_base_t
	{
		//
		// スリムバー(を持つウィンドウ)です。
		//
		my::slimbar_t slimbar;
	} hive;
}
