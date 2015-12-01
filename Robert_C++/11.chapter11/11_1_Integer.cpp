#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int num = 0);
	void Show();
private:
	// メンバ変数をstaticにしてみる。
	static int m_value;
};

Integer::Integer(int num){
	m_value = num;
}

void Integer::Show(){
	cout << m_value << endl;
}
//staticの場合は実装により実体を作ってあげないといけない
int Integer::m_value;

int main(){
	Integer a(100),b(300);
	//staticの場合はクラスの全てで共有されるので、一番最後の300が全体に共有される。
	a.Show();
	b.Show();
}