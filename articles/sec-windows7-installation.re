#@# -*- coding: utf-8 -*-

={ReviewWin7} Re:VIEWのインストール（Windows7編）

Re:VIEWのインストール方法などを調べると、Dockerを使うのが簡単だと書いてあったりします。
Techboosterさんの書籍やQiitaを調べても、それ以外の方法はあまり出てきません。
かろうじてCygwinを使う方法が出てくるぐらいでしょうか。
WindowsだとそもそもDockerを使えるようにすること自体が大変です。
Cygwinのインストールにも非常に長い時間がかかります。
Windows 10であれば、Windows Subsystem for Linuxを使う方法もありますが、Windows 7ユーザーは
これらの情報からRe:VIEW環境を構築すること自体が大変です。

この章では、Windows 7ユーザーに向けて、比較的簡単なRe:VIEWのインストール方法を紹介します。
Windowsユーザーは、PCにプログラムをインストールする時、インストーラーをインターネットからダウンロードして、
それらを実行してインストーラーの指示に沿って作業していくことに慣れていると思います。
この章で紹介する方法は、たった二つのインストーラーをダウンロードして、Windowsユーザーが慣れたやり方でインストールしていきます。

さて、すでに説明があったように、Re:VIEWはRubyと呼ばれるブログラムを介して原稿を処理します。
そして、PDFを出力する際にTeXと呼ばれる組版ソフトを使っています。
つまり、TeXとRubyとRe:VIEWをインストールする必要があるわけです。

この章では、最初にTeXをインストールして、次にRubyをインストールします。
最後に、Rubyを使ってRe:VIEWをインストールします。
TeXとRubyのどちらを先にインストールしても問題ありませんが、Re:VIEWのインストールにはRubyが必要です。

=={ReviewWin7-Tex} TeXのインストール
TeXと呼ばれるソフトウェアには、実は色々なバリエーションがあります。
オリジナルのTeXに色々な拡張が加えられているからです。
Windowsで使えるTeXとしては、W32TeXやTeX Liveがあります。
ここでは、W32TeXを使った手順を紹介します。
なぜかって？それはこの章の著者が元々W32TeXを使っていたからです:-)。

==={ReviewWin7-TeXDownload} インストーラーのダウンロード
あべのりさんのページ@<fn>{TEX3}から、TeXインストーラ3をダウンロードしましょう。
//footnote[TEX3][@<href>{http://www.math.sci.hokudai.ac.jp/~abenori/soft/abtexinst.html}]
ページ下部に、執筆時点での最新版（0.85r3）へのリンクが張られているので、
リンクをクリックしてzipファイルをダウンロードしましょう。

昔話になりますが、昔はWindowsにTeXをインストールするのは一仕事でした。
このインストーラーが公開されてから、インストールがとても楽になりました。

==={ReviewWin7-TeXInst} インストールの実行
ダウンロードしたらzipファイルを解凍しましょう。
//image[ReviewWin7_texinst_extract][W32TeXインストーラーの解凍][scale=0.75]{
//}
abtexinstフォルダの中にあるabtexinst.exeがインストーラーの本体です。
//image[ReviewWin7_texinst_exe][W32TeXインストーラーの実行ファイル][scale=0.75]{
//}
abtexinst.exeをダブルクリックするとインストーラーが起動するので、順を追ってインストールしていきましょう。
//image[ReviewWin7_texinst_1_start][W32TeXインストーラーの実行画面][scale=0.5]{
//}

[次へ（N）>]ボタンを押すと、TeXをインストールするフォルダや、
TeXをダウンロードするサイトを設定する画面が現れます。
インストール作業をしているPCでインターネットが見られるのであれば、
基本的には何も変更する必要はありません。
もしインストール作業中にファイルがダウンロードできないというエラーが出た場合は、
ここのURLを別のURLに変更してみてください。
//image[ReviewWin7_texinst_2_1_path_org][インストール先とインストール用ファイルのURLの設定][scale=0.5]{
//}
この章の著者は、インストールするフォルダの名前をw32texからTeXに変更しています。
C:\TeX\と書かれている箇所が登場したら、ここを皆さんの設定したフォルダの名前に置き換えながら読んでください。
Windows 7のユーザー設定によっては、Cドライブ直下にフォルダを作れないことがあります。
その場合はインストールするフォルダを変更してください。
//image[ReviewWin7_texinst_2_2_path_changed][本章著者の設定][scale=0.5]{
//}

