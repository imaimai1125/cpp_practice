#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	int a,b;
	cout << "Input 2 numbers. --" << endl;
	cin >> a >> b;
	cout<<"bigger one is " << (a>b ? a:b) << endl;
	/*****************************************
	これと同値な値を返す
	if(a>b){
		cout<<"bigger one is " << "a" << endl;
	}else{
		cout<<"bigger one is " << "b" << endl;
	}
	*****************************************/
}