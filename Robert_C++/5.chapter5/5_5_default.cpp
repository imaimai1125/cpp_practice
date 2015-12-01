#include <iostream>
using namespace std;

int sum(int a,int b,int def1 = 1 ,int def2 = 2){
	return a + b + def1 + def2;
}
int product(int a,int b,const int& c){
	return a*b*c;
}

int main(int argc, char const *argv[])
{
	cout << sum(1,2) << endl;
	cout << sum(1,2,2) << endl;
	// cout << sum(1,2,,3) << endl; これはエラー
	cout << sum(1,2) <<endl;

	int c = 2;
	cout <<product(1,2,c)<<endl;
}