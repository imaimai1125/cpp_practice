#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;


//参照のエラー
string Hoge(ostream& ostr){
 try{
 		//ダウンキャスト
		ostringstream& sstr = dynamic_cast<ostringstream&>(ostr);
		sstr.str(" ");
		sstr << "Hoge" << flush;
		return sstr.str();
	}catch(const bad_cast& e){
		return "ERROR!";
	}
}

//ポインタのエラー
string Hoge2(ostream& ostr){
	ostringstream* sstr = dynamic_cast<ostringstream*>(&ostr);
	if(sstr != NULL){
		sstr -> str(" ");
		*sstr << "Hoge2" << flush;
		return sstr -> str(); 
	}else{
		return "ERROR! null pointer!";
	}
}


int main(){
	ostringstream sstr;
	cout << Hoge2(cout) << endl;
	cout << Hoge2(sstr) << endl;
	cout << Hoge(cout) << endl;
	cout << Hoge(sstr) << endl;
}