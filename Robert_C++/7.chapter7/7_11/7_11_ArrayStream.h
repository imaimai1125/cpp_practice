#ifndef ARRAY_STREAM2
#define ARRAY_STREAM2

// 継承のためインクルード
#include "7_11_Stream.h"
// 配列から順に値を取得していくクラス
class ArrayStream
	:public Stream{
public:
	ArrayStream(const double* array, int size); //コンストラクタ
	~ArrayStream();//デストラクタ
protected:
	virtual void SetBase();
private:
	double* m_array; //配列
	int m_i; //現在のインデックス
};


#endif