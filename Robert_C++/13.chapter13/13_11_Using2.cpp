#include <iostream>
using namespace std;

class Show{
public:
	static void Value(char ch){cout << ch << endl;}
	static void Value(const char* str){cout << str << endl;}
};

class Show2:
	public Show
{
public:
	//同じ関数で違う引数のを一つだけオーバーライドしようとした時でも
	//すべてのメンバ関数をオーバーライドしなきゃダメ
	static void Value(char ch){
		int n = static_cast<unsigned char>(ch);
		cout << n << endl;
	}
	// static void Value(const char* str){
	// 	Show::Value(str);
	// }
	/************************************************************
	↑でもいいが、たくさん同じメンバ関数があると
	不便なので、usingを使いスッキリさせる
	こうすることで、基底クラスが持つオーバーロードされた
	Valueメンバ関数の宣言をその派生クラスにすべて取り込める
	************************************************************/
	using Show::Value;
};

int main(){
	Show2::Value("A");
	Show2::Value("Hoge");
}