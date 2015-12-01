#include <iostream>
#include <vector>

using namespace std;

//2つのテンプレート引数<template<typename,typename>を持つ
//クラステンプレートtemplate<Hoge class TEMPL>

template <template<typename,typename> class TEMPL>
 class Hoge
{
public:
	void Run(){
		m_v.push_back(1);
		m_v.push_back(3);
		m_v.push_back(5.2);

		for (size_t i = 0, size = m_v.size() ; i < size; ++i)
		{
			cout << m_v[i] << " ";
		}
		cout << endl;
	}
private:
	TEMPL<double ,allocator<int> >  m_v;
};

int main(){
	//vectorを指定してやる
	//vector<double, allocator<int> >型のメンバ変数m_vを宣言していることになる。
	Hoge<vector> hoge;
	hoge.Run();
}