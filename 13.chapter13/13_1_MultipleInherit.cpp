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
基底クラスB
*******************/
class BBase{
public:
	virtual ~BBase(){}
	virtual void BHoge(){
		cout << "A::Hoge" << endl;
	} //純粋仮想関数
};
/*******************
継承クラス
*******************/
class C:
	public ABase,
	public BBase

{
public:
	virtual void AHoge(){
		cout << "C::AHoge" << endl;
	}
	virtual void BHoge(){
		cout << "C::BHoge" << endl;
	}
};
/*******************
main
*******************/
int main(){
	C c;
	//アップキャスト
	ABase& a = c;
	a.AHoge();
	BBase& b = c;
	b.BHoge();
	BBase bb;
	bb.BHoge();
}