[次へ（N）>]ボタンを押すと、dviout, Ghostscript, GSviewのインストール設定の画面が現れます。
ここも特に何も変更しなくてもかまいません。
もしインストール作業中にファイルがダウンロードできないというエラーが出た場合は、
これらのURLを別のURLに変更してみてください。
dvioutはTeXを直接編集するときにしか使いません。
GhostscriptやGSviewは図を埋め込むためにTeXから使われるだけなので、
Re:VIEWで原稿を書くのであれば、これらのソフトを立ち上げることはありません。
//image[ReviewWin7_texinst_3_url][dviout, Ghostscript, GSviewのダウンロードURLの設定][scale=0.5]{
//}

[次へ（N）>]ボタンを押すと、TeXWorksの設定をする画面が現れますが、
TeXWorksはインストールしませんので、このまま次へ（N）>を押してください。
//image[ReviewWin7_texinst_4_texwork][その他のソフトのインストール設定][scale=0.5]{
//}

画面が進むと、ダウンロードするファイルを選択する画面が現れます。
これも変更する必要はありません。インストーラーが必要なファイルを見繕ってくれています。
//image[ReviewWin7_texinst_5_confirm][インストールするファイルの一覧][scale=0.5]{
//}

[次へ（N）>]ボタンで先に進むと、TeX以外にインストールするソフトウェアを選択する画面になります。
TeXWorksはインストールしないので、チェックを外して次へ進みましょう。
//image[ReviewWin7_texinst_6_others][その他のソフトのインストール][scale=0.5]{
//}

ファイルのダウンロードが始まります。
速いと5分くらいで全てダウンロードできますが、遅い場合にはしばらくかかる可能性があります。
ダウンロードを待っている間に、この本を読み進めて予習をしておくとよいかもしれません。
全てのファイルが無事ダウンロードされると、TeXのインストールが始まります。
ここまでくると失敗することはないと思います。
//image[ReviewWin7_texinst_7_download][インストール用ファイルのダウンロード][scale=0.5]{
//}
//image[ReviewWin7_texinst_8_progress][インストール進行中][scale=0.5]{
//}

==={ReviewWin7-TexOthers} Ghostscritp, GSview, dvioutのインストール
TeXのインストールが終わるとGhostscriptのインストールが始まります。
[Next>]を押してライセンス条項を読み、同意できるならI agreeを選択し、
[Install]を押すとインストール完了画面が表示されます。
Show Readmeのチェックを外して[Finish]ボタンを押すとGhostscriptのインストールが完了します。
//image[ReviewWin7_gsinst_1_start][インストーラーの起動（Ghostscript）][scale=0.5]{
//}
//image[ReviewWin7_gsinst_2_license][ライセンスの確認（Ghostscript）][scale=0.5]{
//}
//image[ReviewWin7_gsinst_3_path][インストール先の設定（Ghostscript）][scale=0.5]{
//}
//image[ReviewWin7_gsinst_4_finish][インストール完了（Ghostscript）][scale=0.5]{
//}

つづいてGSviewのインストールが始まります。
[Setup]ボタンを押すと、次に言語の選択画面になりますが、日本語はないので[English]を選びます。
以降は特に変更する必要はないので、ひたすら[Next]ボタンを押していきます。
最後に現れる画面で[Finish]を押すとインストールが進み、Instrall successfulとだけ表示された画面が現れたら、
[Exit]ボタン押してインストールを終了します。
//image[ReviewWin7_gsviewinst_1_start][インストーラーの起動（GSView）][scale=0.5]{
//}
//image[ReviewWin7_gsviewinst_2_lang][インストールする言語の選択（GSView）][scale=0.5]{
//}
//image[ReviewWin7_gsviewinst_3_check][確認画面（GSView）][scale=0.5]{
//}
//image[ReviewWin7_gsviewinst_4_license][ライセンスの確認（GSView）][scale=0.5]{
//}
//image[ReviewWin7_gsviewinst_5_pref][ファイル拡張子の関連付け（GSView）][scale=0.5]{
//}
//image[ReviewWin7_gsviewinst_6_path][インストール先の設定（GSView）][scale=0.5]{
//}
//image[ReviewWin7_gsviewinst_7_startmenu][スタートメニューへのフォルダの登録（GSView）][scale=0.5]{
//}
//image[ReviewWin7_gsviewinst_8_finish][インストール完了（GSView）][scale=0.5]{
//}

