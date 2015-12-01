#include <iostream>
#include <string>
using namespace std;

//パターンマッチングを行いまっちすれば　真を返す
bool Match(const char* str, //判定される文字列
	       const char* pat) //ワイルドカード文字を含むパタンを記述した文字列
{
	//どちらかが終端に達するまでループ
	for(; !(*str=='\0'||*pat == '\0');++str,++pat){
		if(*pat == '*'){
			//ワイルドカード文字のときの処理
			//次の文字と等しくなる位までstrを進める
			for(++pat; ;++str){
				//以降がマッチすればマッチング成功
				//マッチしなければワイルドカード文字の処理を継続
				if(Match(str,pat)){
					return true;
				}//最後まで見つからなければマッチング失敗
				if(*str == '0'){
					return false;
				}
			}//for
		}//if(*pat)
		else{
			//普通の比較処理
			//等しくなければマッチング失敗
			if(*pat != *str){
				return false;
			}
		}
	}//少なくともどちらかは終端に達しているので
	//等しい場合は両方終端に達していることになる
	return *pat == *str;
}

bool Input(string& str){
	cout << ">" << flush;
	getline(cin,str);
	return !(cin.fail()||str == " ");
}

int main(){
	static const char PAT[] = "*.txt";
	cout << PAT << " とのマッチングを行います．" <<endl;

	string str;
	while(Input(str)){
		cout << (Match(str.c_str(),PAT) ? "マッチしました" :"マッチしませんでした")
			 << endl;
	}
}