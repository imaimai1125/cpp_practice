#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
	const char* error = NULL;
	ifstream file;
	string line;

	file.open("test.txt");
	if(!file.is_open()){
		error =  "File cannot be opened!" ;
		goto ON_ERROR;
	}

	getline(file,line);
	if(file.fail()){
		error = "File cannot be read!" ;
		goto ON_ERROR;
	}
	cout << line << endl;
	//エラー処理は、エラーされた時にだけ実行してほしいから。
	return EXIT_SUCCESS;

ON_ERROR:
	cerr << error << endl;
	return EXIT_FAILURE;
}