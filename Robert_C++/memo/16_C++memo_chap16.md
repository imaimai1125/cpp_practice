## chapter.16 その他種々の事項

- 16.1 共同体union
- 16.2 無名構造体
- 16.3 ビットフィールド
- 16.4 可変長配列メンバ
- 16.5 コンマ演算子
- 16.6 トークン連結演算子 ##
- 16.7 文字列化演算子 #
- 16.8 配列へのポインタ
- 16.9 extern C
- 16.10 volatile
- 16.11 set_terminate, terminate


##11/23
### 16.1 共同体union
変数が違えばアドレスは普通違うが，**同じように**することもできる
- 共同体のメンバ変数は全て**同じメモリ領域を共有する**
- 構造体の宣言と同じ形で`struct`を`union`に変えると共用体
- 型ごとの役割が排他的な時につかえばいい？
- 継承はできない．メンバ関数を作ることができない

### 16.2 無名構造体
- 名前のない**クラス・構造体・共用体・列挙体**を作ることができる
- 無名共用体を変数なしで作った場合，メンバ変数に**直接アクセス**できる．これを**匿名共用体という**
	- 内部リンケージのグローバル変数やローカル変数にもできるが**外部リンケージのグローバル変数**にはできない
```
struct {
	char name[MAX_NAME -1];
	int scoreJAPANESE
	char address[MAX_ADDRESS-1];
} student;
```
- 型名のない構造体なので，型名の必要なあらゆることができなくなってしまうが，使い道はある
	- メンバ関数おもてる．ただし，コンストラクタやデストラクタを作ることはできない
	- クラスや構造体を継承できる．基底クラスへの**参照やポインタ**を引数にとる関数へと渡せる
- 無名列挙体は単に定数を宣言したい場合に使える
```
enum{
	EINS =1 ,ZWEI,DREI,
};
```

### 16.3 ビットフィールド
普通バイト単位で変数は扱うが，ビット単位で演算を行うことができる変数もある

- 構造体や共用体のメンバ変数の後ろに`:ビット数`を置くと，そのメンバ変数の大きさはそのビット数になる．
- ビットフィールドの型は**整数型か列挙体型のみ**
- 構造体の一部としても使用できる．

### 16.4 可変長配列メンバ
- **構造体の最後のメンバを配列にしておく**と，その構造体の後ろにあるデータを扱える
- 意図的に大きくメモリを確保し，その部分をメンバの要素とできる
- BITMAPINFOで使われている．(256色と16色ではパレット（対応する色)数が違う）
	- が，強引なのであまり自分から使うべきでは無いかも
```
struct FileInfo{
	int SizePath;
	int SizeFile;
	char path[1];
}
```

### 16.5 コンマ演算子
- `式1, 式2`　とすると，式1が実行された後に式2が実行される
- `式1, 式2`の値は式2になる
- コンマ演算子は優先順位が**最低**
- コンマ演算子を使えば複数の式を**合成**して一つの式にできる
- 演算子なので，オーバーロードも使え，面白いことができるかも．

### 16.6 トークン連結演算子
- マクロ展開において連結されると意味の変わるテキストの間には空白が入ってしまう
- マクロの定義に##があると，展開時にその前後のトークンが連結される．
- 引数の展開は##による連結が行われる前に行われる
- マクロ展開の順番を意識しておこう
	- 引数置換->そのマクロに含まれているマクロを全て展開->トークン連結

### 16.7 文字列化演算子 #
ASSERTマクロを自作してみよう(出力するエラーメッセージに条件式が含まれている)

- マクロ引数に#をつけると，文字列リテラルとして展開される
- assertマクロは，引数が偽であった場合になんらかのエラーメッセージを出力して，abort関数を呼び出すというマクロ


### 16.8 配列へのポインタ
多次元配列もメモリ上にある．多次元配列のアドレスを入れておく変数は？

- n次元配列arrayのアドレス&arrayを入れることのできるポインタの宣言
	- `型(*変数名)[2番目の要素数][3番目の要素数]...[n番目の要素数];`
- n次元配列の配列名は`型(*)[2番目の要素数][3番目の要素数]...[n番目の要素数];`へと暗黙にキャスト出来る
- ２番目以降の要素数も柔軟に使いたいなぁ．
	- 関数テンプレート-要素数が違えば全く別の実態が作られるので効率❌
	- ポインタの配列を作る
```
int* parray[] = {
	array[0],array[1],array[2],//全て5要素の配列
}
//parrayはint*型の一次元配列
void Hoge(int** pp);
Hoge(parray);
```

### 16.9 extern"C"

- C言語とC++では関数名の**内部表現が異なる**
	- C言語にはオーバーロードや名前空間の概念がない．そのために内部表現が異なっている
	- C++には↑の概念があるため，引数に関する情報や名前空間に関する情報を関数名の内部表現に加えることで，同じ名前の関数があった場合にどれを読んでいいのか区別をしている(**名前修飾(マングリング)**という)
- C++からC言語の関数を使うときは関数プロトタイプ宣言の前に**extern"C"**をつける
- 複数の宣言に一括してextern"C"を指定したい場合はその全体をextern"C"{}で囲む

### 16.10 volatile
- `volatile`を使えば**最適化を阻害**できる
```
void Hoge(){
	volatile int n = 1;
	if(n){
	cout << n << endl;
	}
}
```
- マルチスレッドプログラミングでよく使われる
	- 並列に走っていることを認識し無いまま処理を勝手に最適化されては困る
	- メモリへのアクセスが外部機器への入出力に相当するようにする機能が使われる場合など(memory mapped I/O)は，メモリへのアクセスが省略されてしまうと外部機器への操作が省略されてしまうことになる．


### 16.11 set_terminate, terminate
- `set_terminate`で例外がキャッチされなかった場合の処理を登録できる
	- 例外にすら登録されていない例外
- terminate関数を呼ぶと，その登録された処理を読んでから異常終了する
- exceptionヘッダで宣言されている．




## memo
- ostreamとかのライブラリの扱い方がまだイマイチ
- ポインタ，参照などの見直しは必須かも．奥が深いな．