ロベール　C++入門講座

### 10/18
### chapter3
#### bit/byte

* 1ビットは0か1をあらわす一桁
* 1バイトは8ビット
* 操作・記憶の最小単位はバイト
* 型や変数には大きさがあり```sizeof```演算子で取得可能
* (型)を前に付けると型の変更ができる：**キャスト**　
* キャストは環境依存の危険な操作であることも多いのであまり多用しちゃだめ。

```
int a = 10;
double b =1.0;
//キャスト
b = (double)a;
```

* 変数のバイト数 char<short≦int≦long,float≦double≦long double
* 型の決め方　1.01f (float), 1.01l (long), 1.01lu (unsigned long) ※何も付けないとintかdoubleになる


#### 参照（遠隔操作）
* 仮引数（関数内のかっこ）は関数を読んだときに新しく変数が作られ、その変数が実引数の値で初期化される（値渡し）
* 参照（型名に&を付ける）を使えば関数越しに変数を定義できる
* 参照の参照先を途中から変更はできない
* 参照は必ず初期化がいる

値渡し
```
void function(int hogehoge){
}
```
参照渡し
```
void function(&int hogehoge){
}
```

#### 文字コード
- 文字は通し番号で扱う
- その通し番号のことを文字コードという
- 半角1byte, 全角2byte
- ''内の言葉はc++は**char**、cはint型になっている。


### 10/19
#### 文字列　string
- 文字列は文字コードの羅列
- 文字列の終わりには0を付ける（null terminator)
- null terminatorを忘れてプログラムを組んでしまうとばぐる　
- 文字列はchar型の配列変数に入れる
- 文字列は配列変数の名前で扱う。
- sizeof演算子の型はsize_t型。符号なしの整数型なので、キャストしてやったほうがよいかも。（ふつうはしなくても動くようになっている。サイズが大きすぎるとout）
- 文字列を最後まで走査する場合、ヌルターミネータが現れるまで処理すればよい
- sprintfで文字列を編集できる。
- printfで文字列を編集した形で表示できる。(Cのライブラリを使う。結果は一緒)

- 文字列を最後まで走査する場合はsizeofよりnull terminatorで判断させたほうがよい。文字列が変更されて配列変数の途中で文字列が終わるようになっていた場合にもすべての要素を

```
//悪い例
for (int i=0;i<(int)sizeof hello; ++i){
	cout << (int)(unsigned char)hello[i] << ",";
}

//推奨
for (int i=0;hello[i] != '\0'; ++i){
	cout << (int)(unsigned char)hello[i] << ",";
}

```

- null terminatorの条件を書くときは、0のまえに\を付けることで誤識別を防ぐ
- sprintf : はじめに文字列を書いて、後から数値とか変数値を代入できるという仕組み
- sprintfを使うときは #include <cstddio>を使う。
- 作った文字列を入れる容器がstr⇒**大きめ**にとっておかないとバグ、セキュリティの穴になっちゃう。buf overflow


```
char str[50];
sprintf(str, "f(%d,%d) = %d", x,y,f(x,y));
cout << str << endl;
```

* これに対して直接文字列を表示するのが```printf```

####　変換指定子
- ```printf```に関して
```
printf ("今日は%d日です",25);
```
この%ｄが変換指定子
- 種類:d(符号付10進数),u(符号なし10進), o(符号なし8進), x(符号なし16進), f(不動小数点), e(不動小数点表示、指数表記), c(文字), s(文字列)

####　その他文字列操作に関するtips
p.125に例あり。

#### 関数プロトタイプ
- 関数プロトタイプを宣言すれば関数定義を後回しでOK
- main()の前に書くことができる
- 関数プロトタイプは関数の中身を書かないだけのもの。
- プロトタイプは仮引数を書く必要はないけど書いていたほうが可読性が高いからお勧め

#### include
- ```#include```で別のファイルを埋め込むことができる
- ```<hogehoge>``` で設定されたフォルダを優先的に調べる.ツール側で作っているヘッダファイルはこれ
- ```"hogehoge"```で設定されたファイルを優先的に調べる.自分で作ったヘッダファイルはこれ
- ファイルの先頭でincludeするファイルをヘッダファイルという
- include先のプログラム.hを合成された形でソースファイル.cppはビルドする
- プログラムを小分けにできるので便利だよ。
- ???どのヘッダかを呼び出したかみたいなのをプログラムを見て簡単に識別できないのか？？

#### 擬似乱数
- 擬似乱数はrandで取得できる
- 擬似乱数はsrandで初期化できる
- 初期化には時間を利用するとよい
- randには```cstdlib```というヘッダファイルで宣言される
- randomを適当に作っていて、更新しないこともあるので、擬似乱数と呼ばれる。
	- ある初期値から始まってどんどん擬似乱数を生成していっている
	- 初期値をrandom seedという
	- random seedを固定すると同じ擬似乱数が出る。違う乱数を出すためにはプログラムのはじめに乱数種を初期化しないといけない。
	- それをするのがsrand
	- いちいち手動で設定するのはめんどくさいので時間を初期値にする

```
#include <ctime>
void InitRand(){
	srand((unsigned int)time(NULL));
}
```

#### 数学関数
-　```<cmath>```をincludeする
- 小数にはdouble, float, long double型がある
- 数学関数の例
```
//演算規則
int abs(int x);
double fabs(double x);	//小数の絶対値
double floor(double x);	//小数第一位の切捨て
double ceil(double x);	//小数第一位の切り上げ
double fmod(double x, double y);  //xをyで割ったあまり
double modf(double x, double* p); //xを整数部分と小数部分に分離
//以下関数演算の拡張
double sqrt(double x);
double pow(double x, double y);
double exp(double x);
double log(double x);
double log10(double x);
double sin(double x);
double asin(double x);
doube atan2(double y, double x);
double sinh(double x);
double asinh(double x);
```

####　オーバーロード
- 引数が違えば同じ名前の関数が作れる
- 戻り値が違うだけでは同じ名前の関数は作れない
-　同じ名前の違う関数を作ることをオーバーロードという

```
//こういうのがOK
int Abs(int a){
	実行文;
}
double Abs(double a){
	実行文;
}
```

- 引数が同じ場合は二重定義(multiple definition)となりerror
- 引数、個数、順番のどれかひとつでも違いさえすれば同盟の関数を二つ以上定義できる。
- C言語はoverloadできない

####bool型
- bool型の変数はtrue or false
- 条件式においてtrueは真、falseは偽
- trueは1,falseは0と、整数としても利用できる。
```
//使用例
bool b = false;
if(b){実行文;}
```
