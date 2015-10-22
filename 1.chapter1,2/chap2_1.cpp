#include <iostream>
using namespace std;

//2.3 関数：mainの外にかく
int f(int x,int y){
	return 2 * x + y*y;
}
//2.4 戻り値のない関数もOK
void show(int x, int y){
	cout << "f(" << x << "," << y << ") = " << f(x,y) << endl; 
}
void hello(void){
	cout<<"hello world!!!!"<<endl;
}
void chapter(int a, int b){
	cout << "***chapter" << a << "," << b << "***" << endl;
}
//2.5 グローバル変数,ローカル変数
int a_global = 0;
void TEST(){
	//グローバル変数で定義するor関数内で定義するほかは受け付けない。
	int b_local = 1;
	cout << a_global << b_local<< endl;
}
//2.7 条件分岐
void BirthMonth(){
	int month;
	cout << "What month were u born? -- " << flush;
	cin >> month;

	if(1<=month && 12 >= month && month != 11){
		cout << "Oh, you were born in " << month << "!! :)" << endl;
	}else if(11 == month){
		cout << "Great! Your were born in the same month as I was !!" << endl;
	}else{
		cout << "Eh!? Such month doesnt exist!!!" << endl;
	}
}
//2.8 条件分岐2
void devide(){
	int a,b;
	cout << "Input first number. -- " << flush;
	cin >> a;
	cout << "Input next number. -- " << flush;
	cin >> b;
	if(b == 0){
		cout << "We cant devide by 0 :(" << endl;
	}else{
		cout << a << "/" << b << "=" 
			 << a/b << "..." << a%b << endl;
	}
}
void WesternToShowa(){
	int a;
	cout << "Input western year. -- " << flush;
	cin >> a;
	if (a > 1925 && a < 1990){
		cout << "Showa " << a-1925<< " nen" << endl;
	}else if(a == 1926){
		cout << "Showa " << "Gannen" << endl;
	}
	else{
		cout << "Error this year doesnt correspond to showa!!" << endl;
	}
}
//2.9 for文
void SumOfNumber(){
	int a;
	int sum = 0;
	cout << "Input the number here. -- " << flush;
	cin >> a;
	for (int i=1;i<=a;++i){
		sum += i;
	}
	cout << "The sum from 1 to "
		 << a << " is " << sum << endl;
}

int main()
{
	//2.1 引数をoutput
	int a;
	chapter(2,1);
	a = 0;
	cout << "a = " << a << endl;
	a = 2;
	cout << "2a = " << a*2 << endl;TEST();
	//2.2 計算　++ とか
	int b = 5;
	b*=b;
	chapter(2,2);
	cout << "b = " << b << endl; 
	//2.3 f = 2x + y^2
	chapter(2,3);
	cout << "f(100,10) = " << f(100,10) << endl;
	//2.4 戻り値のない関数はvoidやで！
	chapter(2,4);
	show(100,10);
	hello();
	//2.5　グローバル、ローカル
	chapter(2,5);
	TEST();
	//2.6 入力 cin 
	int in;
	//改行しないときはflush
	chapter(2,6);
	cout << "Input number here " << flush;
	cin >> in;
	cout << "amari of the number divided by 3 is " 
		 << in%3 << "." << endl;
	//2.7 if
	chapter(2,7);
	BirthMonth();
	//2.8 if 続き
	chapter(2,8);
	devide();
	WesternToShowa();
	//2.9 for
	chapter(2,9);
	SumOfNumber();
}

