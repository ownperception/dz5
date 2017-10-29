#include"main5.h"

int main(){
	int count = 3;
	Polynom p[count];
	for(int i = 0; i < count;i++){
		p[i]= init_Pol();
	}
	Polinom res = summator(p);
	res.show();

	return 0;
}
