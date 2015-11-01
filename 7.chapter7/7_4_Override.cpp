#include "7_1_1_InputStream.h"
#include "7_1_2_ArrayStream.h"
#include <iostream>
using namespace std;


//????このStream&は何を意味しているんだろう？
bool Average(Stream& stream){
	int count;
	double avr = 0;
	for(count = 0; stream.Set();++count){
		avr += stream.Get();
	}
	if(count == 0){
		return false;
	}
	avr /= count;
	cout << " the average is " << avr << "." << endl;
	return true;
}

int main(){
	InputStream istream;
	Average(istream);

	static const double ARRAY[] = {1.3,4,5,-1};
	ArrayStream astream(ARRAY);
	Average(astream);
}