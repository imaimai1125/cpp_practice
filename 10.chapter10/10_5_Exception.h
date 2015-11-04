#ifndef EXCEPTION_H_
#define EXCEPTION_H_

class Exception{
public:
	virtual ~Exception(); //destructor
public:
	//エラーの状況を出力
	virtual const char* What() const = 0;
};


#endif