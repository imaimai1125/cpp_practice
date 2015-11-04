#ifndef FILEEXCEPTION_H_
#define FILEEXCEPTION_H_

#include "10_5_Exception.h"
#include <string>

class FileException: public Exception{
public:
	FileException(const char* error);
public:
	//エラーの状況を出力
	virtual const char* What() const;
protected:
	std::string m_error;
};


#endif