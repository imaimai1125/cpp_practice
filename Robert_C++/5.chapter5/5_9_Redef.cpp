#include <iostream>
//マクロのおかげで二重定義しても大丈夫
#include "chap_5_9_Redef.h"
#include "chap_5_9_Redef.h"
using namespace std;
/***********************************
外部からの変数をグローバル変数として扱いたいなら
extern int N;
と宣言しといてやる
（ただし、外部の変数がconstなど内部リンケージなら不可
***********************************/
int main(){
	//ヘッダファイルのexternalを使っている
	cout << N << endl;
}
/******************************************
main関数内でヘッダファイルのconstを書き直そうとした結果
C:\Users\imaimai\Documents\sublime\c++\cpp_practice\5.chapter5\chap_5_9_Redef.cpp:8:4: error: assignment of read-only variable 'N'
  N = 1;
    ^
******************************************/
