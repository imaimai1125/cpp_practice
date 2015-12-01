// IntArrayクラスを定義

#ifndef MACRO
#define MACRO

#include <iostream>
#include <cstdlib> //exit関数に必要
using namespace std;

const int INTARRAY_SIZE = 100;
class IntArray{
//コンストラクタ
public:
	IntArray(int n);						
//コピーコンストラクタ（初期化時のエラーを防ぐ）
public:
	IntArray(const IntArray& other);
//代入演算子オーバーロード
public:
	void operator = (const IntArray& other);

//private変数の橋渡し
public:
	// ゲッタ
	int Get(int i);
	// セッタ
	void Set(int i, int value);
//インデックスのチェック
public:	
	void CheckIndex(int i);
//サイズの取得
public:
	int Size();

//配列自体をprivateにすることで、外からのアクセスを不可能にする
private:
	int* m_array;
	int m_size;
};


#endif