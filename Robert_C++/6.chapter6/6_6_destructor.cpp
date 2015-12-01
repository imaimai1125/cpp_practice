#include <iostream>
#include <cstdlib> //exit関数に必要
using namespace std;

const int INTARRAY_SIZE = 100;
class IntArray{
public:
	IntArray(int size);				//コンストラクタ
	~IntArray();					//デストラクタ
public:
	//メンバへのアクセス
	int Get(int i);					//値の取得
	void Set(int i, int value);		//値の変更
public:	
	void CheckIndex(int i);			//インデックスのチェック
private:
	//配列	
	int* m_array;
	int m_size;
};

//コンストラクタ（ポインタ用）
//動的に配列を確保
IntArray :: IntArray(int size){
	m_array = new int[m_size];
	m_size = size;

	cout<<"constructor is called." <<endl;
}

//メンバへのアクセス関数
//getter
int IntArray::Get(int i){
	CheckIndex(i);
	cout<<"getter is called." <<endl;
	return m_array[i];
}

//setter
void IntArray::Set(int i, int value){
	CheckIndex(i);
	m_array[i] = value;
	cout<<"setter is called." <<endl;

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

//関数
void Viss(int num){
	cout <<"VISS : NO. " << num << endl;
}

IntArray a(10);

//デストラクタ（メモリの開放）
IntArray :: ~IntArray(){
	delete [] m_array;
	cout <<"destructor is called" <<endl;
}

int main(int argc, char const *argv[])
{
	Viss(1);
	IntArray b(20);
	Viss(2);
	{
		IntArray c(30);
		Viss(3);
	}
	Viss(4);
}