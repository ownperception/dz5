#include"main5.h"

int main(){
	Polynom p1 = init_Pol();
	p1.show();
	
	Polynom p2 = init_Pol();
	p2.show();

	Polynom res = p1 + p2;
	res.show();

	return 0;
}
