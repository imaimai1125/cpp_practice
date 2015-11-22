#include <cstdio>
using namespace std;

union Word{
	unsigned short word;
	struct {
		unsigned char low;//下位ばいと
		unsigned char high;//上位ばいと
	}byte;
};

int main(){
	Word n = {0x1234};
	printf("上位ばいと: %02X \n", n.byte.high);
	printf("下位ばいと: %02X \n", n.byte.low);
}