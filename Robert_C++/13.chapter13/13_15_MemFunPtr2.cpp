#include <iostream>
#include <cassert>
using namespace std;

//配列のサイズ取得
#define ARRAY_SIZE(array)(sizeof(array)/sizeof* array)
/************************
クラスの宣言
************************/
class Calculator{
public:
	void Run();
private:
	bool Input();
	void Calculate();
private:
	//四則演算を行う関数
	int Add() {return m_a + m_b;}
	int Sub() {return m_a - m_b;}
	int Mul() {return m_a * m_b;}
	int Div() {return m_a / m_b;}
	//四則演算を行う関数をまとめた配列ポインタ
	typedef int(Calculator::*FpOp2)();
	static const FpOp2 FP_OPERATOR[];
	//演算名
	static const char* const OPERATION_NAME[];
private:
	int m_a,m_b;
};
/**********************
四則演算を行う関数をまとめた配列関数ポインタ
**********************/
const Calculator::FpOp2 Calculator::FP_OPERATOR[] = {
	&Calculator::Add, &Calculator::Sub,
	&Calculator::Mul, &Calculator::Div
};
//演算子の名前
const char* const Calculator::OPERATION_NAME[] = {
	"加算","減算","乗算","除算"
};
//処理の実行
void Calculator::Run(){
	while(Input()){
		Calculate();
	}
}
//２つの値を入力
bool Calculator::Input(){
	cout << "Input 2 numbers" << endl;
	m_b = 0;
	cin >> m_a >> m_b;
	return m_b != 0;
}
//２つの値を演算
void Calculator::Calculate(){
	static const size_t SIZE = ARRAY_SIZE(FP_OPERATOR);
	assert(SIZE == ARRAY_SIZE(OPERATION_NAME));
	for(size_t i = 0; i<SIZE; ++i){
		int result = (this->*FP_OPERATOR[i])();
		cout <<OPERATION_NAME[i] << " : " << result << endl;
	}
}
int main(){
	Calculator calc;
	calc.Run();
}