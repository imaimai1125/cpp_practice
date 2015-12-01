//numberクラスの宣言と定義
//ヘッダファイルと一緒にまとめた
#ifndef NUMBER_H_
#define NUMBER_H_ 


#include <iostream>
#include <cassert>
using namespace std;

class Number{
private:
	//保存している値の型
	enum Type {INT,DOUBLE};
public:
	Number(int n = 0){operator = (n);}
	Number(double n){operator = (n);}
	void operator =(int n); //演算子オーバーロード
	void operator =(double n);
public:
	friend std::ostream& operator<< (
		std::ostream& ostr, const Number& n);
private:
	//無名共用体を使った場合
	//タグも共用体変数もいらない
	union{
		int m_int;
		double m_double;
	};
	
	//unionを作った場合
	// union Value{
	// 	int int_;
	// 	double double_;
	// };
	// Value m_value;
	Type m_type;


	//この書き方はm_intとm_doubleが排他的で，メモリの無駄遣い
	// int m_int;
	// double m_double;
	// Type m_type;
};

/***************************
関数の定義
***************************/
void Number::operator=(int n){
	// m_int = n;
	m_int = n;
	m_type = INT;
}

void Number::operator=(double n){
	// m_double = n;
	m_double = n;
	m_type = DOUBLE;
}

ostream& operator<<(ostream& ostr, const Number& n){
	if(n.m_type == Number::INT){
		return ostr << "INT(" << n.m_int << ")";
	} else{
		assert(n.m_type == Number::DOUBLE);
		return ostr << "DOUBLE(" << n.m_double << ")";
	}
}

#endif