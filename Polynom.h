#ifndef POLYNOM
#define POLYNOM

#include<iostream>
#include<sstream>
#include"strm_func.h"

class Polynom{
	public:
		Polynom(const int deg = 0,const int* c = NULL);
		Polynom(const Polynom& p);
		const Polynom& operator = (const Polynom& p);
		int get_deg()const;
		int  get_coefficient(int i) const;
		int set_coefficient(int i,int c) ;
		void show();
		~Polynom();
	private:
		int deg;
		int *c;
};



Polynom summator(const Polynom* p, int count);
const Polynom operator + (const Polynom& p1,const Polynom& p2);
Polynom sum_p(const Polynom& p1,const Polynom& p2);
Polynom init_Pol();
int read_int(const char* message);

#endif
