##Chapter 5
###10/21
配列・構造体を詳しく。その他種種の概念

- 5.1, 5.2 配列
- 5.3-5.5 構造体 struct
- 5.6 列挙 enum
- 5.7 条件演算子 ?:
- 5.8 デフォルト変数	
- 5.9 静的ローカル変数
- 5.10 変数の寿命とスコープ
- 5.11 リンケージ
- 5.12 分割コンパイル
- 5.13 文字列リテラル
- 5.14 エスケープリンケージ
- 5.15-17 new & delete

### 5.1, 5.2 配列
- 配列の配列を作るときは[]の数を増やせばよい
- 配列の配列は指数乗にメモリが増えるので注意
-　int n[3][5]　で n[1] とすると &n[1][0] と同義
- 配列を宣言するときにはじめの部分だけは省略できる
```
n[][] = {
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
};
```
はビルドエラー
```
n[][5] = {
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
};
```
はきちんと機能する。

### 5.3-5.5 構造体 struct - 構造体の宣言の書式は ```struct タグ名　{変数宣言郡};``` -
構造体を使うことで関連のある変数をひとまとめに扱える - 構造体の宣言は**型宣言**である - 構造体の各変数はメンバという -
メモリ上にある変数を実体（2インスタンス）と、構造体変数のことをオブジェクトとも言う。 -
メンバを使うときは```object.member```.これで操作ができる。

- オブジェクトの初期化子は{}で囲む
- 構造体は主に**参照渡し**
- ポインタでメンバにアクセスすることも可能 ```->```を使う

### 5.6 列挙 enum
- ```enum 型{名前　= 値, 名前 = 値, ... ,};```で列挙
- 列挙体変数へは列挙体系の値しか代入できない
- enumの中身は必ず最後でも, を付ける
- 列挙子は整数定数としても利用できる(true = 1, false = 0 みたいなもの)
- 列挙子は初期値が前の数+1
- 一番初めの列挙子は初期値0
- 列挙体変数の値の保障は自分で持つこと
-　enum型でキャストするとどんな値でも扱える。これは致命的な穴らしい。**(が、実際なんで穴なのかよくわからん)**
- enum型はフラグを宣言するときによく使う。フラグとは、状態や設定を表す値
- 列挙体にはコンマを付けてはいけない。

### 5.7 条件演算子 ?:
- conditional operator ?
- ```条件式? 真の場合:偽の場合```
- ```(a>b ? a:b)``` a>bが真の場合はa,偽の場合はbを返す

### 5.8 デフォルト変数	
-　仮引数を初期化するような形にすると省略したときその値が使われる
-　これをデフォルト引数という
-　途中の引数だけを省略することはできない
- デフォルト引数には性的なデータしか指定できない
- オーバーロードとデフォルト引数を併用するときは、呼び出しが区別できるかどうかに注意する
```
sum(int a, int b, int def = 1){
	return a+b+def
}
```
みたいな設定ができる。


### 5.9 静的ローカル変数
- staticを付けることでローカル変数が静的に
- staticのついていない変数は**自動変数**という。
- 自動変数のアドレスを返すような関数はつくっちゃだめ！
- 静的変数の初期化は1度のみ
- 宣言しなければ初期化の値は0
- 静的関数は関数を抜けても値が保存される
- global変数は静的関数

###10/22

###　5.10 変数の寿命とスコープ
- 変数の有効期間を寿命という
- {}で囲んだ全体をブロックという
- 変数や関数の見える範囲をscopeという
- 変数の寿命はスコープによって決まる
- スコープが違えば同じ名前の別の変数を作ることができる
- ::を付ければどのスコープからでもグローバル変数をさせる

### 5.11 リンケージ
## いまいちメリットがわからなかった。。。

