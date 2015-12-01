#include <iostream>
using namespace std;

class Hoge{
public:
	Hoge(int n):m_n(n) 	{cout<<"Hoge  : " << m_n << endl;}
	Hoge(const Hoge&) 	{cout<<"Hoge& : " << m_n << endl;}
	void operator=(const Hoge&) 	{cout<<"Hoge= : " << m_n << endl;}
	virtual ~Hoge() {cout<<"~Hoge : " << m_n << endl;}

private:
	int m_n;
};

void Viss(int n){
	cout << n << endl;
}

//11.7 関数としてクラスを返す。
Hoge Two(){
	Hoge n(2);
	return n;
}

int main(){
	Viss(0);
	Hoge hoge(1);
	Viss(1);
	// テンポラリオブジェクトHoge(2)
	hoge = Hoge(2);
	Viss(2);

	// cout << "***11.7***" << endl;
	// Hoge hoge2(5);
	// hoge = Two();
}

/********************
処理の流れ
1．コンストラクタでオブジェクトが作られる
2．Hoge(2）によりテンポラリオブジェクトが作られる
3．テンポラリオブジェクトがhogeに代入される
4．テンポラリオブジェクトが破棄
5．main関数終了時に破棄
5．
********************/