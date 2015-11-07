#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/************************
IObjectクラス
オブジェクトの情報を文字列で返す
インターフェースクラス
*************************/
class IObject{
public:
	virtual ~IObject(){}
	virtual string GetString() const = 0;
};
/************************
IIntクラス
int値を返すインターフェースクラス
*************************/
class IInt:
	virtual public IObject
{
public:
	virtual int GetInt() const = 0;
};
/************************
IDoubleクラス
double値を返すインターフェースクラス
*************************/
class IDouble:
	virtual public IObject
{
public:
	//どういう関数があるかをリストアップしているだけ。
	virtual double GetDouble() const = 0;

};

/************************
Doubleクラス
IInt,IDoubleの派生クラス
*************************/
class Double:
	virtual public IInt,
	virtual public IDouble
{
public:
	Double(double x):m_x(x){}
public:
	virtual string GetString() const{
		ostringstream ostr;
		ostr << "Double(" << m_x << ")";
		return ostr.str(); 
	}
	virtual int GetInt() const{
		return static_cast<int>(m_x);
	}
	virtual double GetDouble() const{
		return m_x;
	}
private:
	const double m_x;
};
/************************
関数プロトタイプ
*************************/
void ShowInt(const IInt& obj){
	cout << "int : " << obj.GetInt() << endl;
}
void ShowDouble(const IDouble& obj){
	cout << "double : " << obj.GetDouble() << endl;
}

/************************
main
*************************/
int main(){
	Double n = 1.2;
	cout << n.GetString() << endl;
	ShowInt(n);
	ShowDouble(n);
}	