= この本の執筆環境について

じつは本書はGithubで全て公開されています。@<href>{https://github.com/onestop-techbook/c93-onestop-techbook}というリポジトリが、本書のソースコードなのです。環境を整えれば、本書のPDFやepubを生成できるのです。

  * Github
  * Re:View
  * Docker
  * wercker（CI）

この本ではGithubとRe:Viewを主軸として執筆しています。エンジニアに馴染みやすく多人数での執筆に向いています@<fn>{solo}。技術書典で出展されている同人誌ではよく見られる構成です。まずは執筆環境の概要を説明します。
//footnote[solo][もちろん個人の執筆にも向いています。]

== 概要説明

まずはそれぞれの概要をみていきましょう。

=== git / Github

gitはエンジニアがもっともよく使っているバージョン管理ツールです。Linux の作者 Linus 氏が、Linux の開発に耐える大規模バージョン管理ツールが無いことにブチ切れて開発したものです。git より以前は Subversion というソフトがよく使われていましたが、圧倒的に git の方が使い勝手がよくあっという間に普及しました。

git さっぱりわからないという人は、わかばちゃんと学ぶ Git使い方入門@<fn>{wakaba}をオススメしておきます。
//footnote[wakaba][@<href>{https://www.amazon.co.jp/dp/B071D4D6XX/}]

バージョン管理ツールというのは、おおざっぱにいうとソースコードをタイムマシン的にバックアップして管理するものです。これを履歴といいますが、gitでは履歴の差分を省スペースで保持する仕組みなので、容量を気にせずソースコードの履歴を残せます。

====[column] ファイル管理をシステム化する利点

@<tt>{スケジュール.backup.バージョン1.最新版.old.txt}のようなファイルを見かけたことはありませんか？ファイルをコピーしてファイル名で履歴管理しようとする陥る罠です。どれが最新なのかわからないという問題があります。解決方法として@<tt>{スケジュール.2017-11-11.txt}という命名ルールで縛ろうとしてみます。この場合更新頻度が一日一回におさまればいいですが、同じ日に更新しようとした場合さらにルールが必要になります。たとえば@<tt>{スケジュール.2017-11-11.01.txt}でしょう。ですが、同時に別々の人が更新しようとした場合にはどうなるでしょうか？それに、いちいち人間が手で日付いじるの面倒じゃないですか？

そこでバージョン管理ツールです。たとえばgitでやるのならば、gitに@<tt>{スケジュール.txt}を登録するだけです。コミットという作業をするだけで勝手にソースコード貯蔵庫（リポジトリ）に保管されます。いつの時点の@<tt>{スケジュール.txt}も探し出せます。ログ参照・グラフ参照・検索などさまざまな方法で楽かつ高速で探し出せます。

ファイル名で管理するという原始的なことをする時代ではなくなったのです。

====[/column]

そして Github@<fn>{github} は git を活用した世界最大のソースコード SNS で、エンジニアにとっては名刺代わりといってもいいものです。エンジニアにとっての文化的標準でもあります。たとえば、Markdown と呼ばれる文章の簡易記法は、Github の Markdown（Github Fravored Markdown）が事実上の標準となっていますし、git がエンジニアの標準になったのも、Github の存在がとても大きいのです。
//footnote[github][@<href>{https://github.com/}]

Github は多人数でソースコードを同時開発するのにとても向いている便利なサービスです。別にソースコードといってもプログラミングに限定する必要はありません。本の原稿もソースコードです。そのソースコードを Github に預けるのです。自分の PC が吹っ飛んでも Github にソースコードを置いてる限り悲嘆する必要はありません@<fn>{local-commit}。
//footnote[local-commit][ローカルでの変更点を Github に送ってないときは、もちろん悲しいことになります]

====[column] SNS としての Github

SNS といえば Twitter や Facebook が有名ですが、Github もコミュニケーション機能が豊富です。

issue（イシュー）はそのプロジェクトにおける問題を話合う掲示板のようなものです。issue はよほどのことが無い限り誰でも書けます。ソフトウェアに対するバグ報告・質問が寄せられたり、チーム内での設計議論なんかも行われています。

Pull-Request（PR / プルリク）は Github の一番の特徴ともいえるものです。ある有名な OSS@<fn>{OSS} のプロジェクトがあったとして、あなたがバグを見つけたとします。このとき issue で報告するのも手ですが、あなた自身がバグを直してそれが反映されれば手っ取り早くありませんか？それをするのがプルリクです。いきなりプルリク単体を投げると困惑されるかもしれないので、issue で問題提起しつつ、「ハハハ、こんなバグがあったから直したぜ」と言って一緒にプルリクも投げれば、きっとあなたはヒーローになれるでしょう。
//footnote[OSS][オープンソースソフトウェアの略で、誰でも自由にソースコードを読んだり改変できるソフトウェアです。OSSの登場によって、ソフトウェア開発の世界は一気に書き換わりました。]

他にもプロジェクト用の Wiki や進捗管理ツールなども内包していて、エンジニアにとって Github は手放せないのです。

====[/column]

=== Docker

Docker は、ミニマムなLinux実行環境をコンテナという独立した空間に閉じ込めて実行するものです。Docker について詳しく語り出すとインフラの本一冊書けるので詳しくは説明しませんが、Dockerfile というファイルさえ用意しておけば、Windows でも Mac でも Linux でも、同じ Linux コンテナが動きます。そして幸いなことに Re:VIEW 関連全てインストールされた Dockerfile が公開されているので、それを使うだけで構いません。

=== wercker

Re:VIEW で書かれた原稿は PDF や epub などの形式として出力（コンパイル）しないと本にはなりません。インストールさえちゃんとしていれば Re:VIEW のコンパイルは簡単ですが、チームで執筆する場合、それぞれの人の環境に左右されずにコンパイルできる方が楽です。とくにそれは自動化しておきたいものです。Github に登録された原稿が自動でコンパイルされて PDF などに変換されていれば最高じゃないですか。しかもデータの出力だけじゃありません。自動で校正するツールもあります。そういったツールで「この原稿ちょっとマズいんでは？」という指摘を全自動で出すことも簡単です。

自動でコンパイルをするという願いを叶えてくれるのが CI（Continuous Integration@<fn>{CI}）といい、Github と連動してくれる CI のサービスが何種類かあります。自前でサーバーを立てる必要はありません。ユーザー登録して、簡単な設定をするだけです。最近はリポジトリに設定ファイルを1つ追加して、Github 連動の設定をするだけというお手軽な CI サービスが主流です。

さて、今回説明するのは wercker@<fn>{wercker} というサービスです。このサービス元々スタートアップとしてはじまったもので、後に Oracle@<fn>{Oracle} 社に買収されました。経営している会社はともかくとして、wercker は使いやすさ、設定の簡単さが売りです。他の CI サービスではオレオレルールを理解しないと使えないものもありますが、wercker では Docker さえ理解していればほとんどオレオレルールを意識する必要はありません。
//footnote[CI][日本語では継続的インテグレーションといい、自動でコンパイルやユニットテストを走らせるもので、エンジニアの生産性を支えるものです。このジャンルでは Jenkins が有名ですが GUI で設定しなければいけない Jenkins は最近では敬遠される傾向があります。]
//footnote[wercker][@<href>{http://www.wercker.com/}]
//footnote[Oracle][オラクルと聞くとついつい身構える人もいるかもしれませんが、wercker はとてもよいサービスです。]

CI サービスはどれを選んでも構いませんが、Docker 対応しているサービスが一番望ましいです。さきほども軽く説明したとおり、Re:VIEW の環境整備は Docker があれば簡単なためです。

@<href>{https://app.wercker.com/onestop-techbook/c93-onestop-techbook/runs}は実際に筆者がセットアップしたwerckerの結果表示ページです。

== 環境整備

Re:VIEWを手元で動かすには最低限Rubyが必要になります。そして PDF を出力する場合は LaTeX も必要になります。Mac や Linux だとそれなりにノウハウも多くある程度楽ですが、Windows で環境を整える場合はかなり面倒です。Windows10 の Windows Subsystem for Linux を使えると大分マシです。ただ、どの環境にせよ、LaTeX はとにかく色々と面倒です。Docker を使わずに自前で環境構築をするなら、かなりの調査と研究が必要になるでしょう。

  * Rubyをインストールする（Re:VIEWがRubyで作られているため）
  * PDF変換をするために LaTeX をインストールする

また、本書のリポジトリではJavaScriptが使われているためNode.jsがあるといいでしょう。

=== Dockerをインストールする

Docker for Windows@<fn>{docker-for-windows} や Docker for Mac@<fn>{docker-for-mac}を使うのが手っ取り早いでしょう。
//footnote[docker-for-windows][@<href>{https://www.docker.com/docker-windows}]
//footnote[docker-for-mac][@<href>{https://www.docker.com/docker-mac}]

=== Dockerで動かす

//cmd{
$ docker run --rm -v `pwd`:/work vvakame/review /bin/sh -c "cd /work/articles ; review-pdfmaker config.yml"
//}

@<tt>{/work/articles} という指定はこの本でのディレクトリ構成の物です。

たったこれだけです。なんと簡単なことでしょうか。

=== Macで環境を構築する

基本的にはHomebrew@<fn>{Homebrew}とbrewcaskを活用するといいでしょう。
//footnote[Homebrew][@<href>{https://brew.sh/index_ja.html}]
//footnote[brewcask][@<href>{https://caskroom.github.io/}]

//cmd{
$ brew cask install mactex
//}

あとはRubyは好きな方法でインストールしておくといいでしょう。システムにすでに入っているものを使う、Homebrewでインストールする、rbenvを使う、anyenv+rbenvを使うなどの手段があります。
//footnote[rbenv][@<href>{https://github.com/rbenv/rbenv}]
//footnote[anyenv+rbenv][@<href>{https://github.com/riywo/anyenv}]

=== Windows Subsystem for Linux （Windows10）で環境を構築する

#@# 自分でも実験してみるつもりだけど、誰か書ける人かいてくれると嬉しい by @erukiti

=== Windows で環境を構築する

TeXのインストールには、TeXLive@<fn>{TeXLive}を使うのが最近の鉄板のようです。
//footnote[TeXLive][@<href>{https://user.ecc.u-tokyo.ac.jp/users/user-15826/wiki/?TeX/Install}]

Rubyのインストールには、RubyInstaller@<fn>{ruby-installer2}を使うといいようです。
//footnote[ruby-installer2][@<href>{https://github.com/oneclick/rubyinstaller2/releases}]

Windows 7にTeX（W32TeX）とRubyを使ってRe:VIEW環境を構築する方法を@<chap>{sec-windows7-installation}にまとめています。

====[column] 技術書はWordでも書ける　：親方

本書はRe:View＋Githubで並行執筆という環境を構築しており、環境構築手順から記事になっているため、それがベスト解とおすすめしていると思われるかもしれません。確かに、差分管理や原稿出力などにおいて素晴らしい面も多々あり、是非オススメしたい環境ではあるのですが、一方で一から環境設定をすることにハードルを感じることがあるかもしれません。

結論から言ってしまえば、Wordでも普通に本は書けるので、環境構築で挫折しそうになるくらいなら、とっととWordで書いてしまいましょう。WordはWordで癖があるソフトですが、業務用PC、あるいは家庭用PCにもほぼ標準的にインストールされていることもあり、一度も使ったことがないという人はかなりまれかと思います。ということは、とっかかりの操作方法に悩む必要がないソフトだといえます。また、比較的編集中の見た目と印刷結果が近いので、直感的な執筆には向きます。TeXとか、InDesignとかはお作法がかなり厳しかったり、操作を覚えてまともに書けるようになるまでが結構たいへんです。

書き始めるためのハードルはできるだけ下げて、とにかく最初の本を書き上げることを優先すべきで、その上でWordがクソだとおもったら、他の環境を試せばよいのです。いきなり使ったことないツールを使い始めて、そのツールの使い方習得に忙殺され、本が完成しないというのは本末転倒です。執筆ツールはあくまで執筆ツールです。

====[/column]
