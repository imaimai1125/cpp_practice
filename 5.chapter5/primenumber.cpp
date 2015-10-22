#include <iostream>
#include "math.h"

using namespace std;

bool prime(int a){
	int sqrt_a = sqrt(a);
	for (int i = 2; i <= sqrt_a; ++i){
		if(a%i == 0)
			return false;
	}
	return true;
}
void prime_list(int a){
	int n = 0;
	for (int i = 2; i < a; ++i){	
		if(prime(i)){
			cout << i << " " << flush;
			n++;
		}
		if(i%1000 == 0){
			// cout << endl;
			// cout<< "# of primes from " << i-999 
			// <<" to " << i << " is " << n << endl;
			n = 0;
		}

	}
}

int main(int argc, char const *argv[])
{
	int a = 1;
	cout << "input the number here -- " <<flush;
	cin >> a;
	cout << "prime number until " << a <<" is" << endl;
	prime_list(a);
}