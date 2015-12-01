#include "7_1_2_ArrayStream.h"
//クラス内メンバ関数の定義
//Constructor
ArrayStream::ArrayStream(const double* array){
	m_array = array;
	m_i = 0;
}
//setter
bool ArrayStream::Set() {
	m_n = m_array[m_i];
	if(m_n >= 0){
		++m_i;
		return true;
	}else{
		return false;
	}
}