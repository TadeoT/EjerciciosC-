#include <iostream>
using namespace std;
class Complejo{
private:
	float r,i;
	
public:
	Complejo(float real,float imaginario){
		this->r=real;this->i=imaginario;
	}
	float verReal(){return this->r;}
	float verImaginario(){return this->i;}
	void saveReal(float real){
		this->r=real;
	}
	void saveImaginario(float imaginario){
		this->i=imaginario;
	}
	float &operator[](int i){
		if(i==0) return this->r;
		else return 	this->i;
	}
};
bool operator== (Complejo c1,Complejo c2){
	if(c1.verReal()==c2.verReal()){
		if(c1.verImaginario()==c2.verImaginario()){
			return true;
		}
	}
	return false;
}
Complejo operator+(Complejo c1,Complejo c2){
	float r,i;
	r=c1.verReal()+c2.verReal();
	i=c1.verImaginario()+c2.verImaginario();
	Complejo aux(r,i);
	return aux;
}
ostream &operator<< (ostream &salida,Complejo &x){
	salida<<x.verReal()<<"+"<<x.verImaginario()<<"i";
	return salida;
}
istream &operator>> (istream &entrada,Complejo &x){
	float r,i;
	entrada>>r;
	entrada>>i;
	x.saveReal(r);
	x.saveImaginario(i);
	return entrada;
}
int main(int argc, char *argv[]) {
	int bandera,esc=1;
	Complejo c1(0,0),c2(0,0),c3(0,0);
	while(esc==1){
	cout<<"1 - sumar complejos"<<endl;
	cout<<"2 - comparar complejos"<<endl;
	cin>>bandera;
	switch(bandera){
		case 1:
		cout<<"sumar dos complejos"<<endl;
		cout<<"Primero complejo"<<endl;
		cin>>c1;
		cout<<c1<<endl;
		cout<<"Segundo complejo"<<endl;
		cin>>c2;
		cout<<c2<<endl;
		c3=c1+c2;
		cout<<c3<<endl;
		break;
		case 2:
		cout<<"comparar dos complejos"<<endl;
		cout<<"Primero complejo"<<endl;
		cin>>c1;
		cout<<c1<<endl;
		cout<<"Segundo complejo"<<endl;
		cin>>c2;
		cout<<c2<<endl;
		if(c1==c2){
			cout<<c1<<"||"<<c2<<" son iguales"<<endl;
		}else{
			cout<<"No son iguales"<<endl;
		}
		
		break;
	}
	cout<<"cualquier numero para salir o 1 para seguir"<<endl;
	cin>>esc;
	}
	
	return 0;
}

