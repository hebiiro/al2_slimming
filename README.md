# 🎉AviUtl2スリム化MOD

* aviutl2ウィンドウのタイトルバーとメニューバーを一体化してスリム化します。
* aviutl2の汎用プラグインの形式になっていますが、実際には見た目を変えるタイプのMODです。

!["AviUtl2スリム化MOD"](images/r1.png)

## 🚧注意事項

* `データフォルダ`とは`C:\ProgramData\aviutl2`または`aviutl2.exeがあるフォルダ\data`のことです。
* `プラグインフォルダ`とは`データフォルダ\Plugin`のことです。

> [!IMPORTANT]
> * aviutl2 beta30以降でのみ動作します。
> * `ダークモード化MOD`と干渉してしまうので、以下の操作をしてください。
>	* `ダークモード化MOD`の`スリムバーを使用`のチェックを外してください。

## 🚀インストール

* `プラグインフォルダ`に以下のファイルを入れてください。
	* `al2` ✏️フォルダ
		* `al2_slimming.aux2` ✏️汎用プラグインファイル
* (上記ファイルは`al2_slimming.au2pkg.zip`ファイル内の`Plugin`フォルダに入っています)
---
* または、`al2_slimming.au2pkg.zip`ファイルをaviutl2のプレビュー画面にD&Dしてください。
* このとき「`al2`フォルダが使用中です」のようなダイアログが表示された場合は「スキップ」を選択してください。

## 🔥アンインストール

* `プラグインフォルダ`から以下のファイルを削除してください。
	* `al2` ✏️フォルダ
		* `al2_slimming.aux2` ✏️このファイルを削除
		* `config` ✏️フォルダ
			* `al2_slimming.json` ✏️このファイルを削除

## 🔧設定

* `スリム化MOD`ウィンドウで設定します。
---
* `スリムバーを使用`✏️チェックを入れるとタイトルバーとメニューバーが一体化(スリムバー化)します。
* `タイトルを全体中央に描画`
	* ✏️チェックを入れるとスリムバーの中央にタイトルが描画されます。
	* ✏️チェックを入れてない場合はスリムバーの空きスペースの中央にタイトルが描画されます。
* `ボタンの幅(%)`✏️スリムバーのボタンの幅を高さを基準に%単位で指定します。
* `タイトルの書式`✏️スリムバーのタイトルの書式を指定します。
	* `%title%`は元のタイトル名に置換されます。

## 🔖更新履歴

* 🔖r1 #2026年01月28日
	* 🎉初版

## ⚗️動作確認

* AviUtl ExEdit2 beta30a https://spring-fragrance.mints.ne.jp/aviutl/

## 💳クレジット

* AviUtl ExEdit2 Plugin SDK https://spring-fragrance.mints.ne.jp/aviutl/
* Microsoft Research Detours Package https://github.com/microsoft/Detours
* JSON for Modern C++ https://github.com/nlohmann/json
* win32-custom-menubar-aero-theme https://github.com/adzm/win32-custom-menubar-aero-theme

## 👽️作成者情報
 
* 作成者 - 蛇色 (へびいろ)
* GitHub - https://github.com/hebiiro
* X - https://x.com/io_hebiiro

## 🚨免責事項

この作成物および同梱物を使用したことによって生じたすべての障害・損害・不具合等に関しては、私と私の関係者および私の所属するいかなる団体・組織とも、一切の責任を負いません。各自の責任においてご使用ください。