最後にdvioutのインストールをしますが、これは現れた画面でインストールするフォルダを指定して[OK]を押すだけです。
通常は表示されているフォルダから変更する必要はありません。
//image[ReviewWin7_dvioutinst][インストーラーの起動（dviout）][scale=0.5]{
//}

全てのインストールが完了すると、TeXのインストーラーの画面に戻ってきます。
完了ボタンを押すと再起動するか問われるので、再起動しましょう。
プログラムをインストールしてPCを再起動している間、
次にPCが起動するとプログラムが使えるようになっているんだと思うとワクワクしませんか？
この時間がWindowsを使う醍醐味だと思うのです。
//image[ReviewWin7_texinst_9_finish][インストール完了画面][scale=0.5]{
//}
//image[ReviewWin7_texinst_10_reboot][Windowsの再起動][scale=0.5]{
//}

==={ReviewWin7-TeXConfirm} 動作確認
PCが起動したら、TeXが使えるようになっているか確認しましょう。
TeXをインストールしたフォルダ（C:\TeX、皆さんがフォルダを変更していればそのフォルダ）を開き、
アドレスバーにcmdと入力してエンターを押すと、コマンドプロンプトが起動します。
//image[ReviewWin7_texinst_11_cmd][コマンドプロンプトの起動][scale=0.5]{
//}
この状態でplatexと打ってエンターを押しみましょう。
//cmd{
> platex
//}
このようなメッセージが表示されればインストール成功です。
//cmd{
This is e-pTeX, Version 3.14159265-p3.7.1-161114-2.6 (sjis) (TeX Live 2016/W32TeX) (preloaded format=platex)
 restricted \write18 enabled.
**
//}
Ctrl+Cを入力してplatexを終了し、右上の[×]ボタンでコマンドプロンプトを終了してください。
実際の画面はこんな感じです。
//image[ReviewWin7_texinst_12_confirm][platexの動作確認][scale=0.9]{
//}

あまり想像したくありませんが、もし、「'platex'は、内部コマンドまたは外部コマンド、操作可能なプログラムまたはバッチ ファイルとして認識されていません。」
と表示されたときは、何かがうまくいっていません。
インストールをやり直すか、パソコンの詳しい人に酒でもおごってみてもらいましょう。

=={ReviewWin7-Ruby} Rubyのインストール
==={ReviewWin7-RubyDownload} インストーラーのダウンロード
無事にTeXがインストールできたら、次にRubyをインストールします。
WindowsにRubyをインストールするなら、RubyInstaller for Windowsが手軽です。
RubyInstallerのサイト@<fn>{RUBYFORWIN}にアクセスして、ページ上部にあるDownloadというリンクをクリックし、
一覧で表示されているインストーラーから一つ選んでダウンロードします。
//footnote[RUBYFORWIN][@<href>{https://rubyinstaller.org}]
この記事を書いているときは、最新版である@<tt>{Ruby 2.4.2-2 (x64)}をダウンロードて利用しました。
//image[ReviewWin7_rubyinst_exe][Rubyのインストーラー][scale=0.6]{
//}
==={ReviewWin7-RubyInst} インストール
ダウンロードしたインストーラーは実行形式（.exeファイル）なので、
ダブルクリックするとインストールが始まります。
ライセンス条項を読んで同意するなら I accept the Licenseを選択してNextボタンを押し、
次の画面でインストールするフォルダの設定を行います。
//image[ReviewWin7_rubyinst_1_license][ライセンスの確認（Ruby）][scale=0.5]{
//}
//image[ReviewWin7_rubyinst_2_path][インストール先の設定（Ruby）][scale=0.5]{
//}
ここでは何も変更せず、Installボタンを押してインストールしました。
インストールの進行に応じてプログレスバーが伸びていきます。
//image[ReviewWin7_rubyinst_3_progress][インストールの進行（Ruby）][scale=0.5]{
//}
インストールが終わると図のような画面に切り替わりますが、
Run 'risk install' ~と書いてあるチェックを外してFinishボタンを押します。
これでRubyのインストールは完了です。
//image[ReviewWin7_rubyinst_4_finish][インストール完了（Ruby）][scale=0.5]{
//}

