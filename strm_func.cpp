#include"strm_func.h"

using namespace std;

void clr_strm(istream& in){
		if(in.fail()) in.clear();
		in.ignore(numeric_limits<streamsize>::max(),'\n');
}


