## Chapter1. C++に慣れよう

1. C++を複数の言語の連合とみなそう
2. `#difine`よりconst,enum,inlineを使おう
3. 可能ならいつでもconstを使おう
4. オブジェクトは使う前に初期化しよう

## 12/1
### 1項. C++を複数の言語の連合とみなそう
- C++はマルチパラダイムなPログラミング言語
	- 手続き指向プログラミング, オブジェクト指向プログラミング, 関数プログラミング, ジェネリックプログラミング, メタプログラミングを複数まとめてサポート

基本的なサブセット

- C
	- ブロック，ステート，プリプロセッサ，組み込みのデータ型，配列，ポインタなどはここから	
	- プリプロセッサの代わり(2項)やリソース管理のオブジェクト(13項)がC++には存在
	- Cのルールが当てはまる
- オブジェクト指向C++
	- クラス，カプセル化，継承，ポリモーフィズム，仮想関数（動的結合）など
	- オブジェクト指向デザインのための古典的なルールが当てはまる
- テンプレート C++
	- ジェネリックプログラミングの部分
	- テンプレートは非常に強力で，Template Meta Programingというパラダイムを生み出した(48項)	
- STL
	- テンプレートライブラリの中でも非常に特別なもの
	- コンテナ，反復子，アルゴリズム，関数オブジェクトなどライブラリ内の要素が組み合わさっている
	- 独自の方法論があるので，規約(convention)に従う必要がある

サブセットを乗り換える際には戦略を変えていかなければならない．どれなのかを意識することが大事

## 12/2
### 2項 `#define`よりも`const, enum, inline`を使う
プリプロセッサ（コンパイラがまず行うような命令．マクロ？）よりコンパイラを使おう．

- プリプロセッサを使わないほうがいい理由
	 - コンパイル中のエラーにはマクロで定義した数字が直接出てくるため，どこが間違っていたかがわかりにくい
	 - 
- `#define`よりも`const`でなんとかしよう
``` 
#define ASPECT_RATIO 1.543
const double AspectRatio = 1.543;
```

- 一般に文字列はchar*よりstringで表すほうが良い
```
const char* const authorName = "imaimai";
const std::string authorName("imaimai");
```
- クラスで使う定数のスコープ（有効範囲）を限定するためにその定数をクラスのメンバにすることがある.その場合，その定数が実際に**一つだけ**存在するように`static`にする．
```
class GamePlayer{
private:
	static const int NumTurns = 5; //static定数宣言
	int scores[NumTurns]
};
```

ただし，↑のは古いコンパイラでは通らない可能性もあるそういうときに便利なのが**enum**

```
class GamePlayer{
private:
	enum{NumTurns=5}; //enumハック
	int scores[NumTurns]
};
```

- enumハック:enum型の値がintとしても使えることを利用するテクニック
	- constより`#define`に近い
	- constな変数のアドレスを使うことは許されているが，enum要素のアドレスを使うことは許されていない
	- 他プログラマが整数定数へのポインタや参照を使うのを禁止したいなら`enum`を使うと良い
	- テンプレートを使ったメタプログラミングの基本テクニックにもなる(48項)

- `#define`の良くない例:`#define CALL_WITH_MAX(a,b)f((a)>(b)?(a):(b))`
```
int a = 5,b = 0;
CALL_WITH_MAX(++a,b); //2回のインクリメント
CALL_WITH_MAX(++a,b+10); //1回のインクリメント	
```
fが呼び出される前にaが何回インクリメントされるかは引数の値によって変わってしまう.こういうのは良くない

- インライン関数のテンプレートを作れば効率的かつ振る舞いが明白で型安全な関数を得る（30項に詳細)

```
//引数として同じ型のオブジェクトを２つ受け取り
//その大きいほうを使ってfを呼び出す
template<typename T> //T型がわからないため
inline void callWithMax(const T& a,const T& b); //参照仮引数を使う
{
f(a>b?a:b);
}
```

- まとめ：`const`, `enum`, `inline`を使えばプリプロセッサ(特に`#define`)の必要性は小さくなる
- ただ全く必要ないわけではない．

### 3項 可能ならいつでも`const`を使おう！
変更してはいけないという制約をはっきりさせてコンパイラがその制約を守らせる手伝いをしてくれる．
- `const`はグローバル定数，名前空間での定数，ファイル，関数，ブロック，データメンバ(static,非static), ポインタなど様々なところで出てくる

```
char greeting[] = "Hello";
char *p = greeting;					//ポインタもデータも非const
const char *p = grerting;			//ポインタは非const,データはconst
char const *p = greeting;			//ポインタはconst,データは非const
const char const *p = greeting;		//ポインタもデータもconst
```
- constがアスタリスクの左にあるときは「ポインタが指し示すデータ」が普遍
- constがアスタリスクの右にあるときは「ポインタそのものが普遍」

これは同じ意味
```
void f1(const Widget *pw);
void f2(Widget const *pw);
```

- STLのiteratorはポインタをモデルにしているので，反復子は`T*`型ポインタのよいうに振る舞う．const付きの反復子はconst付きのポインタ(`T* const`)と同様に「別のものを指し示すように変更はできないが，指し示すものの内容は変更しても良い反復子」

```
std::vector<int> vec;
...
const std::vector<int>::iterator iter= vec.begin(); //T* const
*iter = 10; //iterが指すものの内容は内容を変更しても問題ない
++iter;		//エラー！iterはconstだから

std::vector<int>::const_iterator citer=vec.begin(); //const T*
*citer = 10;		//エラー！clterはconstだから
++citer;			//clterを変えても問題ない
```