==={ReviewWin7-RubyConfirm} 動作確認
Rubyはコマンドプロンプトから呼び出します。
スタートメニューからすべてのプログラムを展開し、Ruby 2.4.2 ~と書いてあるフォルダを開き、
Start Command Prompt with Rubyを実行します。
//image[ReviewWin7_rubyinst_5_startmenu][スタートメニューからRubyを起動][scale=0.5]{
//}
//image[ReviewWin7_rubyinst_6_prompt][Rubyが有効なコマンドプロンプト][scale=0.9]{
//}
起動したコマンドプロンプトで、次のコマンドを実行してRubyのバージョンを表示してみましょう。
//cmd{
> ruby -v
//}
次のようにRubyのバージョンが表示@<fn>{RUBYVER}されれば、インストール成功です。
//footnote[RUBYVER][インストールしたバージョンによって表示は変わります。]
//cmd{
ruby 2.4.2p198 (2017-09-14 revision 59899) [x64-mingw32]
//}
実際の画面はこんな感じです。ただし、作業フォルダをD:\Workspaceに移動しました。
//image[ReviewWin7_rubyinst_7_confirm][Rubyのバージョンの確認][scale=0.9]{
//}
このままの勢いでRe:VIEWもインストールしてしまいましょう。

=={ReviewWin7-ReView} Re:VIEWのインストール
Re:VIEWは、Rubyを使ってコマンドからインストールします。
Start Command Prompt with Rubyを開いた状態で次のコマンドを実行します。
//cmd{
> gem install review
//}
図のような画面が表示されて、Re:VIEWがインストールされます。
これだけでインストールは終わりです。
簡単だったでしょ？
//image[ReviewWin7_reviewinst][Re:VIEWのインストール][scale=0.9]{
//}

Re:VIEWの動作確認をしながら、pdfを出力するための手順を説明します。
Re:VIEWの原稿を作成するためには、@<tt>{review-init}を実行します。
//cmd{
> review-init reviewSample
//}
ここでは、reviewSampleという名前の原稿を作成しています。
実行して何も表示されなければ、reviewSampleというフォルダが作られ、
その中に原稿のサンプルが存在します。
//image[ReviewWin7_pdfmake_1_init][Re:VIEWによって作られた原稿のひな型][scale=0.6]{
//}

この原稿からpdfを作りましょう。
pdfを作るには、先ほどのreviewSampleに移動して
//cmd{
> review-pdfmaker config.yml
//}
を実行します。
コマンドプロンプト内でフォルダの移動ができないという方は、
reviewSampleというフォルダを開き、
アドレスバーにcmdと入力してコマンドプロンプトを開き、
起動したコマンドプロンプトで次のコマンドを実行してください。
//cmd{
> C:\Ruby24-x64\bin\setrbvars.cmd
//}
@<tt>{Ruby24-x64}はRubyをインストールしたフォルダなので、適宜読み替えてください。
コマンドプロンプトはファイル名を補完してくれるので、C:\Ruまで入力してTabキーを押すと、C:\Ruby24-x64が候補として表示されます。
そのまま\bを入力してTabキー、\sを入力してTabキーを押すことで、最小のキー入力でコマンドを実行できます。
後は前の説明に沿って@<tt>{review-pdfmaker}を実行してください。
途中までは順調に進んでいきますが、book.dvi->book.pdfとなっている直後に終了し、pdfが作られません@<fn>{FONTERROR}。
//footnote[FONTERROR][もし何事もなくpdfファイルが作られていたら、以降の説明は読み飛ばして次の小節に進んでも問題ありません。]
//image[ReviewWin7_pdfmake_2_progress][review-pdfmakerによる処理の実行画面][scale=0.9]{
//}
//image[ReviewWin7_pdfmake_3_error][pdf作成時のエラーメッセージ][scale=0.9]{
//}

