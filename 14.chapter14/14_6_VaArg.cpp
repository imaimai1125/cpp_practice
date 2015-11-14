#include <iostream>
#include <cstdarg>
using namespace std;

int Sum(int first, ...){
	int sum = 0;
	//引数を自由に取るためのもの
	va_list args;
	//va_listとかとセットで使う．
	va_start(args,first);
	for (int i = first; i != 0; i = va_arg(args,int)){
		sum += i;
	}
	//va_listとかとセットで使う．
	va_end(args);
	return sum;
}

int main(){
	//引数を自由に取れる
	cout << Sum(0) << " "
	<< Sum(1,0) << " "
	<< Sum(7,3,0) << " "
	<< Sum(1,2,3,4,5,6,0) << " "
	<< Sum(1,2,0,4,5,6,0) << endl;
}