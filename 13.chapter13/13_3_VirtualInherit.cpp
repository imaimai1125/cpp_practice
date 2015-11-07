#include <iostream>
using namespace std;

/**********************
基底クラスABase
**********************/
class ABase{
public:
	//コンストラクタ(m_x(0)を引数にもつ)
	ABase():m_x(0){}
	//デストラクタ
	virtual ~ABase(){}
	void Set(int x){m_x = x;}
protected:
	int m_x;
};
/**********************
クラスA1（ABaseの派生）
**********************/
class A1:virtual public ABase{};
/**********************
クラスA2（ABaseの派生）
**********************/
class A2:virtual public ABase{};
/**********************
クラスC（A1，A2の派生）
**********************/
class C:
	public A1, public A2
{
public:
	void Show(){
		cout << A1::m_x<<", "
			 << A2::m_x<< endl;
	}
};

/**********************
main
**********************/
int main(){
	C c;
	c.Show();
	//upcast
	A1& a1 = c;
	A2& a2 = c;
	//継承のときにvirtualがなければ別々に扱われる。
	//今回は仮想継承なのでメンバ変数の変更が共有される
	a1.Set(1);
	c.Show();

	a2.Set(2);
	c.Show();
}



