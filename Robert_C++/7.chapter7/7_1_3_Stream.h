//arraystreamとinputstreamに共通する部分をクラスとして作っておき、継承する。

#ifndef STREAM_H
#define STREAM_H
#include <iostream>

class Stream{
public:
	//7.7 コンストラクタ
	Stream(double n);
	double Get() const;
	//7.4 override
	//宣言にて仮想関数にして、オーバーライドできるようにする
	bool Set();
// public:
// 7.2 protected
protected:
	virtual void SetBase() = 0; //純粋仮想関数
	double m_n;
};

#endif