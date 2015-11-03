#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int PAGE_WIDTH = 16;
const int PAGE_HEIGHT = 16;
const int PAGE_SIZE = PAGE_WIDTH * PAGE_HEIGHT;

class DumpFile{
public:
	bool Run(); //一連の処理を実行

private:
	bool Open(); //ファイルを開く
	void Close();//ファイルを閉じる
	void Dump(); //1ページ分をダンプ
	bool Control(); //ページの制御

private:
	fstream m_file;
	int m_page;
};

/*****************************
メンバ関数の中身
*****************************/
bool DumpFile::Run(){
	if(!Open()){
		return false;
	}
	do {
		Dump();
	}while(Control());

	Close();
	return true;
}

//自分が入力したファイル名のファイルを開けるようになった！
bool DumpFile::Open(){
	string filename;
	cout << "ファイル名 > " << flush;
	getline(cin, filename);

	m_file.open(filename.c_str(),ios::in|ios::binary);
	m_page = 0;
	return m_file.is_open();
}

void DumpFile::Close(){
	m_file.close();
}

//1ページ分をダンプ
void DumpFile::Dump(){
	cout << endl;
	m_file.clear();
	m_file.seekg(m_page * PAGE_SIZE);

	for (int i = 0; i < PAGE_HEIGHT; ++i){
		unsigned char buf[PAGE_WIDTH];
		m_file.read((char*)buf,sizeof buf);

		for (int i = 0; i < m_file.gcount(); ++i){
			printf("%02X ", buf[i]);
		}
		cout << endl;
	}
}

//ページめくりなど。
bool DumpFile::Control(){
	while(true){
		string command;
		cout << "Command? (n:next / p:previous / q:quit) >" << flush;
		getline(cin,command);
	
		if(command == "n"){
			//最後のページじゃないなら後ろへ
			if(!m_file.eof()){
				++m_page;
				return true;
			}else{
				//コマンド再入力
			}
		}
		else if(command == "p"){
			//最初のページじゃないなら前へ
			if(m_page > 0){
				--m_page;
				return true;
			}else{
				//コマンド再入力
			}
		}
		else if(command == "q"){
			//終了
			return false;
		}
	}//while(true)
}



int main(){
	DumpFile dump;
	if(!dump.Run()){
		return EXIT_FAILURE;
	}
}