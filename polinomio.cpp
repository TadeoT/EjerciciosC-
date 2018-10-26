#include <iostream>
#include <cmath>
using namespace std;
class Monomio{
private:
	double m_a;
	int m_n;
public:
	Monomio (double a,int n){m_a=a;m_n=n;}
	int ver_n(){return m_n;}
	double ver_a(){return m_a;}
	double evaluar(double x){
	double e;
	e=m_a*pow(x,m_n);
	return e;
	}
	void asignar (double a,int n){m_a=a;m_n=n;}
};
class Polinomio{
private:
	Monomio *p;
	int grado;
public:
	Polinomio(double v[],int g){
		grado=g;
		p=new Monomio[g+1]
		for(int x=grado;x>=0;x--){
			p[x].asignar(v[x],x);
			cout<<p[x].ver_a()<<"*X"<<p[x].ver_n()<<"+"
		}
	}
	double ver_coeficiente(int){return grado; }
	double evaluar(double){};
	~Polinomio(){delete []p};}
};
int main() {
	
	return 0;
}

