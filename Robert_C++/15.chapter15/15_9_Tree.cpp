#include "15_9_Tree.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//実体化
typedef Tree<string> NameTree; //コンストラクタ
typedef NameTree::Node Node; //ノード
typedef NameTree::Children Children;
typedef NameTree::CIterator CIterator;

//再帰を使っている
//イテレータで++動かして行って，子ノードのendに来るまで再帰
void Show(const Node* node, int depth = 0){
	cout << setw(depth*2) << " " << node->value << endl;
	const Children& children = node->children;
	for(CIterator it = children.begin();it != children.end();++it){
		Show(*it,depth+1);
	}
}

int main(){
	NameTree tree("hoge");
	Node* hoge = tree.GetRoot();

	Node* foo = NameTree::Append(hoge,"foo");
	Node* bar = NameTree::Append(hoge,"bar");
	//Node* bar = tree.Append(hoge,"bar"); でも可能なハズ
	NameTree::Append(hoge,"readme.txt");

	NameTree::Append(foo,"foo.h");
	NameTree::Append(foo,"foo.cpp");
	NameTree::Append(bar,"bar.h");
	NameTree::Append(bar,"bar.cpp");


	Node* aaa = NameTree::Append(foo,"aaa");
	NameTree::Append(aaa,"descendant");

	Show(hoge);
	cout << "ノードを削除する" << endl;
	tree.Clear();
	Show(hoge);
}