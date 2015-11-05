#include <iostream>
using namespace std;

int main(){
	int a=0,b=0;
	a = (b=5);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;
	cout << "b = " << (b += 3) << endl;
	cout << "b = " << b << endl << endl;

	(b=2) += a;
	cout << "b = " << b << endl<<endl;

	a = b = 0;
	a = (++b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;
	

	//これだけbが1増える前にaに代入される
	//後置インクリメント
	a = b = 0;
	a = (b++);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;
}