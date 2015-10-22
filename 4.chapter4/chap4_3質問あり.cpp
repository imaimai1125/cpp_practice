/******************************
constの扱い方がいまいちわからないので。
わからないところ
１．ポインタにconstを付けるメリット。付けることで参照先のアドレスと確保するメモリの長さを固定できるけど
そもそもここを変更するような処理があるのか？一度変数の場所を決めてしまえば固定されているのでは？
２．ポインタの要素はポイントで返すのか？l.18-l.20
３．char *const MONTH_NAMEはいったいどういう構造しているの？
一つ一つの要素が文字列のポインタ、つまりMONTH_NAMEの各要素のアドレスを参照できるということになっているということ？
４．l.16で行われているのはポインタの初期化・ポインタ内の変数の初期化・
ポインタ（参照アドレスと長さ）の固定・ポインタ内変数の固定　でよい？？
５．関数へのconstは変数やポインタのconstと何か違うことがあるのか？
******************************/

#include <iostream>
using namespace std;
//ポインタへのconstは参照先のアドレスと確保するメモリの長さを固定する。（箱を固定）
//変数へのconstは値を固定する
const char* const MONTH_NAME[] = {
	"January","February","March","April","May","June",
	"July","August","September","October","November","December"
};
//関数へのconstは
const char* GerOldMonthName(const int month){
	/*************************
	//以下のような変更をconst int month
	month += 1;
	****************************/
	if(1<=month&&month<=12){
		return MONTH_NAME[month-1];
	}
	return 0;
}
int main(){
	/*************************
	//以下のような変更をconst MONTH_NAMEは許さない
	MONTH_NAME[0] = "january";
	cout<<MONTH_NAME[0]<<endl;
	****************************/
	int month = 11;
	cout<<"What month is it now?" <<flush;
	cin >> month;
	
	const char* name = GerOldMonthName(month);

	if(name == 0){
		cout << "Such month doesnt exist" << endl;
	}else{
		cout << name << endl;
	}
}

