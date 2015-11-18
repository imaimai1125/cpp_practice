#include <stdexcept>
#include <iostream>
using namespace std;

template <typename TYPE>
 class Stack{
 public:
 	explicit Stack(size_t sizeMax):
 	m_sizeMax(sizeMax), m_size(0)
 	{
 		m_array = new TYPE[sizeMax];
 	}	
 	virtual ~Stack(){
 		delete [] m_array;
 	}
 public:
 	//一番上にデータを積む
 	void Push(const TYPE& value){
 		CheckOverflow();
		m_array[m_size] = value;
		++m_size; 
 	}
 	//一番上に積まれたデータを削除
 	void Pop(){
 		CheckUnderflow();
 		--m_size;
 	}
 	//一番上に積まれたデータへの山椒を取得
 private:
 	//一番上に積まれたデータへの山椒を取得
 	const TYPE& Top_() const{
 		CheckUnderflow();
 		return m_array[m_size -1];
 	}
 public:
 	TYPE& Top(){return const_cast<TYPE&>(Top_());}
 	const TYPE& Top() const {return Top_();}
 	//スタックがいっぱいかどうかチェック
 	bool Full() const {return m_size == m_sizeMax;}
 	//スタックが空かチェック
 	bool Empty() const {return m_size == 0;}
 private:
 	//スタックがいっぱいだと例外を投げる
 	void CheckOverflow() const{
 		if(Full()){
 			throw std::overflow_error("スタックオーバーフロー");
 		}
 	}
 	//スタックがカラだと例外を投げる
 	void CheckUnderflow() const{
 		if(Empty()){
 			throw std::underflow_error("タスクがからです");
 		}
 	}

private:
	TYPE* m_array;
	size_t m_size;
	size_t m_sizeMax;

};

int main(){
	Stack<int> stack(10);
	try{
		for (int i = 0; i < 20; ++i){
			stack.Push(i);
		}
	}catch(const overflow_error& e){
		cerr << e.what() << endl;
	}
	while(! stack.Empty()){
		cout << stack.Top() << " ";
		stack.Pop();
	}
	cout << endl;
}