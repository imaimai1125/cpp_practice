#include <iostream>
#include <sstream>
using namespace std;

//渡した文字列を関数内で使うために参照渡しにしている。
void Add(stringstream& sstr, int x, int y){
	//文字列のクリア
	sstr.str(" ");
	//文字列の入力
	sstr << x << " + " << y << " = " << (x+y) << flush;
}
int main(int argc, char const *argv[])
{
	stringstream sstr;
	Add(sstr,2,4);
	string expr = sstr.str();
	cout << expr << endl;
	Add(sstr,4,5);
	cout << sstr.str() << endl;


	// 文字列を代入
	stringstream sstr2("1 2 3");
	int x,y,z;
	sstr2 >> x >> y >> z;
	cout << x << " + " << y << " + " << z << " = " << (x+y+z) <<endl;
}