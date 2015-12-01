#ifndef DLIST_H
#define DLIST_H value

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
/**************************
宣言
**************************/
typedef DList<int> List;
typedef List::Node Node;
//進行方向（メンバポインタを使って実装）
typedef Node* Node::*ShowDirection;
const ShowDirection SD_FORWARD = &Node::next; //正順
const ShowDirection SD_BACKWARD = &Node::prev; //逆順

/**************************
関数
**************************/
void Show(const List& list, ShowDirection dir = SD_FORWARD){
	const Node* eol = list.Eol();
	const Node* head = eol->*dir;
	for(const Node* node = head; node != eol ; node = node->*dir){
		cout << node->value << " ";
	}
	cout<<endl;
}

/**************************
main文
**************************/

 int main(){
 	List list;

 	for (int i = 0; i < 10; ++i){
 		list.Push(i);
 	}
 	Show(list);
 	Show(list,SD_BACKWARD);
 	list.Pop();
 	list.Pop();
 	list.Shift();

 }


#endif