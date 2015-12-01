#include <iostream>
using namespace std;

void Error(){
	int* p = NULL;

	try{
		p = new int[10];
		throw "Error Occurs!";
		delete [] p;

	}catch(...){
		cerr << "メモリを開放します" << endl;
		delete[] p;
		throw;
	}
}

int main(){
	try{
		Error();
	}catch(const char* error){
		cout << error << endl;
	}

}