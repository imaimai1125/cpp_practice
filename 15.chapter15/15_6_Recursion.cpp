#include <iostream>
using namespace std;


void CountDown1();
void CountDown2(int n);
unsigned int Factorial(unsigned int n);

int main(){
	// CountDown1();
	// CountDown2(10);
	int i =0;
	cout << "Input the Integer, and I calculate the product of your num." << endl;
	cout << " --> " << flush;
	cin >> i;
	cout << "The product of " << i << " is " << Factorial(i) << endl;
}

//グローバル変数を使わなくちゃいけない	
int i = 20;
void CountDown1(){
	if(i>0){
		cout << i << endl;
		--i;
		CountDown1();
	}
}

//引数ありver.グローバル変数を使わなくて済む
void CountDown2(int n){
	//終了条件
	if(n>0){
		cout << n << endl;
		//再帰
		CountDown2(n-1);
	}
}

//積
unsigned int Factorial(unsigned int n){
	// if(n>0){
	// 	return n*Factorial(n-1);
	// }else{
	// 	return 1;
	// }

	//こっちのがsmarter
	return n == 0 ? 1:n*Factorial(n-1);
}