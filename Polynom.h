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
		const Polynom operator + (const Polynom& p);
		const Polynom operator - (const Polynom& p);
		int get_deg();
		int  get_coefficient(int i) ;
		int set_coefficient(int i,int c) ;
		void show();
		~Polynom();
	private:
		int deg;
		int *c;
};





Polynom minus_p(const int * c1,const int * c2,int deg1, int deg2);
Polynom sum_p(const int * c1,const int * c2,int deg1, int deg2);
Polynom init_Pol();
int read_int(const char* message);

#endif
