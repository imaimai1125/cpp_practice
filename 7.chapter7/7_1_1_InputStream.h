#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H

//継承のためにinclude
#include "7_1_3_Stream.h"

class InputStream 
	: public Stream
{
public:
	//Getter（Streamを継承することにより省略）
	// double Get() const;
	//Setter
	bool Set();
// private:
	// 入力された値
	// double m_n; 
};

#endif