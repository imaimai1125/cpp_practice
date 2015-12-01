#include "7_1_3_Stream.h"
using namespace std;


Stream::Stream(double n) : m_n(n){
	cout << "stream" << endl;
}

//設定された値を取得
double Stream::Get() const{
	return m_n;
}

//値を設定
//overideしてもいいように仮想関数にする
bool Stream::Set(){
	SetBase();
	return m_n>=0;
}

//値を設定する基本関数
//メンバ関数の中身、実際必要？？ー＞純粋仮想関数にすることで省略できる
// void Stream::SetBase(){
// 	// cout << "Stream::SetBase" << endl;
// 	 m_n = -1;
// }
