#include "7_10_HalfInputStream.h"

main(){
	HalfInputStream histream(10);
	//エラーの元
	histream.SetBase();
	cout<<histream.Get()<<endl;;
}