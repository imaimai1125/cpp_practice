#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H

//継承のためにinclude
#include "7_11_Stream.h"

class InputStream 
	: public Stream
{
public:
	InputStream();
protected:
	virtual void SetBase();//値を設定する基本関数
};

#endif