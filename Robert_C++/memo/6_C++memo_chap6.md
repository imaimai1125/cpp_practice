## chapter.6 クラス
クラスの使い方について学ぶ。
## 10/23
- 6.1 クラスの基本
- 6.2 メンバ関数
- 6.3 コンストラクタ
- 6.4 引数つきコンストラクタ
- 6.5 privateアクセス指定子
- 6.6 デストラクタ
- 6.7 分割コンパイル
- 6.8 コピーコンストラクタ
- 6.9 演算子オーバーロード
- 6.10 constメンバ関数
	

### 6.1 クラスの基本
- クラスはデータとその処理をひとまとめにしたもの
- public:を付けないと外から使えな−い（structと違うところ）
- 関数もメンバにできる（structと違うところ）。これをメンバ関数（メソッド）という
- クラスで言う```students[0].Show()```は構造体で言う```Show(&students[0])```みたいなもの

### 6.2 メンバ関数（メソッド）
− クラスとはデータとそれを扱う処理を一つにまとめた型
- メンバ関数を作るときはクラスの宣言中に関数プロトタイプを書く
- メンバ関数を実装するときは関数名の前に```クラス名::```を書く
- メンバ関数内ですのまま使われたメンバ変数は、そのメンバ関数を呼び出すときに作ったオブジェクトのメンバ変数を渡す

- メンバ関数はメンバ変数と同じように、```. ->```などを使って呼び出せる。


### 6.3-6.4 コンストラクタ
- メンバ変数の初期化(```int i = 1```みたいなもの)はコンストラクタで行う
- コンストラクタはクラス名と同じ名前の、戻り値なしの関数
- コンストラクタはオブジェクトを作るときに自動的に呼ばれる。
− コンストラクタに引数があってもよい
- 引数付きコンストラクタを呼ぶには、変数の宣言時に変数名に引数をつける。
- 配列の初期化時には{}の中でまるで普通の関数であるかのようにコンストラクタを呼べばいい

```
class Student{
public:
	char name[MAX_NAME+1];
	int scoreJapanese;
	int scoreMath;
	int scoreEnglish;

	void Show();
};
//スコープみたいなもの
void Student::Show(){
	hogehoge;
}
//配列によって、student型を複数個用意することが可能！！
int main(){
	//インスタンスの生成
	Student student[] = {
		{"Johny" , 15,20,25},
		{"Smith" , 50,55,60},
		{"Michael", 80,90,100},
	};
	for(int i;i<...;++i){}
		student[i].Show();
	}
}
```
##10/24（281−）
### 6.5 private アクセス指定子
− publicをつけるとメンバは外部に公開される
- privateをつけるとメンバは外部に公開されない
− アクセス指定はメンバの値を保証するために重要である
− privateな関数において値を取得するときはゲッタ、値を変更するときはセッタを使う。
− ゲッタとセッタはpublicにして、外部と内部の橋渡しになってる。
- 識別子はすべてのメンバ変数につけておくと良い。基本はprivateにしてアクセス制限したほうが良い

### 6.6 デストラクタ
- 変数の寿命が来ると自動的にデストラクタが呼ばれる
- デストラクタはクラス名の前にチルダ```~```のついた名前の関数
- デストラクタは戻り値も引数もない
- コンストラクタ、デストラクタの機構はメモリリークを防ぐのに便利
- クラスはコンストラクタに始まりデストラクタで終わる

### 6.7 分割コンパイル
- 分割の方法
	− ヘッダファイルにクラスの宣言を書く
	− ソースファイルにメンバ関数の実装部を書く
	− そのクラスを使うソースファイルでそのヘッダファイルをインクルードする。
- クラスについて
	− クラスを使うにはそのクラスの完全な宣言が必要
	− メンバ関数を実装（関数の内容を記述すること）する時にもそのクラスの完全な宣言が必要
	− メンバ関数はどこか一箇所のみで実装されなければいけない。
	− 別々のソースファイルに同じクラスがあっても二重定義にはならない。


### 6.8 コピーコンストラクタ（オブジェクトの複製）
− コピーコンストラクタは自分の**クラス型への参照を引数にとる**
− コピーコンストラクタは仮引数（関数内の引数）を作るときに呼ばれる
- 
− 仮引数は関数を読んだ時に新たに変数が作られ、その変数が実引数の値で初期化されるという仕組みになっている。
− 

## memo
- 同時にコンパイルする意味がイマイチわかっていない。ヘッダじゃなくてcppを同時に作る意味あんの？
− makefileの使い方を知らなきゃ。
```
分割コンパイルの時
g++ -c internal1.cpp
g++ -o internal1.o -c internal1.cpp
g++ -c internal2.cpp
g++ -o internal2.o -c internal2.cpp
g++ -o internal internal1.o internal2.o
```
makefileなら
```
Internal : Internal1.o Internal2.o
	g++ -o Internal Internal1.o Internal2.o
Internal1.o : Internal1.cpp
	g++ -c Internal1.o	
Internal2.o : Internal2.cpp
	g++ -c Internal2.o
```

##11/1 (305-)
###  6.9 演算子オーバーロード
- コピーコンストラクタがない場合に各メンバ変数がコピー元のメンバ変数の値で初期化されるのと同様、代入の場合も各メンバ変数にコピー元のメンバ変数が代入される。
− インスタンスa,bがあり、aを初期化した後に```b = a```と代入演算をすると、aとbは同じメモリ領域を指すようになってしまい、出力結果が一緒になってしまう。
− ↑を回避するために代入時に特殊な処理を行わなければダメ。これを実現するのが**演算子オーバーロード**という
− ```copy(a,b,c)```:a以上b未満のアドレスにあるデータをcの指すアドレス以降にコピーする関数
− ```operator= ```というメンバ関数で代入の振る舞いを変更できる
− ```operator+ ```というメンバ関数で加算の振る舞いを変更できる。+のところは任意の演算子で良い
- 初期化ではコピーコンストラクタ、代入では```operator=```が呼ばれる

### 6.10 constメンバ関数
- constオブジェクトはconstメンバ関数しか呼べない
- ```int IntArray::Size() const ```のように、宣言時にconstをつけることでconstで呼び出したオブジェクトから呼び出せるようになる。













