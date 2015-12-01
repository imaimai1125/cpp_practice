#include "9_6_Array.h"
#include <iostream>
using namespace std;

int main(){
	//初期化(入力する値を決定できる)
	Array<double> array(10);
	for (int i = 0, size = array.Size(); i < size; ++i){
		array.Set(i,i*2.2);
	}
	for (int i = 0; i < array.Size(); ++i){
		cout << array.Get(i) << " ";
	}
	cout << endl;
}