#ifndef HALFINPUTSTREAM_H_
#define HALFINPUTSTREAM_H_

#include "7_1_1_InputStream.h"

//入力値の半分を取得していくクラス
class HalfInputStream:
	public InputStream
{
public: 
	HalfInputStream(double n);
protected:
	virtual void SetBase();
};

#endif