#include <iostream>
//例外を集めたライブラリ？？
#include <stdexcept>
using namespace std;

#define ARRAY_SIZE(array) (sizeof(array)/sizeof*(array))

double Average(const int* array, size_t size){
	//コンパイルに関する制御
	//マクロが定義されていないときだけコンパイルをしてねということ．
	#if ! defined(NDEBUG)
	// #ifndefをつかってもよい
	// #ifndef NDEBUG 

		if(array == NULL){
			throw invalid_argument("Averageに変な引数が渡されました");
		}	
	#endif

	int sum = 0;
	for (size_t i = 0; i < size; ++i){
		sum += array[i];
	}
	return static_cast<double>(sum) / size;
}

int main(){
	int value[] = {
		12,56,23,93,84,24,100,13,
	};
	cout << "Average : " << Average(value,ARRAY_SIZE(value));
}