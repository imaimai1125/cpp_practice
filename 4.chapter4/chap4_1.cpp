#include <iostream>
using namespace std;

//4.1
void Foo(){
int a;
char b[10];
cout << "a : " << (size_t)&a << endl
     << "b : " << (size_t)b << endl;

     // << "Foo : " << (size_t)Foo << endl;　
}
//4.4
void Init(int array[]){
	for (int i = 0; i < 5; ++i){
		array[i] = i*5;
	}
}
void Show(int array[]){
	for (int i = 0; i < 5; ++i){
		cout << array[i] << " " ;
	}
	cout << endl;
}

//4.5 関数で参照先を記述するのはあり。
void ShowAdress(char* pointer){
	cout << "pointer : " << (size_t)pointer << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "&pointer[" << i << "] : " << (size_t)&pointer[i] << endl;
	}
}

//4.7 
//配列
size_t Strlen(char* str){
	size_t i;
	for (i = 0; i < str[i]!= '\0'; ++i)
	{
		//何もしない
	}
	return i;
}
//ポインタ（アドレスの演算含む）
size_t Strlenp(char* str){
	char* p;
	for (p = str; *p != '\0' ; ++p){
	}
	return p-str;
}


void ShowLength(char* str){
	cout << "the length of " << str << " is " << Strlen(str)  << "bytes." <<endl;
	cout << "the length of " << str << " is " << Strlenp(str)  << "bytes." <<endl;
}


/**************************************
main関数
**************************************/
int main()
{
	Foo();
	//4.2ポインタの代入
	char a;
	char *p;
	p = &a;
	cout << "p = " << (size_t) p << endl;
	cout << "&a = " << (size_t)&a << endl;
	//4.4
	int n[5];
	Init(n);
	Show(n);
	//4.5
	//配列がアドレス上にどう配置されるかを確認
	//arrayと&array[0]が同じアドレスであることも確認
	char array[10];
	cout << "array : " << (size_t)array << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << " &array["  << i << "]:" << (size_t)&array[i] << endl;
	}

	cout << "Show adress by function." << endl;
	ShowAdress(array);

	//4.6
	int nn[5];
	cout<<"&n[2] = " << (size_t)&nn[2] << endl;
	//アドレスに1足したことになる。
	cout<<"&n[2] + 1 = " << (size_t)(&nn[2]+1 )<< endl;
	cout<<"&n[3] = " << (size_t)&nn[3] << endl;
	//アドレス同士の引き算
	
	cout<<"&n[2] - &n[3] = " << (size_t)(&nn[3] - &nn[2])<< endl;

	//4.7
	ShowLength("Hello. this is imai.");
	ShowLength("");
}