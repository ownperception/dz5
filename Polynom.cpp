#include"Polynom.h"
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
	else{this->c[0] = 0;}
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

const Polynom Polynom::operator + (const Polynom& p){
	Polynom result;

	if(this->deg > p.deg){
		result = sum_p(this->c, p.c, this->deg, p.deg);
		}
	else{
		result = sum_p(p.c,this->c, p.deg, this->deg);
	}
	return result;
}

const Polynom Polynom::operator - (const Polynom& p){
	Polynom result;

	if(this->deg > p.deg){
		result = minus_p(this->c, p.c, this->deg, p.deg);
		}
	else{
		result = minus_p(p.c,this->c, p.deg, this->deg);
	}
	return result;
}

Polynom::~Polynom(){
	delete[] this->c;
}

int Polynom::get_deg(){
	return this->deg;
}

int Polynom::get_coefficient(int i) {
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





Polynom sum_p(const int * c1,const int * c2,int deg1, int deg2)
{
	int c[deg1+1];
	int i = 0;
	for(; i < deg2 + 1; i++){
		c[i] =  c1[i] + c2[i];
	}
	for(;i < deg1 + 1;i++){
		c[i] = c1[i];
	}
	Polynom res(deg1,c);
	return res;
}


Polynom minus_p(const int * c1,const int * c2,int deg1, int deg2)
{
	int c[deg1+1];
	int i = 0;
	for(; i < deg2 + 1; i++){
		c[i] =  c1[i] - c2[i];
	}
	for(;i < deg1 + 1;i++){
		c[i] = c1[i];
	}
	Polynom res(deg1,c);
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

