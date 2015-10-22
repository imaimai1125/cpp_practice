#include <iostream>
#include "math.h"
using namespace std;
void chapter(int a, int b){
	cout << "***chapter" << a << "," << b << "***" << endl;
}

//2.11　配列の作成
int score[] = {34,13,33,5,31
			  ,24,43,11,22,99};
//2.14
bool prime(int n){
	int sqrt_n = sqrt(n);
	for (int i = 2; i <= sqrt_n; ++i){
		if(n%i == 0){
			return false;
		}		
	}
	return true;
}
//複雑なfor練習
int Insuubunkai(int n){
	//※ルートの使い方がわからない
	int insuu = 0;
	for (int i = 2; i < n; ++i){
		if(prime(i)){
			if(n%i == 0){
				insuu ++;
				int amari = 0;
				int power = 0;
				int divide = n;
				while(amari == 0){
					amari = divide % i;
					divide /= i;
					power ++;
				}
				cout << i <<"^"<< power-1 << "," << flush;
			}
		}
	}
	if(insuu == 0){
		cout << n << " is a prime number." <<endl;
	}
}

int main()
{
	//2.11 配列をfor文で簡素に演算
	chapter(2,11);
	int sum = 0;
	for (int i = 0; i < 10; ++i){
		sum += score[i];
	}
	cout << "The average score in this class is "
	<< sum/10 << "." << endl;
	//2.12　複雑なfor
	chapter(2,12);
	int num = 1;
	cout << "Input your number, and I will factorize it. -- " << flush;
	cin >> num;
	//因数分解のやつだけど、重すぎて使えない。もっと早いアルゴリズムを探す。
	Insuubunkai(num);
	//2.13 while文
	chapter(2,13);
	int a13 = 0;
	while(a13 < 100){
		cout << a13 << " ";
		a13 += 2; 
	}
	cout << endl;
}