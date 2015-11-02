#include <iostream>
#include <string>
using namespace std;

int main(){
	while(true){
		string line = "quit";
		cout << "何か文章を入力してください -> " << flush;
		getline(cin, line);
		if(line == "quit"){
			break;
		}//if

		// 文末から。を探していく
		string::size_type pos = line.rfind("。");
		if(pos == string::npos){
		// 。が見つからなかった場合、単に末尾に付け足す
			line += "ｱﾙﾈ";
		}else{
		//末尾に。があった場合、アルネを先に挿入する。
			line.insert(pos,"ｱﾙﾈ");
		}
		cout << line << endl;
	}//while(true)

}