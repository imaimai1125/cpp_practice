#include "7_11_InputStream.h"
#include <iostream>
using namespace std;

//基底クラスがdoubleを引数に取るので、派生クラスのコンストラクタに明記しといてやる
//デフォルトコンストラクタでは省略が可能
InputStream::InputStream()
{
	cout << "InputStream" << endl;
}

void InputStream::SetBase(){
	cout << "InputStream::SetBase" << endl;
	cin >> m_n;
}