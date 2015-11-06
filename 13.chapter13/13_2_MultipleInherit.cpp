#include <iostream>
using namespace std;
/*******************
基底クラスA
*******************/
class ABase{
public:
	//インラインメンバ関数
	virtual ~ABase(){}
	virtual void AHoge() = 0; //純粋仮想関数
};
/*******************
クラスA1
Aを継承
*******************/
class A1:
	public ABase
{
public:
	virtual void AHoge(){
		cout << "A1::Hoge" << endl;
	}
};
/*******************
クラスA2
Aを継承
*******************/
class A2:
	public ABase
{
public:
	virtual void AHoge(){
		cout << "A2::Hoge" << endl;
	}
};
/*******************
継承クラス
*******************/
class C:
	public A1,
	public A2
{
public:
	//オーバーライド
	//A1由来のAHogeとA2由来のAHogeが両方同じ形にオーバーライド

	virtual void AHoge(){
		cout << "C::AHoge" << endl;
	}
};
/*******************
main
*******************/
int main(){
	C c;
	//アップキャスト
	//オーバーライドされたcの関数を返す

	A1& a1 = c;
	A2& a2 = c;
	a1.AHoge();
	a2.AHoge();
	//スコープ解決演算子を使うとC::AHogeが呼ばれることなく指定した通りの関数が直接呼ばれる！	
	c.A1::AHoge();
	c.A2::AHoge();

	C c1;
	ABase& aa1 = static_cast<A1&>(c1);
	aa1.AHoge();

}