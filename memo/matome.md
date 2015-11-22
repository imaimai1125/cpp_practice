## まとめのまとめ
### 出てきた型
- int 整数
- double 小数
- long double 小数
- char　文字
- char* ストリング（文字列）
- string ストリング
- unsigned char　符号なし文字列
- size_t　メモリのアドレス
- sizeof 配列の大きさ（型ではないかも）
- enum 列挙，フラグ
- struct　構造体（たくさんの変数を保持できるオブジェクト）
- int a[]　配列
- class クラス
- template <typename TYPE> 引数テンプレート
- typedef 同義語を作る
- union メモリを共有する構造体

### 型の前に付ける条件みたいな型
- &　参照
- *　ポインタ
- const　定数
- static　静的変数
- extern 外部リンケージ
- inline インライン関数

### 識別子
- public	パブリック識別子 外部からでもアクセスできる
- private プライベート識別子 外部には絶対後悔しない
- protected 外部には公開しないが、継承先だけには公開可能
- virtual オーバーライド時にアップキャストの影響を受けないようにする
- virtual function() = **0** 純粋抽象関数
- friend メンバ外でもプライベート識別子にアクセスできるようにしている
- explicit 暗黙のキャストをー
- volatile コンパイラの最適化を阻害
- mutable

- (auto)
- (register)

### 条件分岐
```
if(文){実行文}
else if(文){実行文}
else{実行文}
```
```
switch(条件式){
	case A: 実行文; break;
	case B: 実行文; break;
	case C: 実行文; break;
}
```
### 繰り返し
```
for(初期値;条件;繰り返し時の更新){
		実行;
}
```
```
while(条件文){
	実行文;
}
```
```
do{実行文}while{条件式};
```

### オブジェクト指向に大事な言葉たち
- メンバ変数
- メンバ関数・メソッド
- クラス
- オブジェクト
- インスタンス
- コンストラクタ
- デストラクタ
- コピーコンストラクタ
- オーバーロード演算子
- 継承
	- アップキャスト
	- オーバーライド virtual

### 例外処理
```
try{
	if(エラー判定条件){
		throw エラーメッセージ;
	}
}catch(変数宣言){
	エラー処理
}
```
- exception


### マクロ
- #define 関数などを定義
- #undef マクロの解除
- #assert(condition) 偽なら終了する
- #NDEBUG assertマクロを消す	