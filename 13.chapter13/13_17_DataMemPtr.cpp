/*メンバ変数ポインタ
今回は構造体で書いているが，もちろんクラス内のメンバ関数も然り*/

#include <iostream>
using namespace std;

#define ARRAY_SIZE(array) (sizeof (array)/sizeof *(array))

struct Point{
	int x,y;
};

//メンバ変数ポインタ
//Pointとという構造体の中でメンバ変数yはどの位置にあるのか
//を表している
//int Point::*mp = &Point::y;
//変数ポインタ
//int *p = &pt.y;
//これはメモリの中で，ある特定のオブジェクトptのメンバ変数yが
//どの位置にあるのかを表している．
//オブジェクトの実態一つにつき一つの宣言が必要．（pt1とpt2はアドレスが違う）

//inlineってなに？
inline void IncPointMem(Point *pt, int size, int Point::*mp){
	for (int i = 0; i < size; ++i){
		++(pt[i].*mp);
	}
}

void IncX(Point* pt, int size){
	IncPointMem(pt,size,&Point::x);
}

void IncY(Point* pt, int size){
	IncPointMem(pt,size,&Point::y);
}

void Show(const Point* pt, int size){
	for (int i= 0; i < size; ++i){
		cout << pt[i].x << ", " << pt[i].y << endl;
	}
}

int main(){
	Point pt[] = {
		{0,0},{1,1},{2,2},{3,3},
	};
	int size = ARRAY_SIZE(pt);
	IncX(pt,size);
	IncY(pt,size);
	IncX(pt,size);
	Show(pt,size);
}