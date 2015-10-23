#include <iostream>
//↑includeじゃない。。。？


//別の場所で定義された外部リンケージのグローバル変数を扱うという宣言になる
//ほかのファイルまでわたっていけるような変数
extern int a;
//関数プロトタイプを書くと、別の場所で定義された外部リンケージを扱うという宣言になる
void Func();
//エラー出る。linkage0のstaticのやつを無理やり書き換えようとしているから？
// static int b = 2;
// void Func1(){
// 	cout << "b(1) = " << b << endl;  
// }
// void Func2();

int main(int argc, char const *argv[])
{
	Func();
	a = 5;
	Func();

	Func1();
	Func2();
	b = 5;
	Func1();
	Func2();
}