#include <iostream>
using namespace std;

const int MAX_NAME = 16;
//5.4ストラクチャ
struct Student{
	char nameJ[MAX_NAME+1];
	char nameE [MAX_NAME*2];
	int scoreJapanese;
	int scoreMath;
	int scoreEnglish;
};

//struct型は参照渡し
void Show(const Student& student){
	cout << "名前 : " << student.nameJ << endl;
	cout << "NAME : " << student.nameE << endl;
	cout << "国語 : " << student.scoreJapanese << "点" << endl;
 	cout << "数学 : " << student.scoreMath << "点" << endl;
}
//ポインタでメンバ変数にアクセス ->
void ShowByPointer(const Student* pointer){
	cout << "英語 : " << pointer -> scoreEnglish <<"点" <<endl;
}
int main(int argc, char const *argv[]){
	//ストラクチャの宣言
	Student student[] = {
		{"今井武晃" , "Imai Takeaki", 70, 80, 90},
		{"黒川葉子", "Kurokawa Yoko",78, 88, 98},
	};
	cout << student[2].scoreEnglish << endl;
	int size = sizeof student/sizeof *student;
	cout << sizeof student << ", " << sizeof *student << endl;
	for (int i = 0; i < size; ++i){
		Show(student[i]);
		ShowByPointer(&student[i]);
	}
	/*****************************************************
	■ShowByPointer(student[i]);のとき
	C:\Users\imaimai\Documents\sublime\c++\chap5_2_struct.cpp:36:27: 
	error: cannot convert 'Student' to 'const Student*' for argument '1' to 'void ShowByPointer(const Student*)'
  	ShowByPointer(student[i]);
	となる。
	■Show(&student[i]);のとき
	C:\Users\imaimai\Documents\sublime\c++\chap5_2_struct.cpp:15:6: 
	error: in passing argument 1 of 'void Show(const Student&)'
 	void Show(const Student& student){
	となる。

	pointerと配列の違いがいまいち不明。
	*****************************************************/
}