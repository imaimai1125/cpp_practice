#include <iostream>
using namespace std;

/*************************
不完全型の実装
Valueというクラスがあるということを明記
*************************/
class Value;

/*************************
valuefactoryクラス
*************************/
class ValueFactory{
public:
	Value* New(int n) const;
};

/*************************
valueクラス
*************************/
class Value{
	//フレンドクラスの宣言
	//お友達になれば少々プライベートなことも教えてあげられる。
	// friend class ValueFactory;
	//限定的にメンバ関数だけを友達にする
	friend Value* ValueFactory::New(int n) const;
public:
	int Get() const;
private:
	Value(int n):m_n(n){} //constructor
	Value(const Value&); //copy constructor
	void operator=(const Value&); //operator overload
	int m_n;
};

/*************************
valuefactoryクラス実装
実装をインラインに書くと
/home/imaimai/cpp/cpp_practice/13.chapter13/13_9_Friend.cpp: In member function ‘Value* ValueFactory::New(int) const’:
/home/imaimai/cpp/cpp_practice/13.chapter13/13_9_Friend.cpp:15:45: error: invalid use of incomplete type ‘class Value’
  Value* New(int n) const {return new Value(n);}
                                             ^
/home/imaimai/cpp/cpp_practice/13.chapter13/13_9_Friend.cpp:8:7: error: forward declaration of ‘class Value’
 class Value;
       ^
というエラーでる.
*************************/
Value* ValueFactory::New(int n) const{
	return new Value(n);
}
/*************************
valueクラス実装
*************************/
int Value::Get() const{
	return m_n;
}

/*************************
define
*************************/
#define ARRAY_SIZE(array) (sizeof (array)/sizeof *(array))

/*************************
main
*************************/
int main(){
	static const int VALUE[] = {1,2,4,8};
	static const int SIZE = ARRAY_SIZE(VALUE);

	ValueFactory factory;
	for (int i = 0; i < SIZE; ++i){
		Value* value = factory.New(VALUE[i]);
		cout << value -> Get() << " ";
		delete value;
	}
	cout << endl;
}