#include "6_8_IntArray.h"
#include <iostream>
using namespace std;


int main(){
	IntArray a(5);
	IntArray b(5);	
	//aの値を定める
	for (int i = 0; i < a.Size(); ++i){
		a.Set(i,i+1);
	}
	//bはaをコピーし、各要素を2倍した値と定める
	//このタイミングで演算子オーバーロードが使われる。

	b = a;
	for (int i = 0; i < b.Size(); ++i){
		b.Set(i,b.Get(i)*2);
	}
	for (int i = 0; i < a.Size(); ++i){
		cout << a.Get(i) << " -> " << b.Get(i) << endl;
	}
	cout << "aをbの二倍にする" << endl;
	for (int i = 0; i < a.Size(); ++i)
	{
		a.Set(i,b.Get(i)*2);
	}
	for (int i = 0; i < a.Size(); ++i){
		cout << b.Get(i) << " -> " << a.Get(i) << endl;
	}

}