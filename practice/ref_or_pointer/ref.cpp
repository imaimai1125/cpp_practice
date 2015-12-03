#include <iostream>
using namespace std;
//参照についてのりかいを深める
//2015.12.2

void func1();
void func2(int& bar);

class Hoge{
public:
	Hoge(){
		m1 = 2;
	}
	~Hoge(){cout << "destructor"<<endl;}
public:
	int getm(){return m1;}
	void setm(int m){m1 = m;}
	void show(){cout << m1 << endl;}
private: 
	int m1;
};


int main(){
	int foo = 10;
	//定数値への参照はできない
	//参照を宣言した時は必ず対象を代入
	int& bar = foo;
	bar = 30;
	//barの値を変えているのではなく
	//barが指し示しているfooの値を変えている
	//参照は一度宣言するとその元を変えることは不可
	cout << foo << endl <<bar <<endl;
	cout << &foo << endl << &bar << endl;
	func1();

	Hoge hoge;
	hoge.setm(200);
	hoge.show();


}


void func1(){
	int foo = 10;
	func2(foo);
}
//仮引数が参照なら自動的に参照渡しになる．呼び出し元の引数は特に加工する必要なし
void func2(int& bar){ //参照の使用を明示的に宣言
	++bar;
	cout << bar << endl; 
}
