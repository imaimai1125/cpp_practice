#include <iostream>
#include <cassert>
using namespace std;

//配列のサイズ取得
#define ARRAY_SIZE(array)(sizeof(array)/sizeof* array)

//四則演算
int Add(int a, int b){return a+b;}
int Sub(int a, int b){return a-b;}
int Mul(int a, int b){return a*b;}
int Div(int a, int b){return a/b;}

//四則演算を行う関数をまとめた関数ポインタの配列
//四則演算の関数を渡せる．すごい．
int (*const FP_OPERATOR[])(int a, int b) = {
	Add,Sub,Mul,Div
};
///演算名
const char* const OPERATION_NAME[] = {
	"加法","減法","乗法","除法"
};
/******************************************
入力した値に四則演算を順に適用した結果を出力するクラス
******************************************/

class Calculator{
public:
	void Run();
private:
	bool Input(); //二つの値を入力
	void Calculate();//二つの値を演算
private:
	int m_a, m_b;
};
/****************
実装
****************/

//処理の実行
void Calculator::Run(){
	while (Input()){
		Calculate();
	}
}
//二つの値を入力
bool Calculator::Input(){
	cout <<"2つの値を入力してください" << flush;
	m_b = 0; //入力が変な場合はm_bが0から変更されずfalse
	cin >>m_a >> m_b;
	return m_b != 0;
}
//二つの値を演算
void Calculator::Calculate(){
	static const size_t SIZE = ARRAY_SIZE(FP_OPERATOR);
	assert(SIZE == ARRAY_SIZE(OPERATION_NAME));

	for (size_t i = 0; i < SIZE; ++i)
	{
		int result  = FP_OPERATOR[i](m_a,m_b);
		cout << OPERATION_NAME[i] << " : " << result << endl;
	}
}

int main(){
	Calculator calc;
	calc.Run();
}









