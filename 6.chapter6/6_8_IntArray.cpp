#include "6_8_IntArray.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//コンストラクタ
IntArray :: IntArray(int num){
	fill_n(m_array,INTARRAY_SIZE,0);
}

//メンバへのアクセス関数
//getter
int IntArray::Get(int i){
	CheckIndex(i);
	return m_array[i];
}

//setter
void IntArray::Set(int i, int value){
	CheckIndex(i);
	m_array[i] = value;
}

//インデックスのチェック	
void IntArray::CheckIndex(int i){
	if (0<=i&&i<INTARRAY_SIZE){
		//インデックスは正常です
	}else{
		cout <<"Index is invalid"<<endl
			 <<"value : " << i << endl;
		exit(EXIT_FAILURE);
	}
}

//配列のサイズを返す
int IntArray::Size(){
	return m_size;
}