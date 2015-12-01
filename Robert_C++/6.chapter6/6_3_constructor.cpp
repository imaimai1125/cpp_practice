#include <iostream>
using namespace std;

class Integer{
public:
	int m_value;

	void Show();
	//コンストラクタの宣言 
	Integer();
	Integer(int num);
};

//コンストラクタ 初期値入力
Integer::Integer(){
	m_value = 0;
}
//6.4コンストラクタに引数を持たせたい時
Integer::Integer(int num){
	m_value = num;
}

//メンバ変数の表示
void Integer::Show(){
	cout << m_value << endl;
}

int main(int argc, char const *argv[])
{
	// コンストラクタがあるので、呼び出した時に初期化されている。
	Integer a(2),b;
	Integer c(10);

	a.Show();
	b.Show();
	c.Show();
}