//5.3のenumを文字列リテラルで簡単にする
#include <iostream>
using namespace std;

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

//比較（？演算子）
CompareResult Compare(int a, int b){
	return a<b ? CR_LESS_THAN :
		   a>b ? CR_MORE_THAN :
		   CR_EQUAL_TO;
}

bool Compare(){
	//配列にするといちいち各要素の文字列の長さが必要になっちゃう
	//
	//char*　をつかう
	//毎回初期化する必要はないのでstaticをつけると良い
	
	static	const char* message[] = {
		"former is less than later",
		"former is equal to later",
		"former is more than later"
	};

	int a = -1;
	int b;
	cout << "Input 2 numbers." << endl;
	cin >> a >> b;
	if(a==-1){
		return false;
	}
	cout << message[Compare(a,b)] << endl;
	return true;
}

int main(){
	while(Compare()){
	}
	char str[] = 
	"this is a pen.";
	cout<<sizeof str<<endl;
	for (int i = 0; i < str[i] !=0; ++i){
		cout << (char)str[i] << " ";
	}
	// for (int i = 0; i<sizeof str[]; ++i)
	// {
	// 	cout>>str[i]>>" ";
	// }
}