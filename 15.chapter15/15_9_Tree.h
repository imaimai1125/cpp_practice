#ifndef TREE_H_
#define TREE_H_ 

#include <list>
template <typename TYPE>
 class Tree
{
public:
	struct Node{
		typedef std::list<Node*> Children;
		// これらが型名であるということの印
		typedef typename Children::iterator Iterator;
		typedef typename Children::const_iterator CIterator;

		TYPE value; //ノードに関連付けられた値
		Children children; //子ノード

		Node(const TYPE& value):value(value){}
	};
	typedef typename Node::Children Children;
	typedef typename Node::Iterator Iterator;
	typedef typename Node::CIterator CIterator;
public:
	explicit Tree(const TYPE& value){
		m_root = new Node(value); //ルートノードを作成
	}

	virtual ~Tree(){
		Clear();
		delete m_root; //ここでルートノードを破棄
	}
	//ルートノードを取得
	Node* GetRoot(){return m_root;}
	const Node* GetRoot() const {return m_root;}

	//nodeの子ノードにvalueを持ったノードを作成
	static Node* Append(Node* node, const TYPE& value){
		Node* child = new Node(value);
		node -> children.push_back(child);
		return child;
	}
	//ルートノード以外全削除
	void Clear(){
		Clear(m_root);
	}

private:
	//Clearの中身も再帰的に扱われる
	void Clear(Node* node){
		//子ノードを全て破棄
		Children& children = node->children;
		for(Iterator it = children.begin();it != children.end();it++){
			Clear(*it);
		}
		children.clear();
		//ルートノードだけはdeleteしない
		if(node != m_root){delete node;}
	}
private:
	Node* m_root; //ルートノード

};



#endif //TREE_H_
