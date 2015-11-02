#include "7_11_ArrayStream.h"
#include <iostream>
#include <algorithm>
using namespace std;

//クラス内メンバ関数の定義
//Constructor
//配列を複製できるようにする
ArrayStream::ArrayStream(const double* array, int size){
	m_array = new double [size];
	copy(array, array+size , m_array);
	m_i = 0;
	cout << "ArrayStream" << endl;
}

ArrayStream::~ArrayStream(){
	delete []  m_array;
	cout << "~ArrayStream" << endl;
}

//値を設定する基本関数
void ArrayStream::SetBase() {
	m_n = m_array[m_i];
	if(m_n >= 0){
		++m_i;
	}
	cout << "ArrayStream::SetBase()" << endl;
}