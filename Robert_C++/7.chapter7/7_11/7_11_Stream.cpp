#include "7_11_Stream.h"
using namespace std;


Stream::Stream() {
	cout << "Stream" << endl;
}
Stream::~Stream(){
	cout << "~Stream" << endl;
}


//設定された値を取得
double Stream::Get() const{
	return m_n;
	cout << "Stream::Get()"<<endl;
}

//値を設定
//overideしてもいいように仮想関数にする
bool Stream::Set(){
	SetBase();
	return m_n>=0;
	cout << "Stream::Set()"<<endl;
}
