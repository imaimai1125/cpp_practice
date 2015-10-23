#ifndef REDEF1_MACRO //マクロ名をかくらしい
#define REDEF1_MACRO

const int N = 10;

#endif 
// #ifndef REDEF1_MACRO
/***************************
マクロを書かなかった場合のエラー


In file included from C:\Users\imaimai\Documents\sublime\c++\cpp_practice\5.chapter5\chap_5_9_Redef.cpp:3:0:
C:\Users\imaimai\Documents\sublime\c++\cpp_practice\5.chapter5\chap_5_9_Redef.h:4:11: error: redefinition of 'const int N'
 const int N = 10;
           ^
***************************/
