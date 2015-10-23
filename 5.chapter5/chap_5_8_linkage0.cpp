#include <iostream>
using namespace std;

//外部リンケージ
int a = 2;
void Func(){
	cout << "a = " << a <<endl;
}

//内部リンケージ
static int b = 9;
static void Func1(){
	cout << "b(1) = " << b << endl;
}
void Func2(){
	Func1();
}