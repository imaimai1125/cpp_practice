#include <iostream>
using namespace std;

int main(){
	union{
		unsigned int i;
		unsigned int b4:2;
	};
	// i = 0x12345678;
	i = 5;
	//２進法にすると5は101
	//２ビットで区切ると，上の100は考慮されず，01が反映される
	cout << i << endl;
	//下から4bitにどういう値のが入っているか
	cout << b4 << endl;
}
