#include "14_5_Debug.h"
#ifdef NDEBUG //リリース時
#else //デバッグ時

#include <iostream>
#include <cstdlib>
using namespace std;

namespace Debug{
	void Assert(bool b, const char* file, int line){
		if(b){
			//この条件は常に真じゃないといけない
		}else{
			///バグがでるときはファイル名，番号を出して強制終了
			cerr << file << "(" << line << ")"
			<< ": Assertion Error!" << endl;
			exit(EXIT_FAILURE);
		}
	}
}

int main(){
}

#endif //#ifdef NDEBUG
