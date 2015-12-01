#ifndef SLIST_H
#define SLIST_H value

#include <cassert>
#include <cstddef>
#include <iostream>
using namespace std;

//単方向リスト
template <typename TYPE>
 class SList{
public:
	//node
	struct Node{
		TYPE value;
		Node* next;
	};
public:
	SList(){m_eol.next = NULL;}
	virtual ~SList(){Clear();}
	//先頭nodeを終了後
	Node* GetFirst(){return m_eol.next;}
	const Node* GetFirst() const {return m_eol.next;}
	//Nodeの次の位置にnodeを挿入
	Node* Insert(Node* node, const TYPE& value){
		assert(node != NULL);
		Node* next = new Node();
		next->value = value;
		next->next = node->next;
		return node->next = next;
	}

	//先頭位置に値を挿入
	Node* Unshift(const TYPE& value){
		return Insert(&m_eol,value);
	}

	//nodeの次のノーdを削除
	void EraseNextNode(Node* node){
		assert(node != NULL);
		Node* next = node->next;
		assert(next != NULL);
		node->next = next->next;
		delete next;
	}

	// 先頭nodeの削除
	void Shift(){
		EraseNextNode(&m_eol);
	}

	//全削除
	void Clear(){
		Node* next;
		for(Node* node = m_eol.next; node != NULL; node = next){
			next = node->next;
			delete node;
		}
		m_eol.next = NULL;
	}

	//i番目の値にアクセス
private:
	const TYPE& At_(int i) const{
		const Node* node = m_eol.next;
		for (int j = 0; j < i; ++j){
			node = node->next;
		}
		return node->value;
	}
public:
	TYPE& At(int i) {return const_cast<TYPE&>(At_(i));}
	const TYPE& At(int i) const {return At_(i);}

private:
//リストの端（end of list)をあらわすnode
	Node m_eol;


 };
/**************************
宣言
**************************/
typedef SList<int> List;
typedef List::Node Node;

/**************************
関数
**************************/
void Show(const List& list){
	for(const Node* node = list.GetFirst(); node != NULL ; node = node->next){
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
 		list.Unshift(i);
 	}
 	Show(list);
 	list.Shift();
 	Show(list);
 	list.At(3) = 42;
 	Show(list);

 }


#endif