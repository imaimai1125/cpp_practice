//そのクラスを使うソースファイルでそのヘッダファイルをインクルードする

#include "6_7_Test.h"

//6_7_Test.cppをインクルードしても良い
//6_7_Test.cppを同時コンパイルしてもいい
// void Test::Func(){
// 	a = 0;
// }

int main(){
	Test test;
	test.Func();

}