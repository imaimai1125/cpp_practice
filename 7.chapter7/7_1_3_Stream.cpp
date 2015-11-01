#include "7_1_3_Stream.h"
using namespace std;

//設定された値を取得
double Stream::Get() const{
	return m_n;
}

//値を設定
bool Stream::Set(){
	cout << "Stream::Set" << endl;
	m_n = -1;
	return false;
}