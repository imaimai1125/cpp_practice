#include <iostream>
using namespace std;

int Bit(int x){
	return 1 << x;
}

//それぞれの記号の反転器
const int SHOW_X = Bit(0);
const int SHOW_Y = Bit(1);
const int SHOW_Z = Bit(2);

void Show(int flags){
	cout << ((flags & SHOW_X) != 0 ? "X" :"x")
		 << ((flags & SHOW_Y) != 0 ? "Y" :"y")
		 << ((flags & SHOW_Z) != 0 ? "Z" :"z")
		 << endl;
}
int main(){
	//Showの引数はどのビットが立つかを記述している。
	//ひとけた目がX...となっている
	Show(1);
	Show(SHOW_X);
	Show(SHOW_X|SHOW_Z);
	Show(SHOW_X|SHOW_Y|SHOW_Z);
	
	int flags;
	//ORで足す
	flags |= SHOW_Y|SHOW_Z;
	cout << flags << endl;
	//NANDで削除
	flags &= ~SHOW_Y;
	cout << flags << endl;
	//XORで反転
	flags ^= SHOW_X;
	cout << flags << endl;

}
