#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Calculator{
public:
	typedef double ValueType;
	void Run();

private:
	bool Input();	//計算式を入力	
	bool Calculate(); //計算を行う
	void ShowResult() const; //計算結果を表示

private:
	ValueType m_a, m_b;
	ValueType m_result;
	char m_op;
};

void Calculator::Run(){
	while(Input()){
		if(Calculate()){
			ShowResult();
		}
	}
}

//計算式を入力
bool Calculator::Input(){
	istringstream isstr;
	while(true){
		string line;
		cout << "数式を入力してください" << endl;
		getline(cin, line);
		if(cin.fail()||line.empty()){
			return false;
		}

		isstr.clear();
		isstr.str(line);
		isstr >> m_a >> m_op >> m_b;
		if(isstr.fail()){
			continue;
		}
		isstr >> line;
		if(isstr.fail()){
			break;
		}
	}//while(true)
	return true;
}

//計算を行う
bool Calculator::Calculate(){
	switch(m_op){
	case '+': m_result = m_a + m_b; break;
	case '-': m_result = m_a - m_b; break;
	case '*': m_result = m_a * m_b; break;
	case '/': 
		if(m_b == 0){
			cout << "0では割りきれません" << endl;
			return false;	
		}
		m_result = m_a / m_b;
		break;
	default:
		cerr << "不正な演算子です" << endl;
		return false;
	}//switch
	return true;
}

//計算結果を表示
void Calculator::ShowResult() const{
	cout << m_result << endl;
}

int main(){
	Calculator calc;
	calc.Run();
}