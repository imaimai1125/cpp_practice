#ifndef HASHFN_H_
#define HASHFN_H_ 
#include <cstddef>
#include <string>
using namespace std;

//デフォルトのハッシュ関数
template <typename TYPE>
 class HashFn
{
public:
	static size_t Get(const TYPE& value);
	static const size_t SIZE = 23; //ハッシュ表のサイズ
};

//stringでの特色
template<>
 size_t HashFn<string>::Get(const string& value)
{
	size_t size = value.size();
	const unsigned char* p =
	 reinterpret_cast<const unsigned char*>(value.data());
	return (p[0]+p[size/2]+p[size-1])%SIZE;
}



#endif