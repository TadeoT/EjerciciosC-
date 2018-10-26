#include <iostream>
using namespace std;
class Racional {
	int num,den;
public:
	Racional (int n, int d){num=n;den=d;}
	int verNum(){return num;}
	int verDen(){return den;}
	void saveNum(int n){
		this->num=n;
	}
	void saveDen(int d){
		this->den=d;
	}
	Racional operator++(int){
		Racional aux = *this;
		this->num = this->num+this->den;
		return aux;
		
	}

	
};
istream &operator>> (istream &entrada,Racional &x){
	int n,d;
	entrada>>n;
	entrada>>d;
	x.saveNum(n);
	x.saveDen(d);
	return entrada;
}
bool operator!=(Racional r1,Racional r2){
	if(r1.verDen()== r2.verDen()){
		if(r1.verNum()== r2.verNum()){
			return false;
		}
	}
	return true;
}
ostream &operator<< (ostream &salida,Racional &x){
	salida <<x.verNum()<<"/"<<x.verDen();
	return salida;
}
Racional operator+(Racional r1,Racional r2){
	int n,d;
	n=r1.verNum()*r2.verDen()+r2.verNum()*r1.verDen();
	d=r1.verDen()*r2.verDen();
	Racional aux(n,d);
	return aux;
}
Racional operator*(Racional r1,int a){
	int n,d;

	n=(r1.verNum()*a);
	d=(r1.verDen());
	
	Racional aux(n,d);
	return aux;
}
	
int main(int argc, char *argv[]) {
	Racional a(3,5), b(2,3),c(0,1),d(0,0);
	if(a!=b){
		cout<<"Son diferentes"<<endl;
	}
	c=a+b;
	d=a*2;
	b++;
	cout<<b<<endl;
	cout<<d<<endl;
	cout<<c<<endl;
	
	cin>>a;
	cout<<a;
	return 0;
}

