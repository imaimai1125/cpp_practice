#include <iostream>
#include <algorithm>
using namespace std;

class IntArray{
public:
	//静的メンバ定数。はじめから初期化しておいてやる
	//じゃないとconstなのにどんな値かわかんない
	static const int SIZE = 100;

public:
	IntArray();
	virtual ~IntArray();
	int m_array[SIZE];
};

IntArray::IntArray(){
	cout << "IntArray::IntArray()" << endl;
	fill_n(m_array,SIZE,1);
}

IntArray::~IntArray(){
	cout << "IntArray::~IntArray()" << endl;
}

int main(){
	IntArray array;
	cout << IntArray::SIZE<< endl;
	cout << array.m_array[IntArray::SIZE -1] << endl;
 }