- 関数宣言での利用はconstの最も強力な使い方の一つ
- constは関数の戻り値にも，個々の仮引数にも使える．
	- 関数の戻り値をconstにすると安全性や効率を犠牲にすることなくクライアントがその関数を誤用する可能性を低くできる(24項)
- メンバ関数については関数そのものにconstをつけることもできる

```
class Rational{...};
const Rational operator*(const Rational& lhs,const Rational& rhs);
```

`*`演算子をconstにすることで以下のような悲劇を防ぐことができる
```
Rational a,b,c;
if(a*b = c){...}//比較のつもりがミス！
```
constにしておくとこのようなこのように「==のつもりが=に...!」を避けることができる．

- メンバ関数にconstをつける理由
	- クラスのインターフェースを理解しやすくなる．オブジェクトを変更するのかしないのかの区別が明確に．
	- constなオブジェクトに対して使える.(20項)
- オーバーロードでconstのあるなしだけが異なる２つのバージョンのメンバ関数を考えることができることは割と大事
 
```
class TextBlock{
public:
...
	//constなオブジェクトのための[]演算子
	const char& operator[](std::size_t position) const
	{return text[position];}
	//constでないオブジェクトのための[]演算子
	char& operator[](std::size_t position)
	{return text[position];}
private:
	std::string text;
};

```
```
TextBloc tb("HELLO");
std::cout << tb[0];

const TextBloc ctb("WORLD");
std::cout << ctb[0];
```
どっちも可能になる

- constは**ビットレベルの普遍性**を考慮するのであって論理的な普遍性を保証しているわけではない．
	- ポインタの指し示すオブジェクトを変更していても，データメンバであるポインタ自身を変更していなければビットレベルの普遍性を持っていることになる．
```
class aaa{
public:
...
	char& operator[](std::size_t position)const
	{return pText[position];}
private:
	char *pText;
}
```

##　何がダメか全然わからない

- 逆に，論理的な普遍性を保つためならビットレベルの普遍性は少し変更しても良いだろういう宗派もあり
	- `mutable`を使うと，クラスのconstメソッドの中でも**操作できる**メンバ変数を作ることができる


- constと非constでコードがめっちゃ重複する
	- `const_cast`と`static_cast`をうまく使ってやる

```
const_cast<char&>(
	static_cast<const TextBlock&>(*this)
	[position]	
);
```

再帰的に読んだthisを読んでから`static_cast`でconstをつける．そうすることでconstなメンバ関数が呼び出すことができる．呼び出したところでconstを除去するキャスト`const_cast`を行う．


- 参考:(constメンバ関数)http://qiita.com/takeh1k0/items/b6587734f0a88951f8d4

「constメンバ関数では、暗黙的に渡されるthisポインタがconstで修飾される」

「const修飾は波及する」

##この説明も意味不明．thisの指オブジェクトの中身を保護する必要があるのはなぜ？？？？？？？


## 12/3
### 4項 オブジェクトは使う前に初期化しよう

- C++は，ある状況では初期化されたり初期化されなかったりする（ように見える）
	- 初期化されてないやつを読み出そうとすると未定義になっちゃったり，デタラメな値を読みだしちゃう．
	- このルールは複雑だから覚えるメリットはあんまない
- 混乱するので，**必ず初期化する**ことを心がけるべき
- 組込型は必ず初期化をしないとエラーになる
```
int x = 0;
const char* text = "A C-style string";

double d;
std::cin >> d;
```

- 組込型以外はコンストラクタが初期化する．
	- オブジェクト内の**すべてのデータ**をコンストラクタで初期化しよう
	- 代入と初期化を混同しない！

```
class PhoneNumber{...};
class ABEntry{
public:
	ABEntry(const std::string& name, const std::string& address,
	const std::list<PhoneNumber>& phones);
private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesCOnsulted;
}

//これは代入！！！！！！！！
//代入する前にデフォルトコンストラクタが呼ばれる
ABEntry::ABEntry(const std::string& name, const std::string& address,
	const std::list<PhoneNumber>& phones)
{
	theName = name;
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = 0;

}
//これが初期化！！！！！！
//メンバ初期化子リストを使えば各データメンバのコンストラクタを
//呼び出すことになり無駄がなくなる(コピーコンストラクタを使っている)
ABEntry::ABEntry(const std::string& name, const std::string& address,
	const std::list<PhoneNumber>& phones)
:theName(name),
 theAddress(address),
 thePhones(phones),
 numTimesConsulted(0),
{}

```

- いつでも初期化子リストを使うと悩む必要ない
- 基底クラス部分は派生クラス部分より先に初期化される．
- 一つのクラスの中ではデータメンバーが宣言された順番に初期化される
- ローカルでない静的オブジェクト
	- グローバルなオブジェクト, static宣言をクラス内でされたオブジェクト, 名前空間をスコープとするオブジェクト, ファイル内でstatic宣言されたオブジェクト
	- 関数内でstatic宣言されたオブジェクトは関数にとってローカルなのでローカルな静的オブジェクト
- 異なる翻訳単位にあるローカルでない静的オブジェクトの初期化の順番は決められない
- 関数内でstatic宣言s慣れたオブジェクトはその関数の呼び出しで制御が最初にその定義に達した時に初期化される

- まとめ：気をつける３つ
	-  クラスのメンバでない**組込型オブジェクト**は明示的に初期化
	-  クラスのデータメンバのすべてを初期化するように**初期化子リスト**を使う
	-  **異なる翻訳単位にあるローカルでない静的オブジェクト**はその初期化の順番が不定なためその問題を避けるようにデザインを考えること．

























