#include <iostream>
#include <cstdlib>
using namespace std;

//WINDOWSは./をつけなくてもいいが，他のはつけないといけない
//というのをマクロで定義している．
#ifdef WINDOWS
#define CURRENT
#else 
#define CURRENT "./"
#endif //WINDOWS

//14.2で作ったファイルが実行できるか否かを判断して返す
const char FILENAME[]  = CURRENT "14_2.exe";

int main(){
	if(system(FILENAME) == 0){
		cout << "プログラムは正常に実行されました．"<<endl;
		return EXIT_SUCCESS;
	}else{
		cerr << "実行に失敗しました" << endl;
		return EXIT_FAILURE;
	}
}