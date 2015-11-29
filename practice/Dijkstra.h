#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_ 

class Node{
private:
	const char* label;
	int TotalCost;
	Node* from;
public:
	Node(const char* label);
	Node(const char* label, Node* from);
	Node(const Node& other);
public: 
	const char* getLabel();
	Node* getFrom();
	int getTotalCost();
public:
	void setFrom(Node* from);
	void setTotalCost(int TotalCost);
};

class Edge{
private:
	Node* srcNode;
	Node* dstNode;
	int cost;
public:
	Edge(Node* srcNode, Node* dstNode, int cost);
public:
	Node* getSrcNode();
	Node* getDstNode();
	int getCost();
};


class Dijkstra{
public:
	Dijkstra();
	~Dijkstra();
public:
	void run();
private:
	Edge* Edges[9];
	Node* dummy;
	Node* s;
	Node* a;
	Node* b;
	Node* c;
	Node* d;
	Node* g;
};

#endif