これは、Re:VIEWの原稿がTeX形式に変換されてdviファイルが作られ、それがpdfに変換されるという一連の作業の中で、
dviファイルからpdfファイルに変換する途中で問題が発生しています。
ヒラギノフォントを使おうとして、ヒラギノフォントが存在しないので
エラーが発生しているという状況です。

ヒラギノフォントを買えば解決するかもしれませんが、試していないのでわかりません。
ヒラギノフォントを使わずに、Windowsに最初から用意されているMSゴシックやMS明朝を使うように設定をします。
具体的には、dviをpdfに変換するプログラムのオプションをconfig.ymlに記述します。
config.ymlを開いてdvioptionsを検索してください。
コメントアウトされたTeX関連のオプションの最後にdvioptionsが見つかるはずです。
//list[list_config_yml][config.ymlの設定]{
# LaTeX用のコマンドを指定する
# texcommand: "uplatex"
#
# LaTeXのコマンドに渡すオプションを指定する
# texoptions: null
#
# LaTeX用のdvi変換コマンドを指定する(dvipdfmx)
# dvicommand: "dvipdfmx"
#
# LaTeX用のdvi変換コマンドのオプションを指定する
# dvioptions: "-d 5"
//}
この行をアンコメントして、オプションに
@<tt>{-f msmingoth.map}
を追加します。
//list[list_configW32TeX_yml][dvioptionsの追加]{
# LaTeX用のコマンドを指定する
# texcommand: "uplatex"
#
# LaTeXのコマンドに渡すオプションを指定する
# texoptions: null
#
# LaTeX用のdvi変換コマンドを指定する(dvipdfmx)
# dvicommand: "dvipdfmx"
#
# LaTeX用のdvi変換コマンドのオプションを指定する
dvioptions: "-f msmingoth.map -d 5"
//}
ファイルを上書き保存するのはちょっと待ってください。
これを読んでいるあなたは、同人誌を個人で執筆しますか？
複数人で共同で執筆しますか？
個人で執筆しているのなら、上書き保存をして、もう一度@<tt>{review-pdfmaker}を実行してください。
複数人で共同編執筆している場合、全員Windowsを使っていますか？MacやLinuxを使っている共同執筆者はいませんか？
もしWindows以外のOSを使っている人がいると、このオプションが悪さをする可能性があるので、
上書き保存はせずに名前を付けて新しく保存してください。
この章の著者は@<tt>{config_W32TeX.yml}という名前を使っています。

これでもう一度コマンドプロンプトから@<tt>{review-pdfmaker}を実行しましょう。
新しく名前を付けて@<tt>{config.yml}を保存した人は、そのymlファイルを使ってください。たとえば次のようにして実行します。
//cmd{
> review-pdfmaker config_W32TeX.yml
//}
warningはでますが順調に変換が進んでいきます。
reviewSampleのフォルダにbook.pdfが作られていることが確認できました。
これで無事にWindows 7でRe:VIEWを使い、PDFファイルを作成できるようになりました。
//image[ReviewWin7_pdfmake_4_result][作成されたpdfファイル][scale=0.5]{
//}

まとめると、Windows 7でRe:VIEW環境を構築する手順は次のとおりです。

 1. TeXをインストール
 2. Rubyをインストール
 3. RubyからRe:VIEWをインストール
 4. @<tt>{config.yml}の@<tt>{dvioptions}に@<tt>{-f msmingoth.map}を追加

なお、各ソフトのインストールは一度だけでよいのですが、@<ttb>{config.yml}@<b>{にオプションを追記するのは原稿毎に行う必要があることに注意してください。}

== Visual Studio CodeのRe:VIEW用拡張機能と編集作業
Re:VIEWが使えるようになったので、次は快適な執筆環境を整えましょう。
執筆に使うエディタには、Microsoft社が公開しているVisual Studio Code（以降、VSCode）がよいと思います。
多機能なわりに動作が軽く、しかも無料です。
Re:VIEW用の拡張機能をインストールすると、Re:VIEWの命令をハイライトしてくれたり、VSCode内ででき上がりを見れたりします。
ここでは、VSCodeにRe:VIEW用の拡張機能を導入する方法と、VSCode内からpdfを作る方法を説明します。

