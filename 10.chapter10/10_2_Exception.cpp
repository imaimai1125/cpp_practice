#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
	try{
		ifstream file;
		file.open("test.txt");
		if(!file.is_open()){
			throw  "File cannot be opened!" ;
		}
		
		
		string line;
		getline(file,line);
		if(file.fail()){
			throw  "File cannot be read!" ;
		}
		cout << line << endl;
	}//try
	catch(const char* error){
		cerr << error << endl;
		return EXIT_FAILURE;
	}
}