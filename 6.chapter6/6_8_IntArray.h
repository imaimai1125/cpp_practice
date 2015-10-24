#ifndef MACRO
#define MACRO


#include <iostream>
#include <cstdlib> //exit関数に必要
using namespace std;

const int INTARRAY_SIZE = 100;
class IntArray{
public:
	IntArray(int n);						//コンストラクタ
public:
	//ここはアクセスできるようにする
	int Get(int i);					//値の取得
	void Set(int i, int value);		//値の変更
public:	
	void CheckIndex(int i);			//インデックスのチェック

public:
	int Size();
private:
	int* m_array;
	int m_size;
};

#endif