#include <iostream>
#include <utility>
using namespace std;

template <typename TYPE>
 class Value
 {
 public:
 	Value(const TYPE& value):m_value(value){}
 	void Show(){cout << m_value << endl;}
 private:
 	TYPE m_value;
 };

template<typename FIRST, typename SECOND>
 class Value< pair<FIRST, SECOND> >
{
public:
	Value(const FIRST& first, const SECOND& second):
		m_value(first,second){}
	void Show(){
		cout << "1st : "<<m_value.first << endl;
		cout << "2nd : "<<m_value.second << endl;
	}
private:
	pair<FIRST,SECOND> m_value;

};

int main(){
	Value<int> n(42);
	n.Show();
	Value< pair<int,const char*> > p(1,"Hoge");
	p.Show();
}