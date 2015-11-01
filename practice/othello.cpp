#include <iostream>
using namespace std;

//オセロを作る

int main(int argc, char const *argv[])
{
	const int OTHELLO_SIZE = 8;
	int OTHELLO_FIELD[OTHELLO_SIZE][OTHELLO_SIZE];
	// initialize
	for (int i = 0; i < OTHELLO_SIZE; ++i){
		for (int j = 0; j < OTHELLO_SIZE; ++j){
			OTHELLO_FIELD[i][j] = 0;
		}
	}
	OTHELLO_FIELD[3][3] = 1;
	OTHELLO_FIELD[4][4] = 1;
	OTHELLO_FIELD[3][4] = 2;
	OTHELLO_FIELD[4][3] = 2;
	//update


	// console out the field
	cout << "  ";
	for (int i = 0; i < OTHELLO_SIZE; ++i){
		cout << i+1 << " " ;
	}
	cout << endl;
	for (int i = 0; i < OTHELLO_SIZE; ++i){
		cout << i+1 << " ";
		for (int j = 0; j < OTHELLO_SIZE; ++j){
			if(OTHELLO_FIELD[i][j] == 0){
				cout << " "<<" ";
			}else if(OTHELLO_FIELD[i][j] == 1){
				cout << "●"<<" ";
			}else if(OTHELLO_FIELD[i][j] == 2){
				cout << "○"<<" ";
			}
		}cout << endl;
	}
	
	bool A = true;//エラー判定
	bool turn = true; //先攻後攻判定
	while(A){
		int tate = 0;
		int yoko = 0;
		cout << "Where do you want to put on the OTHELLO?" << endl;
		cout << "TATE = " ;
		cin >> tate;
		cout << "YOKO = ";
		cin >> yoko;
		if(OTHELLO_FIELD[tate-1][yoko-1] != 0){
			A = false;
			cout << "error! " << endl;
		}else{
			if(turn){
				OTHELLO_FIELD[tate-1][yoko-1] = 1;
				turn = false;
			}else{
				OTHELLO_FIELD[tate-1][yoko-1] = 2;
				turn = true;
			}
		}
		// console out the field
		cout << "  ";
		for (int i = 0; i < OTHELLO_SIZE; ++i){
			cout << i+1 << " " ;
		}
		cout << endl;
		for (int i = 0; i < OTHELLO_SIZE; ++i){
			cout << i+1 << " ";
			for (int j = 0; j < OTHELLO_SIZE; ++j){
				if(OTHELLO_FIELD[i][j] == 0){
					cout << " "<<" ";
				}else if(OTHELLO_FIELD[i][j] == 1){
					cout << "●"<<" ";
				}else if(OTHELLO_FIELD[i][j] == 2){
					cout << "○"<<" ";
				}
			}cout << endl;
		}
	}

}