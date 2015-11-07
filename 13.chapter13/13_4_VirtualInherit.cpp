#include <iostream>
using namespace std;

/**********************
基底クラスABase
**********************/
class ABase{
public:
	//コンストラクタ(引数xをとる)
	ABase(int x):m_x(x){}
	//デストラクタ
	virtual ~ABase(){}
	//このメンバ関数を継承したい。
	void Show(){
		cout <<  m_x << endl;
	}
protected:
	int m_x;
};
/**********************
クラスA1（ABaseの派生）
**********************/
class A1:virtual public ABase{
public:
	//デフォルトコンストラクタじゃなくなったので明示してやる
	A1() : ABase(1){}
public:
	void Show1(){
		cout << "good morning!" << endl;
	}
};
/**********************
クラスA2（ABaseの派生）
**********************/
class A2:virtual public ABase{
public:
	A2(): ABase(2){}
//仮想継承して、2つ共におなじ関数があるとambigousとなってエラーを吐く
// public:
	// void Show1(){
		// cout << "hello" << endl;
	// }
};
/**********************
クラスC（A1，A2の派生）
**********************/
class C:
	public A1, public A2
{
public:
	C(int x): ABase(x){}
};

/**********************
main
**********************/
int main(){
	A1 a1;
	A2 a2;
	C c(5);
	a1.Show();
	a2.Show();
	c.Show();
	c.Show1();
}


