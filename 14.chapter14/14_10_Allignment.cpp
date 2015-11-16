#include <iostream>
using namespace std;

//バイト境界を決める
//#pragma pack(1)
struct Person{
	char name[21];
	int age;
	char birthmonth;
	char sex;
};

#pragma pack()
int main(){
	//peson構造体のサイズ
	cout << sizeof (Person) << endl;
	//構造体内各引数のアドレス
	cout << "      name : " << offsetof(Person,name) << endl
	 << "       age : " << offsetof(Person,age) << endl
	 << "birthmonth : " << offsetof(Person,birthmonth) << endl
	 << "       sex : " << offsetof(Person,sex) << endl;
}

