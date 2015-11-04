#include "10_5_FileException.h"

FileException::FileException(const char* error){
	m_error = error;
}
//エラーの状況を出力する関数
const char* FileException::What() const{
	return m_error.c_str();
}