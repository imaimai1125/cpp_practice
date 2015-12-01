#include <iostream>
using namespace std;


/************************
クラスの定義
************************/
class Fraction{
public:
	//デフォルト引数を設定しているので、
	Fraction(double numer = 0, double denom = 1);
public:
	double GetNumer() const; //分子の取得
	double GetDenom() const; //分母の取得
public:
	operator double() const; //値の取得（分数から少数へ）
	Fraction operator*(const Fraction& rop) const; //掛け算
	Fraction operator*(const double n) const;

	Fraction& operator*=(const Fraction& rop); 
	Fraction& operator/=(const Fraction& rop);
private:
	double m_numer;
	double m_denom;
friend Fraction operator*(double lop, const Fraction& rop);
};

/************************
クラスの実装
************************/
Fraction::Fraction(double numer, double denom):
 m_numer(numer),
 m_denom(denom)
{}

//取得
double Fraction::GetNumer() const{
	return m_numer;
}
double Fraction::GetDenom() const{
	return m_denom;
}
//キャスト演算子をオーバーロード
//f.operator() -> fだけであらわせるようになる
Fraction::operator double() const{
	return m_numer/m_denom;
}
//f1.operator*(f2) -> f1*f2 で表されている
Fraction Fraction::operator*(const Fraction& rop) const{
	return Fraction(
		m_numer*rop.m_numer,
		m_denom*rop.m_denom);
}
Fraction Fraction::operator*(const double n) const{
	return Fraction(m_numer*n,m_denom);
}
//f1.operator(f2) *= f1 -> f1 *= f2
Fraction& Fraction::operator*=(const Fraction &rop){
	m_numer *= rop.m_numer;
	m_denom *= rop.m_denom;
	return *this;
}
Fraction& Fraction::operator/=(const Fraction &rop){
	m_numer *= rop.m_denom;
	m_denom *= rop.m_numer;
	return *this;
}

/************************
関数プロトタイプ
************************/
Fraction operator*(double lop, const Fraction& rop){
	// return Fraction(lop * rop.GetNumer(),rop.GetDenom());
	//クラス内にfriendと定義してやればprivate変数にアクセスできる。
	return Fraction(lop * rop.m_numer,rop.m_denom);
}
/************************
main
************************/

int main(){
	Fraction f(1.0,2.0);
	Fraction N(1.3); //こういうのも可能。暗黙のキャスト Fraction a();もok
	cout << f.GetDenom() << endl;
	cout << f << endl;
	//掛け算
	Fraction g(2,5);
	cout << f * g << endl;
	//代入
	f *= (g*g);
	cout << f << endl;
	f/=g;
	cout << f*2.0 << endl;
	cout << 5.0*f << endl;
}