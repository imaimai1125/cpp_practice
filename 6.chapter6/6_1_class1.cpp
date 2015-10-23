#include <iostream>
using namespace std;

const int MAX_NAME = 16;
class Student{
public:
	char name[MAX_NAME+1];
	int scoreJapanese;
	int scoreMath;
	int scoreEnglish;

	void Show();
};

//クラス内で関数showを宣言しなかった時
// void Show(const Student& student){
// 	cout << "name : " << student.name <<endl;
// 	cout << "japanese : " << student.scoreJapanese <<endl;
// 	cout << "math : " << student.scoreMath <<endl;
// 	cout << "English : " << student.scoreEnglish <<endl;
// }
void Student::Show(){
	cout << "name : " << name <<endl;
	cout << "japanese : " << scoreJapanese <<endl;
	cout << "math : " << scoreMath <<endl;
	cout << "English : " << scoreEnglish <<endl;
}
int main(){
	Student student[] = {
		{"Johny" , 15,20,25},
		{"Smith" , 50,55,60},
		{"Michael", 80,90,100},
	};
	int size = sizeof student/sizeof *student;
	for (int i = 0; i < size; ++i)
	{
		// Show(student[i]);
		student[i].Show();
	}
}