#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//ファイルを開く。
//開かなければ例外を投げる
void Open(ifstream& file, const char* filename){
	file.open(filename);
	if (!file.is_open()){
		throw  "File cannot be opened!" ;
		
	}
}

//ファイルから一行取得する
void GetLine(ifstream& file, string& line){
	getline(file, line);
	if(file.fail()){
		throw  "File cannot be read!" ;
	}
}

int main(){
	try{
		ifstream file;
		Open(file,"test.txt");
		string line;
		GetLine(file,line);
		cout << line << endl;
	}//try
	catch(const char* error){
		cerr << error << endl;
		return EXIT_FAILURE;
	}
}