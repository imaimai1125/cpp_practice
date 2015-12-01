#include <iostream>
using namespace std;

#define FIVE_TIMES for(int i_ = 0; i_ < 5; ++i_)
#define TIMES(cnt, n) for (int cnt = 0 ; cnt < n; ++cnt)


int main(){
	FIVE_TIMES{
		cout << i_+1 << " Hello" << endl;
	}
	TIMES(i,10){
		cout << i << " " << endl;
	}
	cout << endl;
}