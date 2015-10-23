//3.7 ヘッダファイルを呼び出す
#include "chap3_2_include.h"
#include <iostream>
//3.8　擬似乱数
#include <cstdlib>
#include <ctime>
//3.9 数学関数
#include <cmath>

using namespace std;

//現在の時刻を乱数種として利用
void InitRand(){
	srand((unsigned int)time(NULL));
}

int Dice(){
	return rand()%6+1;
}
int Dice2(){
	return (int)(rand() /(RAND_MAX+1.0)*6)+1;
}

//3.10,3.11　bool,オーバーロード
//絶対値
int Abs(int a){
	if(a<0){
		return -a;
	}else{
		return a;
	}
}
double Abs(double a){
	if(a<0){
		return -a;
	}else{	
		return a;
	}
}
//入力(参照渡し)boolで書く
bool Input(int& i, double& d){
	cout<<"Input the number of Integer"<<flush;
	cin >> i;
	if(i == 0){
		return false;
	}
	cout <<"Input the shousuuchi" << flush;
	cin >> d;
	if( d == 0){
		return false;
	}
	return true;
}
//絶対値の表示
int ShowAbs(int i, double d){
	cout << "The abs of "<< i << " is " << Abs(i) <<endl;
	cout << "The abs of "<< d << " is " << Abs(d) <<endl;

}


/*******************************
main関数
*******************************/
int main(){
	//ヘッダファイル内に書かれた関数
	Hello();
	InitRand();
	for (int i = 0; i < 20; ++i){
		cout << Dice() + Dice() << " ";
	}
	cout << endl;
	for (int i = 0; i < 20; ++i){
		cout << Dice2() + Dice2() << " ";
	}
	cout << endl;

	double a = 1;
	double b = 1;
	cout << "二辺の長さをInputしてください -- " << flush;
	cin >> a >> b;
	cout << "the length of Shahen is " << sqrt(a*a+b*b) << "." << endl; 

	//falseにならない限り操作を実行し続ける。boolのほうがわかりやすい
	int i=0;
	double d=0;
	int lim = 0;
	while(Input(i,d)||lim<5){
		ShowAbs(i,d);
		lim ++;
	}
	cout<<endl;
	//3.12
	bool l = false;
	cout<<(int)l<<endl;
}



void Hello(){
	cout<<"Hi, Hello!"<<endl;
}