#include <iostream>
using namespace std;

/**********************
基底クラスABase
**********************/
class ABase{
public:
	//デフォルトコンストラクタ
	//デストラクタ
	virtual ~ABase(){}
	virtual void AHoge() = 0;
};
/**********************
クラスA1（ABaseの派生）
**********************/
class A1:virtual public ABase
{
public:
	virtual void AHoge(){
		cout << "A1::AHoge" << endl;
	}
};
/**********************
クラスA2（ABaseの派生）
**********************/
class A2:virtual public ABase
{
public:
	virtual void AHoge(){
		cout << "A2::AHoge" << endl;
	}	
};
/**********************
クラスC（A1，A2の派生）
**********************/
class C:
	public A1, public A2
{
public:
	virtual void AHoge(){
		cout << "C::AHoge" << endl;
		A1::AHoge();
		A2::AHoge();
	}
};

/**********************
main
**********************/
int main(){
	C c;
	ABase& a = c;
	c.AHoge();

}



