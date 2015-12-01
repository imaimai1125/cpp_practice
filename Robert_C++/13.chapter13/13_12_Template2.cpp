#include <iostream>
using namespace std;

template<int N>
 class SBit
{
public:
	static const int Value = 1 << N;
};

int main(){
	cout << SBit<0>::Value << " "
		 << SBit<1>::Value << " "
		 << SBit<2>::Value << " " << endl;

	//関数は動的なのでarrayに打ち込むのは無理だけど、
	//こいつは静的なのでぶち込める
	//マクロでもぶち込めるようなものを作ることは可能
	//#define BIT(x) (1<<(int)x)
	int array[SBit<5>::Value];

}