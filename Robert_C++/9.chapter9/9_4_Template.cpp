#include <iostream>
using namespace std;

template <typename TYPE>
 void FillArray(TYPE* array, size_t size, TYPE value){
 	for (size_t i = 0; i < size; ++i){
 		array[i] = value;
 	}
 }

 template <typename TYPE>
  void ShowArray(const TYPE* array , size_t size){
  	for (size_t i = 0; i < size; ++i){
  		cout << array[i] << " ";
  	}
  	cout << endl;
  }

  int main(){
  	const int SIZE = 5;
  	int i[SIZE];
  	string str[SIZE];

  	FillArray<int>(i,SIZE,0);
  	FillArray<string>(str,SIZE,"hoge");
  	ShowArray(i,SIZE);
  	ShowArray(str,SIZE);

  }