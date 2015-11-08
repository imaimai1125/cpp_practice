#include <iostream>
//最大・最小などが定義されている
//USHRT_MAXIINT_MAX,INT_MINなどのマクロが入っている
//1バイトのビット数を取得するためのマクロCHAR_BITなどもある。
#include <climits>
#include <typeinfo>

using namespace std;
template <typename TYPE>
 class Limits
{
public:
	static const TYPE MIN;
	static const TYPE MAX;
};

//最大値と最小値を提供するクラステンプレート

//2種類の特殊化の方法がある。
//クラス宣言によるテンプレートの特殊化
template<>
 class Limits<unsigned short>
{
public:
	static const unsigned short MIN = 0; //TYPE型の最小値
	static const unsigned short MAX = USHRT_MAX; //TYPE型の最大値
};
//実体定義で特殊化
template <> const int Limits<int>::MIN = INT_MIN;
template <> const int Limits<int>::MAX = INT_MAX;

template <typename TYPE>
 void ShowMinMax(){
 	cout << "Type : " << typeid(TYPE).name() <<  endl
 	//最小値
		 << "  Min : " << Limits<TYPE>::MIN<<endl
	//最大値
		 << "  Max : " << Limits<TYPE>::MAX<<endl;
}

int main(){
	ShowMinMax<unsigned short>();
	ShowMinMax<int>();
}
