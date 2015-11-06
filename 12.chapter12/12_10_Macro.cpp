#include <iostream>
using namespace std;


#define ARRATY_SIZE(array) (sizeof (array)/sizeof *(array))
//ちゃんとサイズを測ってくれない
//arrayのポインタサイズを出しちゃう
// template <typename TYPE>
//  size_t ArraySize(TYPE array[]){
//  	return sizeof array/sizeof *array;
//  }

 int main()
 {
 	int n[100];
 	cout << ARRATY_SIZE(n) << endl;
 }