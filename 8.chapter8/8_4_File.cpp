#include <iostream>
//ファイルの取り扱い
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	fstream file;
	file.open("8_4_test.txt",ios::out);
	if(! file.is_open()){
		return EXIT_FAILURE;
	}
	file << "ファイルに書き込んじゃいますね？？？" << endl;
	file << "二行目を書き込みます" << endl;
	file.close();
}