/*****************************
gnuplotを簡単に導入できるように書く
header file
author:imai takeaki
date:20151130
******************************/

#ifndef GNUPLOT_H_
#define GNUPLOT_H_
#include "data.h"
#include <string>

class GNUPLOT{
public:
	GNUPLOT(){
		gp_ = popen("gnuplot -persist","w");
		flg_w_ = false;
		flg_up_ = false;
		flg_rm_ = false;
	}
	~GNUPLOT(){
		pclose(gp_);
	}

	void plot(DATA &data);
	//セッタ
	void set(std::string param);
	void set_flg_w(bool flg_w_);
	void set_flg_up_(bool flg_up_);
	void set_flg_rm_(bool flg_rm_);
private:
	void rm_file(std::string fname);
	FILE *gp_;
	bool flg_w_;
	bool flg_rm_;
	bool flg_up_;
};

#endif