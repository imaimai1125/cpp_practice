#include <iostream>
#include <cstdio>

using namespace std;

//3.2 参照
//ここの引数の＆によって参照という特殊な変数を作ることができる。
void WesternToShouwa(int& x){
	if(1926<=x && x <= 1989){
		x -= 1925;
	}else{
		x = 0;
	}
}
void Shouwa(){
	int year;
	cout << "Input the western year here. " << flush;
	cin >> year;
	WesternToShouwa(year);
	if(year == 0){
		cout << "This year is not in Shouwa." << endl;
	}else{
		cout << "This year is " << year << " in Shouwa" << endl;
	}
}
//文字コード
void ShowCode(char ch){
	cout << "Ther number of [" << ch << "] is" 
	<< (int)(unsigned char)ch << "." << endl;  
}


//3.5 文字列走査
int f(int x, int y){
	return 2*x+y;
}
void Show(int x, int y){
	char str[50];
	sprintf(str, "f(%d,%d) = %d", x,y,f(x,y));
	cout<<str<<endl;
}


//3.6関数プロトタイプ
int Prototypef(int x,int y);

int main(){
	//3.2
	Shouwa();
	//3.3
	ShowCode('a');
	ShowCode('b');
	//3.4
	char hello[] = "a";
	cout << "convert [hello] to Character code" << endl;
	for (int i = 0; i < (int)sizeof hello; ++i){
		cout << (int)(unsigned char)hello[i]<<" ," ;
	}
	cout << endl;
	//3.4 extra　文字コード⇒文字
	for (int i = 90; i < 128; ++i)
	{
		cout << (unsigned char)i << " ,";
	}
	//3.5 文字列、sprintf
	char aisatsu[] = "konnnitiwa!";
	//aisatsu[4] = '\0';
	cout << "convert the character of ["<<aisatsu<<"]"<<" to the character code" <<endl;
	for (int i = 0; aisatsu[i] != '\0'; ++i){
		cout << (int)(unsigned char)aisatsu[i] << ", ";
	}
	cout<<endl;
	Show(1,2);
	cout << Prototypef(2,3) << endl;
}

int Prototypef(int x,int y){
	return x*x+y*y;
}