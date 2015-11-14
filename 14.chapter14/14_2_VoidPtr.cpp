#include <iostream>
using namespace std;

int main(){
	char c = '1';
	int i = 2;
	double d = 3;
	void * p;

	// ポインタ使うならvoidのままでは使えないのでキャストする
	p = &c;
	cout << *static_cast<char*>(p) << " ";
	
	p = &i;
	cout << *static_cast<int*>(p) << " ";

	p = &d;
	cout << *static_cast<double*>(p) << " ";
}