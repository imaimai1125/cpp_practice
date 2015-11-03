#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int WIDTH = 16;
int main(){
	fstream file;
	file.open("8_9_hello.txt" , ios::in|ios::binary);
	if(!file.is_open()){
		return EXIT_FAILURE;
	}

	do{
		unsigned char buf[WIDTH];
		file.read((char*) buf, sizeof buf);
		//file.gcount
		cout << file.gcount() << endl;
		for (int i = 0, size = file.gcount(); i < size ; ++i)
		{
			printf("%02X ",buf[i]);
		}
		cout << endl;
		//file.eof()
	}while(!file.eof());
	file.close();
}