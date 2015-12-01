#include <iostream>
using namespace std;
class Count{
public:
	Count();
	virtual ~Count();
	void Show();
private:
	static int m_count;
};
//継承するとどうなるか
//Countを継承した派生クラスCount2
class Count2:public Count{};



int Count::m_count = 10;

Count::Count(){
	++m_count;
	cout << "Count::Count;" << endl;
}
Count::~Count(){
	--m_count;
	cout << "Count::~Count;" << endl;
}
void Count::Show(){
	cout << m_count << endl;
}

int main(){
	//静的メンバ変数がどう扱われるかチェック。
	Count a;
	a.Show();
	{
		Count2 b;
		a.Show();
		//派生クラスとか関係なくメモリ領域は1つしか存在しない。
		b.Show();
	}
	a.Show();
}