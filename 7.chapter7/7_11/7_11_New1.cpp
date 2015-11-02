#include "7_11_ArrayStream.cpp"
#include "7_11_InputStream.cpp"
#include "7_11_Stream.cpp"

#include <iostream>
using namespace std;

Stream* CreateStream(){
	char ch;
	while(true){
		cout << "i : InputStream, a : ArrayStream -> " << flush;
		cin >> ch;

		switch(ch){
		case 'i':
			return new InputStream();
		case 'a':
			while(true){
				cout << "choose the array (1,2) -> " << flush;
				cin >> ch;
				if(ch == '1'){
					static const double ARRAY[] = {1,2,3,-1};
					static const int SIZE = sizeof ARRAY/sizeof *ARRAY;
					return new ArrayStream(ARRAY,SIZE);
				} else if(ch == '2'){
					static const double ARRAY[] = {0.1,0.3,-1};
					static const int SIZE = sizeof ARRAY/sizeof *ARRAY;
					return new ArrayStream(ARRAY,SIZE);
				}
			}//while(true)
		}//switch(ch)
	}//while(true)
}

double Sum(Stream& stream){
	double sum = 0;
	while(stream.Set()){
		sum += stream.Get();
	}
	return sum;
}

int main(){
	for (int i = 0; i < 3; ++i){
		Stream* stream = CreateStream();
		double sum = Sum(*stream);
		cout << "Sum : " << sum << endl;
		delete stream;
	}
}