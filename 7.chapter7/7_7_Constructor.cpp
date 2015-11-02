#include "7_1_1_InputStream.cpp"
#include "7_1_3_Stream.cpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	InputStream stream(5);
	cout << stream.Get() << endl;
}