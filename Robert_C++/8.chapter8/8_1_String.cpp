#include <iostream>
#include <string>
using namespace std;

int main(){
	string hello = "hello";
	cout << hello << endl;
	hello = "HELLO";
	cout << hello << endl;
	hello += " WORLD!!" ;
	cout << hello << endl;
	cout << hello << "を文字コードに変えると" << endl;
	for (int i = 0 , size = hello.size(); i < size ; ++i){
		cout << (int)(unsigned char)hello[i] << ",";
	}
	cout << endl;
	cout << "になります" << endl;
}