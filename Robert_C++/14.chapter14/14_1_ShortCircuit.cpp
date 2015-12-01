#include <iostream>
using namespace std;

bool Input(double& value){
	cout << "Input the number." << endl;
	value = 0;
	cin >> value;
	return value != 0;
}

int main(){
	double a,b;
	while(Input(a) && Input(b)){
		cout << "a/b = " << (a/b) << endl
			 << "b/a = " << (b/a) << endl;
	}
}