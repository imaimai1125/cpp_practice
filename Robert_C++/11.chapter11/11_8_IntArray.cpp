#include <iostream>
#include <cstdlib> //exit関数に必要
using namespace std;

const int INTARRAY_SIZE = 100;
class IntArray{
//コンストラクタ
public:
	IntArray(int n);						
//代入演算子オーバーロード
public:
	void operator = (const IntArray& other);

//private変数の橋渡し->参照を戻り値にすることで統一的にかける
public:
	int& At(int i);
//演算子オーバーロード
public:
	int& operator[] (int i);
	const int& operator[] (int i) const;
//インデックスのチェック
public:	
	void CheckIndex(int i);
//サイズの取得
public:
	int Size();

//配列自体をprivateにすることで、外からのアクセスを不可能にする
private:
	int* m_array;
	int m_size;
};


//コンストラクタ
IntArray :: IntArray(int num){
	m_size = INTARRAY_SIZE;
	fill_n(m_array,INTARRAY_SIZE,0);
}

//メンバへのアクセス関数(戻り値が参照)
int& IntArray::At(int i){
	CheckIndex(i);
	return m_array[i];
}
//演算子オーバーロード
int& IntArray::operator[] (int i){
	CheckIndex(i);
	return m_array[i];
}

// const int& IntArray::operator[] (int i) const{
// 	CheckIndex(i);
// 	return m_array[i];
// }

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

//配列のサイズを返す
int IntArray::Size(){
	return m_size;
}

void Show(IntArray array){
	for (int i = 0; i < array.Size(); ++i){
		cout << array.At(i) << " ";
	}
	cout<< endl;
}

int main(int argc, char const *argv[])
{
	IntArray array0to9(10);
	for (int i = 0; i < array0to9.Size(); ++i)
	{
		//演算子オーバーロードのおかげでこうかける。
		array0to9[i] = i;
		cout << i << endl;
	}
	// Show(array0to9);		
	cout << array0to9[30] << " ";

}