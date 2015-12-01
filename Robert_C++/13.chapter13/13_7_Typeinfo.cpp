#include <iostream>
#include <fstream>
#include <sstream>
//型の確認
#include <typeinfo>
using namespace std;


class ClassA{
public:
	ClassA() {}
	virtual ~ClassA(){}
};


// 関数の引数を参照渡しにする->アップキャストと同じこと
//型を表示
void ShowType(const ostream& ostr){
	cout << typeid(ostr).name() << endl;
}

//型のチェック
void CheckType(const ostream& ostr){
	const type_info& tiOstr = typeid(ostr);
	const type_info& tiOstream = typeid(ostream);
	const type_info& tiOfstream = typeid(ofstream);
	const type_info& tiCOfstream = typeid(const ofstream);
	const type_info& tiCROfstream = typeid(const ofstream&);

	cout << boolalpha;

	cout << "(==)" << endl
		 << "ostream 	 	: " << (tiOstr == tiOstream) << endl
		 << "ofstream 		: " << (tiOstr == tiOfstream) << endl 
		 << "const ostream 	: " << (tiOstr == tiCOfstream) << endl 
		 << "const ostream& 	: " << (tiOstr == tiCROfstream) << endl; 
}


int main(){
	fstream fstr;
	ofstream ofstr;
	stringstream sstr;
	ostringstream osstr;
	ClassA class_a;

	ShowType(fstr);
	ShowType(ofstr);
	ShowType(sstr);
	ShowType(osstr);
	
	cout << typeid(1).name() << endl;
	cout << typeid(1.0).name() << endl;
	cout << typeid("あ").name() << endl;
	cout << typeid("a").name() << endl;
	cout << typeid("hello world").name() << endl;
	cout << typeid(class_a).name() << endl;

	//型チェック
	CheckType(ofstr);
}