/****
11/2 エラーが出る
/home/imaimai/cpp/cpp_practice/7.chapter7/7_10_HalfInputStream.cpp: In function ‘int main()’:
/home/imaimai/cpp/cpp_practice/7.chapter7/7_10_HalfInputStream.cpp:11:6: error: ‘virtual void HalfInputStream::SetBase()’ is protected
virtualの使い方がイマイチわかっていない？
****/

#include "7_10_HalfInputStream.h"
#include "7_1_1_InputStream.cpp"
#include "7_1_3_Stream.cpp"
#include <iostream>
using namespace std;

HalfInputStream::HalfInputStream(double n)
:InputStream(n){
	cout<<"HalfInputStream"<<endl;
}
//値を設定する基本関数

void HalfInputStream::SetBase(){
	InputStream::SetBase();
	m_n /= 2;
}

main(){
	HalfInputStream histream(5);
	//エラーの元
	histream.SetBase();
	cout<<histream.Get()<<endl;
}