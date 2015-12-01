#include <iostream>
//例外の基底
#include <exception>
using namespace std;

class Hoge{
public:
	Hoge();
	virtual ~Hoge();
};

Hoge::Hoge(){cout<<"Hoge"<<endl;}
Hoge::~Hoge(){cout<<"~Hoge"<<endl;}

class Base{
public:
	Base();
	virtual ~Base();
};

Base::Base(){cout<<"Base"<<endl;}
Base::~Base(){cout<<"~Base"<<endl;}


//Derivedは、Baseクラスの派生クラスになっている
//更に、メンバ変数にHogeのコンストラクタを持っている。
//つまり、Derivedが呼び出されるとHogeとBaseも同時に呼び出される。
class Derived:
	public Base
{
public:
	Derived();
	virtual ~Derived();

private:
	Hoge m_hoge;
};

Derived::Derived(){throw exception();}
Derived::~Derived(){cout<<"Derived"<<endl;}

int main(){
	try{
		Derived d;
	}catch(const exception& e){}
}
//例外処理が行われた場合、そのクラスのコンストラクトは必ず失敗しているため
//デストラクタは呼ばれない！