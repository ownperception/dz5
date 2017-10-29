#include"Polynom_new.h"
using namespace std;


Polynom::Polynom(const int deg, const int* c)
	:deg(deg)
{
	if(c){
		this->c = new int[deg+1];
		for(int i = 0;i < deg+1; i++){
			this->c[i] = c[i];
		}
	}
	else{
		this->c = new int [1];
		this->c[0] = 0;
	}
}

Polynom::Polynom(const Polynom& p)
	:deg(p.deg)
{
	delete[] this->c;
	this->c = new int[p.deg+1];
	for(int i = 0; i < this->deg+1; i++){
		this->c[i] = p.c[i];
	}
}

const Polynom& Polynom::operator = (const Polynom& p){
	delete[] this->c;
	this->c = new int[p.deg+1];
	this->deg = p.deg;
	for(int i = 0; i < this->deg+1; i++){
		this->c[i] = p.c[i];
	}
	return *this;
}

const Polynom operator + (const Polynom& p1,const Polynom& p2){
	Polynom result;
	if(p1.get_deg() > p2.get_deg()){
		result = sum_p(p1, p2);
		}
	else{
		result = sum_p(p2,p1);
	}
	return result;
}


Polynom::~Polynom(){
	delete[] this->c;
}

int Polynom::get_deg()const{
	return this->deg;
}

int Polynom::get_coefficient(int i) const{
	return (i <= this->deg)?this->c[i]:0;
}

int Polynom::set_coefficient(int i,int c){
	if(i < this->deg){
		this->c[i] = c;
		return 0;
	}
	return 1;
}

void Polynom::show(){
	for(int i = this->deg; i > -1; i--){
		int key = 1;
		switch(c[i]){
			case 0:
				cout<< 0;
				key = 0;
				break;
			case 1:
				if(!i) cout<<c[i];
				break;
			default:
				cout<<c[i];
				break;
		}
		switch(i*key){
			case 0:
				if(!i)break;
				cout<<" + ";
				break;
			case 1:
				cout<<"x + ";
				break;
			default:
				cout<<"x^"<<i<<" + ";
				break;
		}
	}
	cout<<endl;
}





Polynom sum_p(const Polynom& p1,const Polynom& p2)
{
	int c [p1.get_deg()+1];
	int i = 0;
	for(; i < p2.get_deg() + 1; i++){
		c[i] =  p1.get_coefficient(i) + p2.get_coefficient(i);
	}
	for(;i < p1.get_deg() + 1;i++){
		c[i] = p1.get_coefficient(i);
	}
	Polynom res (p1.get_deg(),c);
	return res;
}

Polynom init_Pol(){
	int deg = read_int("Enter degree : ");
	if(deg < 0)deg = 0;

	int c[deg+1];
	cout<<"Enter coefficient of Polynom."<<endl;
	for(int i = 0; i < deg + 1; i++){
		stringstream s;
		s<<"Enter C"<<i<<": ";
		c[i] = read_int(s.str().c_str());
	}

	return Polynom(deg,c);
}

int read_int(const char* message){
	int key = 1;
	int c;
	while(key){
		key = 0;
		cout<< message;
		cin>>c;
		if(cin.fail()){
			cout<<"Try again"<<endl;
			clr_strm(cin);
			key = 1;
		}
	}
	return c;
}


Polynom summator(const Polynom* p, int count){
	Polynom res;
	for(int i = 0; i < count; i++){
		res = res + p[i];
	}
	return res;
}



