	#include <iostream>
	using namespace std;
//4.8 constの重要性
//strをミスって書き換えたりしちゃうと困る⇒constと宣言
int StrCount(const char* str, char ch){
	int num = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if(str[i] == ch){
			++num;
		}
	}
	return num;
}

//4.9
//グローバル変数でconstを付けることでglobal内で書き換え不可
const int ARRAY_SIZE = 5;
void Init(int array[]){
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		array[i] = i*5;
	}
}
//引数にconstを付けることでshow内書き換え不可にする
//Showの中でInit(array)を呼ぶこともできない。const書き換え可能性有りと判断される。
void Show(const int array[]){
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		cout << array[i] << " " ;
	}
	cout<<endl;
}


//4.10
const char* const MONTH_NAME[] = {
	"January","February","March","April","May","June",
	"July","August","September","October","November","December"
};
const char* GerOldMonthName(int month){
	if(1<=month&&month<=12){
		return MONTH_NAME[month-1];
	}
	return 0;
}
int main(){
	char path[] = "/User/imaimai/document/sublime/c++";
	cout << path << "is in " << StrCount(path,'/')<<endl;
	//4.9
	int n[ARRAY_SIZE];
	Init(n);
	Show(n);

	//4.10
	int month = 13;
	cout<<"What month is it now?" <<flush;
	cin >> month;
	const char* name = GerOldMonthName(month);
	if(name == 0){
		cout << "Such month doesnt exist" << endl;
	}else{
		cout << name << endl;
	}
}

