#include <iostream>
using namespace std;

/*************************
valueクラス
*************************/
class Value{
	//フレンドクラスの宣言
	//お友達になれば少々プライベートなことも教えてあげられる。
	friend class ValueFactory;
public:
	int Get() const {return m_n;}
private:
	Value(int n):m_n(n){} //constructor
	Value(const Value&); //copy constructor
	void operator=(const Value&); //operator overload
	int m_n;
};

/*************************
valuefactoryクラス
*************************/
class ValueFactory{
public:
	Value* New(int n) const{
		return new Value(n);
	}
};

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