==={ReviewWin7-VSCodeExt} Re:VIEW用拡張機能のインストール
拡張機能のインストールは、VSCodeの拡張機能のメニューから行います。
VSCodeのウィンドウ左側を、縦に並んでいるアイコンのうち、四角に切れ込みが入ったような図柄のアイコンが拡張機能です。
（どのようなアイコン化は図を参照してください）
このアイコンをクリックすると、現在インストールされている拡張機能と、拡張機能を検索するためのテキストボックスが表示されます。
メニューバーの表示→拡張機能を選択することでも表示することができます。
検索用のテキストボックスに「review」と入力すると、いくつか候補が表示されます。
そのうちatsushieoさんのRe:VIEW（Re:VIEW language support for Visual Studio Code）をインストールします。
インストールは簡単で、緑色で塗りつぶされているインストールボタンをクリックするだけです。
//image[ReviewWin7_vscode_1_extension][Visual Studio CodeへのRe:VIEW用拡張機能の追加][scale=0.5]{
//}

==={ReviewWin7-VSCodeEdit} VSCodeによる編集作業
Re:VIEW用の拡張機能をインストールできたら、具体的な編集作業の流れを見ていきましょう。
編集するファイル（config.ymlやcatalog.yml, *.re等）を一つずつVSCodeに読み込ませてもよいのですが、
原稿はフォルダにまとまって置かれているので、フォルダをまるごとVSCodeで開き、VSCodeから編集するファイルを拓くことにします。
この方が開くファイルを間違えたりしないので便利です。
ここでは、先ほどRe:VIEWの動作確認に使ったreviewSampleを使い、
編集作業からpdfの出力までを説明します。

ファイル→フォルダーを開くクリックし、開きたいフォルダ（reviewSample）を選択します。
//image[ReviewWin7_vscode_2_openfolder][Visual Studio Codeにフォルダを追加するメニュー][scale=0.7]{
//}
//image[ReviewWin7_vscode_3_selectfolder][フォルダの選択][scale=0.7]{
//}
すると、VSCodeのエクスプローラー（ウィンドウ左、縦に並んでいるアイコンの一つ目）にフォルダが表示され、
中に置かれているファイルやフォルダが一覧で表示されます。
ここに見えているファイル名をシングルクリックすると、そのファイルがVSCodeに読み込まれ、編集できるようになります。
//image[ReviewWin7_vscode_4_workspace][Visual Studio Codeに読み込まれたフォルダとファイル][scale=0.7]{
//}

reviewSample.reをクリックして開き、編集をします。
テストという名前の章を一つ設けてみました。
//image[ReviewWin7_vscode_5_edit][Visual Studio Codeでのファイル編集画面][scale=0.9]{
//}
そして、ここからがVSCodeの便利なところで、
ウィンドウ右上にあるShow previewをクリックするとウィンドウが分割され、右に仕上がりが表示されるのです。
もしRe:VIEWの命令に何か間違いがあると、仕上がりが表示されなくなり、
原稿の間違っている箇所を赤の下線で指摘してくれます。
//image[ReviewWin7_vscode_6_preview][ファイルのプレビュー][scale=0.9]{
//}

間違いもないのでreview-pdfmakerを使ってpdfを出力しましょう。
いちいちスタートメニューからコマンドプロンプトを立ち上げなくても、
表示→統合ターミナルをクリックするとウィンドウ下部にコマンドプロンプトが表示されます。
//image[ReviewWin7_vscode_7_runterminal][ターミナルの起動][scale=0.7]{
//}
//image[ReviewWin7_vscode_8_terminal][ターミナルでのRubyの有効化][scale=0.7]{
//}

先ほどの説明と同じように、Rubyを使えるようにコマンドを実行します。
//cmd{
> C:\Ruby24-x64\bin\setrbvars.cmd
//}

その後、review-pdfmakerを実行してpdfファイルを作ります。
コマンドは次のように実行するのでしたね。
//footnote[VSCODEREVIEW][先ほどはconfig_W32TeX.ymlを使っていましたが、より一般的な説明のためにconfig.ymlを使っています。先の説明に沿ってdvioptionsが追記されています。]
//cmd{
> review-pdfmaker config.yml
//}
//image[ReviewWin7_vscode_10_pdfmaker][Re:VIEWによるpdfファイルの作成][scale=0.7]{
//}

