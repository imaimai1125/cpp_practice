#include <iostream>
//vector
#include <vector>
using namespace std;

//vector<double>の場合、第一引数をdoubleにする。
void Show(const int* array, int size){
	for (int i = 0; i < size; ++i){
		cout << array[i] << " ";
	}
	cout << endl;
}
int main(){
	vector<int> v(10);
	for (size_t i = 0; i < v.size(); ++i){
		v[i] = (i+1)*(i+1);
	}
	Show(&v[0],v.size());
	v.resize(5);
	Show(&v[0],v.size());
}