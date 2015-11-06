#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define ON_ERROR_GOTO(expr)\
	error = (expr);\
	if(error != NULL){ \
		goto ON_ERROR; \
	}


const char* Open(ifstream& file, const char* filename){
	file.open(filename);
	return file.is_open() ? NULL : "File cannot be opened";
}
const char* GetLine(ifstream &file, string& line){
	getline(file,line);
	return file.fail() ? "Fail to read line":NULL;
}

int main(){
	const char* error = NULL;

	ifstream file;
	string line;
	//マクロ設定をしておくことにより効率化
	//変数や関数などでまとめられない処理を一つにまとめることができる
	ON_ERROR_GOTO(Open(file,"test.txt"));
	ON_ERROR_GOTO(GetLine(file,line));

	cout << line << endl;
	return EXIT_SUCCESS;
ON_ERROR:
	cerr << error << endl;
	return EXIT_FAILURE;
}