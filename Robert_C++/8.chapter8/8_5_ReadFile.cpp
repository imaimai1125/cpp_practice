#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
	fstream file;
	file.open("8_4_test.txt", ios::in);
	if(! file.is_open()){
		return EXIT_FAILURE;
	}
	string str;
	//読み込み
	getline(file, str);
	file.close();
	cout << str << endl;	
	//二行目以降はどうするんやろ？？？
}