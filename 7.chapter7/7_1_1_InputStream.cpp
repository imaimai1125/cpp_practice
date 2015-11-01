#include "7_1_1_InputStream.h"
#include <iostream>
using namespace std;

bool InputStream::Set(){
	cin >> m_n;
	return m_n >= 0;
}