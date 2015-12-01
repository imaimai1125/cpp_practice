
#ifndef STREAM_H
#define STREAM_H
#include <iostream>

class Stream{
public:
	//コンストラクタ
	Stream();
	// 基底クラスのデストラクタは仮想関数にすべし！
	virtual ~Stream();
	double Get() const;
	//7.4 override
	//宣言にて仮想関数にして、オーバーライドできるようにする
	 bool Set();
protected:
	virtual void SetBase() = 0; //純粋仮想関数
	double m_n;
};

#endif