#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
using namespace std;
/***********************
クラスの定義
***********************/
template <typename TYPE>
 class Array{
 public:
 	Array(int size);						//コンストラクタ
 	Array(const Array& other);				//コピーコンストラクタ
 	void operator= (const Array& other);	//演算子オーバーロード
 	virtual ~Array();						//デストラクタ
public: 
	void Error(); 
public:
	//アクセス関数
	TYPE Get(int i) const;
	void Set(int i, TYPE value);
public:
	//配列のsizeを返す
	int Size() const;
private:
	//インデックスのチェック
	void CheckIndex(int i) const;
private:
	//メンバ変数
	TYPE* m_array;
	//メンバ定数にしてみる
	const int m_size;
 };
/***********************
クラスの実装
***********************/
//コンストラクタ
template <typename TYPE>
  Array<TYPE>::Array(int size):m_size(size)
  {
  	m_array = new TYPE[size];
  }
 //コピーコンストラクタ
template <typename TYPE>
  Array<TYPE>::Array(const Array& other){
  	m_size = other.m_size;
  	m_array = new TYPE[m_size];
  	std::copy(other.m_array,other.m_array+m_size, m_array);
}
//オーバーロード演算子
template <typename TYPE>
  void Array<TYPE>::operator= (const Array& other){
  	TYPE* array = new TYPE[other.m_size];
  	delete[] m_array;
  	m_array = array;
  	m_size = other.m_size;
  	std::copy(other.m_array,other.m_array+m_size, m_array);
}
//デストラクタ
template <typename TYPE>
 Array<TYPE>::~Array(){
 	delete[] m_array;
 }


//Get
template <typename TYPE>
 TYPE Array<TYPE>::Get(int i) const{
 	CheckIndex(i);
 	return m_array[i];
}
//Set
template <typename TYPE>
 void Array<TYPE>::Set(int i, TYPE value){
 	CheckIndex(i);
 	m_array[i] = value;
 }
//サイズを返す
template <typename TYPE>
 int Array<TYPE>::Size()const{
 	return m_size;
 }
 //インデックスのチェック
template <typename TYPE>
 void Array<TYPE>::CheckIndex(int i) const{
 	if(0<=i && i<m_size){
 	}else{
 		std::cerr << "Index is invalid!" << std::endl
 				<<"value : " << i << std::endl;
 		std::exit(EXIT_FAILURE);
 	}
 }
//Error
template <typename TYPE>
 void Array<TYPE>::Error(){
 	m_size = 0;
 }

/***********************
メイン文
***********************/
int main(){
	Array<int> array(10);
	// m_sizeをconstにしたので、代入するとエラー
	// array.Error();

}
