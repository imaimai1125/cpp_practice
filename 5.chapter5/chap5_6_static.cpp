#include <iostream>
#include <algorithm> //fill_nを使うためのヘッダファイル
using namespace std;

/*******************************
アドレスが一定かどうか
*******************************/
void CheckAddress_Sub();
void CheckAddress_Sub2();
void CheckAddress(){
	cout << "***Check if the address of static variable is constant." << endl;
	CheckAddress_Sub();
	CheckAddress_Sub2();
	CheckAddress_Sub();
}
//静的変数a,自動変数b
void CheckAddress_Sub(){
	static int a;
	int b;
	cout <<"&a = "<< (size_t)&a << endl
		 <<"&b = "<< (size_t)&b << endl;
}
//この関数の中からCheckAddres_Subを読んだときに
//変数a,bのアドレスがどうなるか
void CheckAddress_Sub2(){
	cout << "in sub2, the address of automatic variable has changed,"<<endl
		 << "however, that of static one has not." << endl;
	CheckAddress_Sub();
}
/*******************************
初期化は本当に一回なのか
*******************************/
void CheckInitOnce_Sub();
void CheckInitOnce(){
	cout << "***Chack if initialize has been carried out only oncce." << endl;
	CheckInitOnce_Sub();
	cout << "a has changed, however, b has not changed." << endl
		 << "This is because a is initialized only once." << endl;
	CheckInitOnce_Sub();	
}
//二度目以降の呼び出しにa++,b++の影響を受けるのか
void CheckInitOnce_Sub(){
	static int a = 3;
	int b =3;
	cout << "a = " << a << endl
		 << "b = " << b << endl;
	++a;
	++b;
}

/*******************************
0で初期化されているのか
*******************************/
void CheckZeroInit_Sub();
void CheckZeroInit_Sub2();
void CheckZeroInit(){
	cout << "***Check if static variable is initialized as 0 without declaration." << endl;
	CheckZeroInit_Sub();
	CheckZeroInit_Sub2();
	cout << "static variable is always initialized as 0," << endl
		 << "however, automatic one is initialized at random." <<endl; 

}

//静的変数が何で初期化されているのかcheck
void CheckZeroInit_Sub(){
	static int a, b, c;
	cout << a << " " << b << " " << c <<endl;
}
//自動変数が何で初期化されているのかcheck
void CheckZeroInit_Sub2(){
	int a,b,c;
	cout << a << " " << b << " " << c <<endl;
}

/*******************************
値が保障されているのか
*******************************/
void CheckInvariant_Sub(int*& pa, int*& pb);
void CheckInvariant_Sub2();
void CheckInvariant(){
	cout << "***Check if the value is preserved." << endl;
	int *pa, *pb; //*は両方につける（両方ポインタ）
	CheckInvariant_Sub(pa, pb);
	CheckInvariant_Sub2();
	// CheckInvariant_Sub2を呼んでもa,bの値が保存されているか
	cout << "*pa = " << *pa << endl
		 << "*pb = " << *pb << endl;
}
//静的変数aと自動変数bのアドレスを引数を通して返す
//int*&はint*への参照
void CheckInvariant_Sub(int*& pa, int*& pb){
		static int a = 9;
		int b = 9;
		pa = &a;
		pb = &b;
}
void CheckInvariant_Sub2(){
	//大きな変数を作ってソレをすべて0で埋める
	//fill_nは指定したデータで配列などを埋める関数みたいなもの。
	int dummy[100];
	fill_n(dummy, 100, 0);
}


/*******************************
main関数
*******************************/
int main(int argc, char const *argv[]){
	CheckAddress();
	CheckInitOnce();
	CheckZeroInit();
	CheckInvariant();
}