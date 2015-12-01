#include <iostream>
#include <exception>
using namespace std;


void OnTerm(){
	cerr << "異常終了です" << endl;
	abort();
}

int main(){
	set_terminate(OnTerm);
	throw exception();
}