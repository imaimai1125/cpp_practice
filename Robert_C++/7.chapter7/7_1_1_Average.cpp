// 入力から平均値を出力するプログラム
#include "7_1_1_InputStream.h"
#include <iostream>
using namespace std;

bool Average(InputStream& stream){
	int count;
	double avr = 0;

	for (count = 0; stream.Set() ; count ++){
		avr += stream.Get();
	}
	if (count == 0){
		return false;
	}
	avr /= count;
	cout << "the average is " << avr << "." << endl;
	return true;
}
int main(int argc, char const *argv[])
{
	while(true){
		InputStream stream;
		if(!Average(stream)){
			break;
		}
	}
}