#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	//書き込み
	fstream file;
	file.open("8_8_binary.txt", ios::out|ios::binary);
	if(!file.is_open()){
		return EXIT_FAILURE;
	}
	int n = 0x41424344;
	//第一引数は先頭アドレス、第二引数は変数のバイト数
	file.write((const char*)&n, sizeof n);
	file.close();
 	
	//読み込み
	fstream rfile;
	rfile.open("8_8_binary.txt", ios::in|ios::binary);
	if(!rfile.is_open()){
		return EXIT_FAILURE;
	}
	int m;
	rfile.read((char*) &m, sizeof m);
	file.close();
	cout << m << endl;
	
}