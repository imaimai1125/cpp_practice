// #include "15_1_TaskManager.h"
#include "15_1_TaskManager.cpp"
#include <iostream>
using namespace std;

class CountDown{
public:
	//カウントダウンタスク
	//カウントダウンしていき0になったら登録解除
	static bool Task(){
		cout << m_count << endl;
		if(m_count == 0){
			return false;
		}
		--m_count;
		return true; 
	}
	static void Register(TaskManager& manager, int count){
		m_count = count;
		manager.Register(Task);
	}
private:
	static int m_count;
};

int CountDown::m_count;

//Helloと出力するだけのタスク
bool Hello(){
	cout << "Hello" << endl;
	return true;
}

bool konnnichiha(){
	cout << "こんにちは" << endl;
	return true;
}

//メイン関数
int main(){
	TaskManager manager;
	CountDown::Register(manager, 3);
	manager.Register(Hello);
	manager.Register(konnnichiha);
	for (int i = 0; i < 5; ++i){
		manager.Execute();
	}

}