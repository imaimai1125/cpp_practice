#ifndef ARRAY_STREAM
#define ARRAY_STREAM
// 継承のためインクルード
#include "7_1_3_Stream.h"
// 配列から順に値を取得していくクラス
class ArrayStream
	:public Stream{
public:
	ArrayStream(const double* array); //コンストラクタ
	bool Set();

private:
	const double* m_array; //配列
	int m_i; //現在のインデックス
};


#endif