- ファイルを超えて利用できるかどうかをリンケージという
-　ファイルの外部でも利用できるのが外部リンケージ，内部でしか利用できないのを内部リンケージ
-　関数に外部リンケージを持たせるには戻り値にexterm
-　グローバル変数の場合も普通に変数を定義すれば外部でも使える
- externの変数宣言を行うと別の場所で定義された**外部リンケージのグローバル変数**を扱うという宣言になる
- staticなしの**関数プロトタイプを**書くと、別の場所で定義された**外部リンケージの関数を扱う**という宣言になる
- staticを付けると**内部リンケージ**
- 外部リンケージのグローバル変数はどこでも書き換えができるので、作らないほうがいい！
-　内部リンケージのグローバル変数はその変数を含むひとつのファイル中心に調べればいいのでまだまし。

---

### 5.12 分割コンパイル
- ファイルを新規作成すればそれだけで複数ソースになる
- あるソースファイルで作った関数を公開したいときはヘッダファイルにする
- ```const　定数```は内部リンケージを持つ（外部に反映されない？？）
- ヘッダファイルには必ず二重インクルード防止コードを書く
	- 同じヘッダファイルを二回インクルードすると起こる
	- ```#ifndef```,```#define```,```#endif```などを使う（前処理命令）
	- ```#```が前につくと、コンパイルより**前**に処理を行う。
	- ```#define```はマクロというものを定義する
	###**マクロってなんだ？**
```
#ifndef REDEF1_MACRO //マクロ名をかくらしい
#define REDEF1_MACRO

const int N = 10;

#endif 

```

- main関数はひとつ
- 個別にコンパイルしたものをオブジェクトファイルという
	- ```gcc -c hogehoge.cpp```とかくと、オブジェクトファイルを生成する
- 実行ファイルは複数のオブジェクトファイルをリンクしてつくる。
- ヘッダファイルに関数プロとタイプやexternつきの変数宣言を書いておいて、includeする

### 5.13 文字列リテラル
- ```""```で囲まれた文字列を**文字列リテラル**という。
- 文字列リテラルはその**アドレスを返す**
- 文字列リテラルは**静的**、破棄されない。書き換えてはだめ
	- 文字列リテラルのアドレスを受けるポインタは必ず```const```
	- 毎回初期化するのももったいないので```static```をつけることも多い
	- ``` static const char* const str[] = {"a","b","c"};```など
- ポインタを文字列リテラルで初期化すると、文字列リテラルへのアドレスで初期化される
- 配列を文字列リテラルで初期化すると、その配列が文字列リテラルの内容で初期化される


```
//配列の配列の構造をしている。この場合、箱の大きさを省略できる配列は
//一番初めの配列要素だけなので、エラーになっちゃう	
//エラーをクリアするためには2番目の値を入れる必要があるが、
//文字数とか数えるのめちょめんどくさい
static	const char message[][] = {
	"former is less than later",
	"former is equal to later",
	"former is more than later"
};
//アドレスを使うと、アドレスは変数なので文字数を入力する必要がなくなる
//つまり、配列の要素は省略できる！
static	const char* message[] = {
	"former is less than later",
	"former is equal to later",
	"former is more than later"
};

```
### 5.14 エスケープリンケージ
- \から始まる特殊な文字表記をエスケープシーケンスという
- エスケープシーケンスを使うと特殊な文字の文字コードや数値を表現できる
	-　ロベールP254に一例が載っている。
- エスケープシーケンスはソースファイル上でのみ必要。コンパイル後は文字コードに変換される

### 5.15-17 new & delete
- ```new```を使うことでメモリを動的に確保できる
- 結果は**型**へのポインタで受ける
```
int* p = new int;
//↑整数値を受ける 
```
- 使い終わったら必ず```delete アドレス```でメモリを開放する
- newに失敗すると例外が発生する
- メモリの確保が失敗する可能性を無視してはいけない
- 配列の動的確保はnew 型[要素数]で受ける
ｰ 要素数は定数じゃなくてOK
ｰ 開放は```delete[] アドレス```で行う

- メモリの動的確保のタイミング
	− サイズの自由な配列を作りたい
		− 動的配列・可変配列。配列のサイズを実行中に自由に決められる
	− 巨大な配列を安全に作りたい
		− 関数内でえ巨大な配列変数を作るとstack overflowを起こす。動的確保しておくと、巨大配列の時はエラーを吐いてくれる
	− 変数の寿命を自分で制御したい
		− new ~ deleteで寿命を支持できる