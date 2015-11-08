#include <iostream>

namespace Hoge{
	using namespace std;
	void Hello(){
		cout << "Hello" << endl;
	}
}
int main(){
	Hoge::Hello();
}