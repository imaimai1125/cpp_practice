//クラス内メンバ関数の定義

#include "6_8_IntArray.h"
#include <algorithm>
#include <cstdlib>

IntArray::IntArray(int size){
	m_array = new int[size];
	m_size = size;
	cout << "コンストラクタが呼ばれました" << endl;
}

//コピーコンストラクタ
IntArray::IntArray(const IntArray& other){
	m_array = new int [other.m_size];
	m_size = other.m_size;
	cout << "コピーコンストラクタが呼ばれました" << endl;
}

//代入演算子オーバーロード
void IntArray::operator = (const IntArray& other){
	int* array = new int[other.m_size];
	delete [] m_array;
	m_array = array;
	m_size = other.m_size;
	copy(other.m_array, other.m_array + m_size, m_array);
	cout << "=演算子をオーバーロードしました。"<<endl;
}
//メンバへのアクセス関数
//getter
int IntArray::Get(int i){
	CheckIndex(i);
	cout<<"["<<i<<"]の値を取得しました。 -> " << m_array[i] <<endl;
	return m_array[i];
}

//setter
void IntArray::Set(int i, int value){
	CheckIndex(i);
	m_array[i] = value;
	cout<<"["<<i<<"]の値を"<<value<<"としました。" <<endl;

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

int IntArray::Size(){
	return m_size;
}
/***********************************
Destructorが何故か機能しない（エラーが出る）
error::definition of implicitly declared "IntArray::~IntArray()"
***********************************/

//デストラクタ（メモリの開放）
// IntArray::~IntArray(){
// 	delete [] m_array;
// 	cout <<"destructor is called" <<endl;
// }