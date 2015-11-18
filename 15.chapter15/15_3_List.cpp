#include <cassert>
#include <cstddef>
#include <iostream>
using namespace std;

//双方向リスト
template <typename TYPE>
 class DList{
public:
	//node
	struct Node{
		TYPE value;
		Node* prev;
		Node* next;
	};
public:
	DList(){m_eol.next = m_eol.prev = &m_eol;}
	virtual ~DList(){Clear();}
	//先頭nodeを取得
	Node* GetFirst(){return m_eol.next;}
	const Node* GetFirst() const {return m_eol.next;}
	//最後のノードを取得
	Node* GetLast(){return m_eol.prev;}
	const Node* GetLast() const {return m_eol.prev;}
 	//リストの終端を取得
 	const Node* Eol() const {return &m_eol;}


	//指定したノードの直前に値を挿入
 	//prev -> node -> nextの順
	Node* Insert(Node* next, const TYPE& value){
		assert(next != NULL);
		Node* node = new Node();
		Node* prev = next -> prev;

		node->value = value;
		node->prev = prev;
		node->next = next;
		prev->next = node;
		next->prev = node;
		return node;
	}

	//nodeの次のノーdを削除
	void Erase(Node* node){
		assert(node != NULL);
		if (node == &m_eol){return;}

		Node* prev = node->prev;
		Node* next = node->next;

		prev->next = next;
		next->prev = prev;
		delete node;
	}

	//先頭位置に値を挿入
	//数珠繋ぎだから
	Node* Unshift(const TYPE& value){
		return Insert(&m_eol.next,value);
	}
	//最後の位置に値を挿入
	Node* Push(const TYPE& value){
		return Insert(&m_eol,value);
	}

	// 先頭nodeの削除
	void Shift(){
		Erase(m_eol.next);
	}
	//最後のノードの削除
	void Pop(){
		Erase(m_eol.prev);
	}	


	//全削除
	void Clear(){
		Node* next;
		for(Node* node = m_eol.next; node != &m_eol; node = next){
			next = node->next;
			delete node;
		}
		m_eol.prev = m_eol.next = &m_eol;
	}

private:
//リストの端（end of list)をあらわすnode
	Node m_eol;
 };



#define ARRAY_SIZE(array) (sizeof (array)/sizeof* (array))
typedef DList<int> List;
typedef List::Node Node;


/**************************
イテレータクラス
**************************/
class Iterator{
public:
	Iterator(const Node* node):m_node(node){}
public:
	//現在のノードの値を取得
	int operator*() {return m_node->value;}
	//違うノードを指しているかどうか判定
	bool operator != (const Iterator& other) const{
		return m_node != other.m_node;
	}
	//次のノードに進む_
	void operator ++() {m_node = m_node->next;}
protected:
	const Node* m_node; //現在のノード
};

template <typename ITERATOR>
void Show(ITERATOR begin, ITERATOR end){
	for (ITERATOR it = begin; it != end; ++it){
		cout << *it << " " ;
	}
	cout << endl;
}


int main(){
	List list;
	for(int i=0;i<10;++i){
		list.Push(i*i);
	}
	Show(Iterator(list.GetFirst()), Iterator(list.Eol()));


	static const int ARRAY[] = {1,2,4,8};
	static const int SIZE = ARRAY_SIZE(ARRAY);
	Show(ARRAY,ARRAY+SIZE);
}







