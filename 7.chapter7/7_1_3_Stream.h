//arraystreamとinputstreamに共通する部分をクラスとして作っておき、継承する。

#ifndef STREAM_H
#define STREAM_H
#include <iostream>

class Stream{
public:
	double Get() const;
	//7.4 override
	bool Set();
// public:
// 7.2 protected
protected:
	double m_n;
};

#endif