#include <vector>
#include <list>
#include <set>
using namespace std;

#define SUFFIX(type) SUFFIX_##type
#define SUFFIX_int Int

//CONCATマクロを定義してやる
#define CONCAT_(a,b) a##b
#define CONCAT(a,b) CONCAT_(a,b)

#define TYPEDEF_CONTAINERS(type)\
 typedef std::vector<type> CONCAT(Vector,SUFFIX(type));\
 typedef std::list<type> CONCAT(List,SUFFIX(type));\
 typedef std::set<type> CONCAT(Set,SUFFIX(type))
 
 //これじゃあマクロの展開順番によって，うまく展開され無い
 // typedef std::vector<type> Vector##SUFFIX(type);\
 // typedef std::list<type> List##SUFFIX(type);\
 // typedef std::set<type> Set##SUFFIX(type)
 

int main(){
	TYPEDEF_CONTAINERS(int);
	VectorInt v;
}
