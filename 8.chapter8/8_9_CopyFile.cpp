#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const char SRC_NAME[] = "8_9_hello.txt";
const char DST_NAME[] = "8_9_hellocp.txt";

const int BUF_SIZE = 1024;

int main(){
	fstream src; //コピー元
	fstream dst; //コピー先

	src.open(SRC_NAME, ios::in|ios::binary);
	if(!src.is_open()){
		return EXIT_FAILURE;
	}
	dst.open(DST_NAME, ios::out|ios::binary);
	if(!dst.is_open()){
		//先に開いたのを忘れずに閉じる
		src.close();
		return EXIT_FAILURE;
	}
	bool error = false;
	do{
		char buf[BUF_SIZE];
		src.read(buf,sizeof buf);
		// 読み込みエラーの判定
		if(src.fail() && ! src.eof()){
			error = true;
			break;
		}
		dst.write(buf, src.gcount());
		//書き込みエラーの判定
		if(dst.fail()){
			error = true;
			break;
		}
	}while(! src.eof());

	dst.close();
	src.close();
	if(error){
		cout << "ファイル操作でエラーが発生しました！" << endl;
		remove(DST_NAME);
		return EXIT_FAILURE;
	}
}
