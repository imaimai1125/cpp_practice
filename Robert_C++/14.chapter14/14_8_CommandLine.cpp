//コマンドライン引数とその個数を表示させるようなプログラム

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "argc = " << argc << endl;
	for (int i = 0; i < argc; ++i){
		cout << "argv[" << i << "] = " << argv[i] << endl;	
	}
	return 0;
}