エラーが発生しなければbook.pdfが作られます。
これも実はコマンドプロンプトから開くことができて、ファイル名を入力するとそのファイルが開かれます。
//cmd{
> book.pdf
//}

この章の著者の環境では、AdobeのAcrobatが起動し、book.pdfが表示されます。
pdfファイルを表示したままにしておくと、次にRe:VIEWでpdfファイルを作成するときに
pdfファイルを上書きできなくなるので、編集作業に戻る、あるいはpdfファイルを作成するタイミングで開かれているpdfファイルを閉じるようにしましょう。
残念ながら、VSCodeでpdfファイルを開こうとすると、サポートされていないというメッセージが表示されます。

=={ReviewWin7_summary} この章のまとめ
この章では、Windows 7でRe:VIEW環境を構築して、Visual Studio Codeで編集してpdfを出力するところまで説明しました。
事前に情報を集めてめんどくさいなぁと思っていた方は、意外に簡単で拍子抜けしたのではないかと思います。
締切（とストレージ）の都合上、TeX Liveを試せなかったのは残念ですが、問題なく使えるのではないかと予想しています。
もし、本書をお読みになった方で知見をお持ちの方は、ぜひ本書の改訂版を一緒に作りましょう！

====[column] Windows 7にRe:VIEW環境を構築するたった四つの方法 @ 暗黙の型宣言

Windows 7にRe:VIEW環境を構築する方法が（実は）たくさんあり、この手順を見つけるまでには紆余曲折がありました@<fn>{WIN10ENV}。
//footnote[WIN10ENV][Windows 10の場合は、Linux Subsystem on Windowsが利用できるので、Dockerを簡単に利用できます。]
私が試したのは次の４通りです。

 1. インターネット上の説明に沿ってDocker for Windowsを使う方法。この方法は、仮想化環境を動かすためのVirtualBoxがVMWareと相性が悪いので使えませんでした。
 2. VMWareにLinuxをインストールしてそこにRe:VIEW環境を構築する方法。この方法は簡単に成功しましたが、執筆作業がWindowsとLinuxにまたがってしまうのでやり取りが億劫でした。また、仮想OSのために30GBほど消費しますし、ノートPCではバッテリーの消費が多くなり、出先で執筆ができません。
 3. CygwinにRe:VIEWをインストールする方法。この方法では、Cygwin自体がかなり容量を消費しますし、ファイルパスの設定が非常にややこしいことになります。
 4. Windows版のTeXとRubyをインストールしてターミナルから使う方法。この方法は情報がありませんでしたが、やってみるとうまくいきました。
 
Windows版のTeXとRubyを使う方法は情報が見つからなかったので、何か根本的な問題があるのかと考えていましたが、
Ruby for Windowsをインストールして、gemでRe:VIEWがインストールできた段階で現実味を帯びてきました。
途中、ヒラギノフォントを読みにいくエラーを回避できなくて詰まりましたが、dvioptionsを見つけてエラーを回避できました。
やってみるものですね。

このような試行錯誤を楽しむことができるなら別ですが、技術書を書くためにRe:VIEWを使おうとする人全員にそのような試行錯誤を要求するのは酷というものでしょう。
そのために本書があるわけですから、本書を読んだ方（この章では特にWindows 7ユーザー）が環境構築に詰まることなく、
技術書執筆に集中できるようになれば、それに勝る喜びはありません。

====[/column]

====[column] Re:view on Windowsを早々に諦めた話：親方

私は、様々な記事等でWindows上でRe:view環境構築が大変である記述をみて早々に諦め、本書の担当範囲をテキストエディタ（Terapad）で書くことにしました。werckerによりオンラインコンパイルができるため、（多少待ち時間があったり、バージョン断片が増える問題はありますが）ローカル環境を作る必要がないためです。そして、バージョン管理がしっかりできるGit上で共同執筆したからこそ本書およびテキストエディタ1本での執筆ができたと言っても過言ではないのです。

====[/column]
