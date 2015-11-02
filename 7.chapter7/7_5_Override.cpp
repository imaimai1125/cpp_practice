#include "7_1_1_InputStream.h"
#include <iostream>
using namespace std;

int main(){
	// Streamを純粋抽象クラスにしたので実体を作れなくなった。
	
	// Stream stream;
	// stream.Set();
	// cout << stream.Get() << endl;
	InputStream istream;
	cout << "> " <<flush;
	istream.Set();
	cout << istream.Get()<<endl;
}