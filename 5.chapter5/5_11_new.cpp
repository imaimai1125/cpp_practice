#include <iostream>
using namespace std;


void CalcMultiples(int* array, int size, int n){
	for (int i = 0; i < size; ++i){
		array[i] = n * (i+1);
	}
}
void ShowArray(const int* array, int size){
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	//nothrowを入れておくと、配列が確保できなかった時にnull pointerを返す
	int* p = new(nothrow) int;
	//pに値を代入している。謎だ。
	if(p!=NULL){
		*p = 1;
		cout << *p << endl;
		delete p;
	}
	int size = 3;
	int* array;
	cout << "How far do you caluculate ?? -- " << flush;
	cin >> size;

	array = new int[size];
	CalcMultiples(array,size,3);
	ShowArray(array,size);


	//これはOKなのか？newで配列を確保してやると、配列のサイズを可変にすることができる。
	cout << "How far do you caluculate ?? -- " << flush;
	cin >> size;
	// array = new int[size];
	CalcMultiples(array,size,3);
	ShowArray(array,size);

	delete[] array;
}