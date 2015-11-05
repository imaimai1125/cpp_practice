#include <iostream>
using namespace std;
class Count{
public:
	Count();
	virtual ~Count();
	//静的メンバ関数
	static void Show();
private:
	static int m_count;
};

int Count::m_count;
Count::Count(){
	++m_count;
	cout << "Count::Count" << endl;
}
Count::~Count(){
	--m_count;
	cout << "Count::~Count" << endl;
}

void Count::Show(){
	cout << m_count << endl;
}

int main(){
	Count::Show();
	Count a;
	Count::Show();
	{
		Count b;
		Count::Show();
	}
	Count::Show();
}