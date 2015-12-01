#include "7_1_1_InputStream.h"
#include <iostream>
using namespace std;

//基底クラスがdoubleを引数に取るので、派生クラスのコンストラクタに明記しといてやる
//デフォルトコンストラクタでは省略が可能
InputStream::InputStream(double n)
:Stream(n)
{
	cout << "InputStream" << endl;

}

// bool InputStream::Set(){
// 	cin >> m_n;
// 	return m_n >= 0;
// }

void InputStream::SetBase(){
	cout << "InputStream::SetBase" << endl;
	cin >> m_n;
}