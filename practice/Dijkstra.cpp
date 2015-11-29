#include <iostream>
#include "Dijkstra.h"
using namespace std;

/**********************************
Node
**********************************/
Node::Node(const char* label, Node* from){
	this->label = label;
	this->from = from;
}
Node::Node(const char* label){
	this->label = label;
	this->from = NULL;
}

//getter
const char* Node::getLabel(){return this->label;}
Node* Node::getFrom(){return this->from;}
int Node::getTotalCost(){return this->TotalCost;}
//setter
void Node::setFrom(Node* from){this->from = from;}
void Node::setTotalCost(int TotalCost){this->TotalCost = TotalCost;}

/**********************************
Edge
**********************************/
//constructor
Edge::Edge(Node* srcNode, Node* dstNode, int cost){
	this->srcNode = srcNode;
	this->dstNode = dstNode;
	this->cost = cost;
}
//getter
Node* Edge::getSrcNode(){return this->srcNode;}
Node* Edge::getDstNode(){return this->dstNode;}
int Edge::getCost(){return this->cost;}

/**********************************
Dijkstra
**********************************/
//初期化
Dijkstra::Dijkstra(){
	this->dummy = new Node("X");
	this->s = new Node("S",dummy);
	this->a = new Node("A");
	this->b = new Node("B");
	this->c = new Node("C");
	this->d = new Node("D");
	this->g = new Node("G");
	
	this->Edges[0] = new Edge(this->s,this->a,5),
	this->Edges[1] = new Edge(this->s,this->b,4),
	this->Edges[2] = new Edge(this->s,this->c,2),
	this->Edges[3] = new Edge(this->a,this->b,2),
	this->Edges[4] = new Edge(this->a,this->g,6),
	this->Edges[5] = new Edge(this->b,this->c,3),
	this->Edges[6] = new Edge(this->c,this->d,6),
	this->Edges[7] = new Edge(this->b,this->d,2/),
	this->Edges[8] = new Edge(this->d,this->g,4);
}

Dijkstra::~Dijkstra(){
	delete this->dummy;
	delete this->s;
	delete this->a;
	delete this->b;
	delete this->c;
	delete this->d;
	delete this->g;
	for(int i=0;i<9;++i){
		delete Edges[i];
	}
}

void Dijkstra::run(){
	while(true){
		bool cont = false;
		//calculation
		for(int i = 0;i < 9 ; ++i){
			Edge* edge = this->Edges[i];
			Node* src = edge->getSrcNode();
			cout << edge->getSrcNode()->getLabel()<<endl;
			Node* dst = edge->getDstNode();
			if(src->getFrom() == NULL){continue;}
			if(dst->getFrom() == NULL ||
			   src->getTotalCost()+edge->getCost()<dst->getTotalCost()){
				dst->setFrom(src);
				dst->setTotalCost(src->getTotalCost()+edge->getCost());
				cont = true;
			}	
		}
		if(!cont){break;}
	}
	cout << "distance : " << g->getTotalCost() << endl;
	Node* node = g;
	while(node != dummy){
		cout << node->getLabel() << endl;
		node = node->getFrom();
	}
	cout <<endl;
}


int main(){
	Dijkstra* d = new Dijkstra();
	cout << "aaa" << endl;
	d->run();
}
