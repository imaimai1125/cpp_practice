
## chapter.8  ファイルとストリーム
## 11/2 

- 8.1-8.2 stringクラス
- 8.3 stringstreamクラス
- 8.4-8.5 ファイルのすすめ
- 8.6 テキストとバイナリ
- 8.7 2進数・16進数
- 8.8 バイナリモードで読み書き
- 8.9 ファイル操作のエラー処理
- 8.10 ファイルポインタ
- 8.11 iostreamとマニピュレータ
- 8.12-8.14 名前空間

### 8.1-8.2 stringクラス
- stringクラスを使えば文字列を便利に扱える
- c_strメンバ関数を呼ぶとconst char 配列のアドレスが得られる
- ```string hello = "Hello";```は```string hello("Hello");```とほとんど同じ
- stringは```hello += " World"```のようなことができる（演算子オーバーロードを使っている）
- ```getline``` は入力から一行拾い、stringクラスのオブジェクトに入れる関数。
- 引数に指定した文字列をlineの**末尾**から検索していく関数。

```
string::size_type pos = line.rfind(".");
```
- 見つかった場合はそのインデックスを、見つからなかった場合は```string::npos```（```::```はスコープを返す）
- string型にはたくさんのメンバ関数が用意されているので、必要に応じて使う**（p378-379）**
	- i番目の要素への参照を返す(```char& operator[](string::size_type i)  const char& operator[](string::size_type i) const;```)
	- 文字列のサイズ変更(```void resize(string::size_type n)```)
	- 文字列を空に（```void clear```)
	- などなど。

### 8.3 stringstreamクラス
- stringstreamクラスを使えばcoutと同じ形で文字列生成ができる
- stringstreamクラスを使えばcinと同じ形で文字列から値を取り出すことができる。
- stringstreamクラスは<sstream>内にある
- stringstream内に残っている文字列を一旦消去 -> ```sstr.str(" ")```

### memo
- 演算子オーバーロードのことは正直よくわかってない
- 同じくコピーコンストラクタもイマイチ
- クラスを複数作るときの初期化と代入について不都合なく処理を行うための手続き？？