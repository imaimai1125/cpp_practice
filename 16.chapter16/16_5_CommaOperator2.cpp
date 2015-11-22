//int型を入力しつづける限り足し合わせることができるプヨグラム
//コンマ演算子を使ってうまく使う．

#include <iostream>
using namespace std;

int main(){
	int sum = 0;
	int n;
	cout << "input the number -> " << flush;
	while(cin >> n, !cin.fail()){
		cout << "input the number -> " << flush;
		sum += n;
	}

	cout << "the sum of your Input is -> " << sum << endl;
}