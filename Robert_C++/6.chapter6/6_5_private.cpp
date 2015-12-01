#include <iostream>
#include <cstdlib> //exit関数に必要
using namespace std;

const int INTARRAY_SIZE = 100;
class IntArray{
public:
	IntArray();						//コンストラクタ
public:
	//ここはアクセスできるようにする
	int Get(int i);					//値の取得
	void Set(int i, int value);		//値の変更
public:	
	void CheckIndex(int i);			//インデックスのチェック
private:
	//配列	
	int m_array[INTARRAY_SIZE];

};
//コンストラクタ
IntArray :: IntArray(){
	fill_n(m_array,INTARRAY_SIZE,0);
}

//メンバへのアクセス関数
//getter
int IntArray::Get(int i){
	CheckIndex(i);
	return m_array[i];
}

//setter
void IntArray::Set(int i, int value){
	CheckIndex(i);
	m_array[i] = value;
}

//インデックスのチェック	
void IntArray::CheckIndex(int i){
	if (0<=i&&i<INTARRAY_SIZE){
		//インデックスは正常です
	}else{
		cout <<"Index is invalid"<<endl
			 <<"value : " << i << endl;
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char const *argv[])
{
	IntArray a;
	a.Set(3,3);
	cout <<	a.Get(3) << endl;
	a.CheckIndex(10);
}3