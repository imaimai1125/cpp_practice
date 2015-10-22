#include <iostream>
using namespace std;

enum CompareResult{
	//数字はtrueの1くらいの役割
	//数字は省略しても自動で補間してくれる。
	CR_LESS_THAN = 0,
	CR_EQUAL_TO = 1,
	CR_MORE_THAN = 2,
};
#include <iostream>
using namespace std;

CompareResult Compare(int a, int b){
	if(a<b){
		return CR_LESS_THAN;
	}else if(a>b){
		return CR_MORE_THAN;
	}else{
		return CR_EQUAL_TO;
	}
	/****************************************
	?演算子を使って書くとこう
	return a<b ? CR_LESS_THAN :
		   a>b ? CR_MORE_THAN :
		   CR_EQUAL_TO;
	****************************************/
}

bool Compare(){
	int a = -1;
	int b;
	cout << "Input 2 numbers." << endl;
	cin >> a >> b;
	if(a==-1){
		return false;
	}
	//switch文を使って条件分岐をする
	switch(Compare(a,b)){
		case CR_LESS_THAN:
			cout << "former is less than later.";
			break;
		case CR_EQUAL_TO:
			cout << "former is equal to later.";
			break;
		case CR_MORE_THAN:
			cout << "former is more than later.";
			break;
	}
	return true;
}

int main(){
	while(Compare());
	CompareResult comp = CR_LESS_THAN;
	/****************************************
	CompareResult comp = 3; はエラー
	
	CompareResult como = (CompareResult)9;
	cout << como << endl;

	とすると、通ってしまう。
	この危険性についてはよくわからないので後で聞く。
	*****************************************/
}