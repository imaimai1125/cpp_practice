## chapter.10 エラー処理と例外
## 11/4 4｀｀｀｀｀｀73-

- 10.1 goto文
- 10.2-10.6 例外処理
- 10.7 標準例外クラスと例外指定
- 10.8 コンストラクタで投げられた例外

### goto文
- ```goto ラベル```でラベルの位置へ移動できる
- gotoを利用すればエラー処理や多重ループの脱出が可能
- それ以外の処理でgotoを使うのは良くない
	- ラベルの場所にどこでも飛べるので自由度が高すぎる
	- ループの外から中に飛び込むなんてこともできちゃう
	- エラー処理と多重ループのbreak, continueくらいにしか使っちゃダメ
- goto文は初期化を伴う変数宣言を飛び越えることができない。	

### 例外
- throw式で例外を投げることができる
- tryブロック内で例外が発生すると対応するcatch節に飛ぶ
```
try{
	if(エラー判定条件){
		throw エラーメッセージ;
	}
}catch(変数宣言){
	エラー処理
}
```
- その関数内で補足されなかった例外は関数外へ投げられる
```
//Open,GetLineの中に　throwがある。
try{
	ifstream file;
	Open(file,"test.txt");
	string line;
	GetLine(file,line);
	cout << line << endl;
}//try
catch(const char* error){
	cerr << error << endl;
	return EXIT_FAILURE;
}
```

- 例外を補足できなければエラー終了する
- catch節は複数あっても大丈夫
	- 投げられた例外の型と対応するcatch節のみが反応する
- catch節からも例外を投げられる
- catch節内ならthrow;だけで同じ例外を投げられる
- catch(...)ですべての例外をキャッチできる。
	- elseみたいなもの
- 例外は参照でも受けられる
- 例外は**アップキャスト可能**
- ```throw class_name(引数);```という形にする。
- 例外は処理速度が遅い、エラーにしか現在使われていない などの理由から、エラー処理以外で使わないほうが賢明。


### 10.7 標準例外クラスと例外指定
- 標準例外クラスの基底クラスはexceptionクラス
- エラーの種類によって様々な例外クラスが用意されている
- 関数宣言の最後に```throw(例外型リスト)```と書くと、その関数がその型の例外しか投げないことを宣言できる。これを例外指定という。
- 標準例外クラス（詳しくは**p505**）
	- 処理を実行する前に検出可能なエラーを表す例外クラス（基底クラスはlogic_error）
	- 処理の実行時に検出可能なエラーを表す例外クラス（基底クラスはruntime_error）
	- 言語的に投げられる例外クラス（基底クラスはexception, クラス名の先頭にはbad_という接頭辞が付いている）
```
namespace std{
	class exception{
	public:
		exception() throw;
		exception(const exception&) throw();
		exception& operator= (const exception&) throw();
		virtual ~exception() throw;
		virtual const char* what() const throw();
	};
}
```
```
const char* FileException::what() const throw{
	return m_error.c_str();
}

↑は↓とほぼ一緒の意味。

const char* HogeException::what() const{
	try{
		return m_error.c_str();
	}catch(...){
		unexpected;
	}
}

```

### 10.8 コンストラクタで投げられた例外
- コンストラクタから外へ例外が投げられた場合、そのクラスのデストラクタは呼ばれない
- コンストラクタの初期化子で例外が投げられた場合、その例外はかあらず再送出される。
- デストラクタから外へは例外をなげちゃダメ

- ↓コンストラクタ内でも例外が発生することはある（この場合はメモリ不足でエラーメッセージが登録できないとか。）
```

FileException::FileException(const char* error){
	m_error = error;
}
```