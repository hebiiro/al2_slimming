#pragma once

namespace apn::slimming
{
	//
	// このクラスはこのプログラムのバージョンを管理します。
	//
	inline struct version_t : version_base_t {
		//
		// コンストラクタです。
		//
		version_t() : version_base_t(L"スリム化MOD", L"🐍スリム化MOD🔖", L"r1") {}
	} version;
}
