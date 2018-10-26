#include <iostream>
#include <sstream>
using namespace std;

struct punto{
	float x,y;
};
class TRecta{
private:
	punto p1,p2;
	
public:
	TRecta (punto punto1,punto punto2){
		p1.x=punto1.x;p1.y=punto1.x;p2.x=punto2.x;p2.y=punto2.y;
	}
	float verx1(){
		return p1.x;
	}
	float very1(){
		return p2.y;
	}
	float verx2(){
		return p2.x;
	}
	float very2(){
		return p2.y;
	}
	virtual string obtener_ecuacion()=0;
	virtual bool pertenece(punto p3)=0;
	virtual ~TRecta(){};
	
};
class TGeneral:public TRecta{
private:
	float A,B,C;
public:
	TGeneral (punto punto1, punto punto2):TRecta(punto1,punto2){};
	string obtener_ecuacion(){
		A=-(very2()-very1());
		B=(verx2()-verx1());
		C=-((very1()*(verx2()-verx1()))-verx1()*(very2()-very1()));
		stringstream aux;
		aux.str("");
			if(B>=0&&C>=0){
				aux<<"La Ecuacion General de la Recta es :"<<A<<"x+"<<B<<"y+"<<C<<endl;
			}
			if (B<=0&&C>=0){
				aux<<"La Ecuacion General de la Recta es :"<<A<<"x-"<<B<<"y+"<<C<<endl;
			}
			if(B<0&&C<0){
				aux<<"La Ecuacion General de la Recta es :"<<A<<"x-"<<B<<"y-"<<C<<endl;
			}
			if(B>0&&C<0){
				aux<<"La Ecuacion General de la Recta es :"<<A<<"x+"<<B<<"y-"<<C<<endl;
			}
		return aux.str();
		}
	bool pertenece(punto p3){
		
	};
	};
class TExplicita:public TRecta{
private:
	float m_m,m_b;
public:
	TExplicita (punto punto1,punto punto2):TRecta(punto1,punto2){};
	string obtener_ecuacion(){
		float A,B,C;
		A=-(very2()-very1());
		B=(verx2()-verx1());
		C=-((very1()*(verx2()-verx1()))-verx1()*(very2()-very1()));
		m_m=-A/B;
		m_b=-C/B;
		stringstream aux;
		aux.str("");
		if (m_b>=0){
			aux<<"La Ecuacion Explicita de la recta es : y="<<m_m<<"x+"<<m_b<<endl;
		}
		else{
			aux<<"La Ecuacion Explicita de la recta es : y="<<m_m<<"x-"<<m_b<<endl;
		}
		return aux.str();
	}
	bool pertenece(punto p3){
		
	};
	
};
	
int main() {
	punto punto1,punto2;
	cout<<"Ingrese los puntos de la recta"<<endl;
	cout<<"Punto 1: x ; y"<<endl;
	cin>>punto1.x;
	cin>>punto2.y;
	cout<<"Punto 2: x ; y"<<endl;
	cin>>punto2.x;
	cin>>punto2.y;
	TExplicita r1(punto1,punto2);
	cout<<"Ingrese los puntos de la recta 2"<<endl;
	cout<<"Punto 1: x ; y"<<endl;
	cin>>punto1.x;
	cin>>punto2.y;
	cout<<"Punto 2: x ; y"<<endl;
	cin>>punto2.x;
	cin>>punto2.y;
	TGeneral r2 (punto1,punto2);
	TRecta *PR;
	PR=&r1;
	cout<<"Puntos  de la recta: ("<<PR->verx1()<<","<<PR->very2()<<")"<<endl;
	cout<<"Puntos  de la recta: ("<<PR->verx2()<<","<<PR->very2()<<")"<<endl;
	cout<<PR->obtener_ecuacion()<<endl;
	
	PR=&r2;
	cout<<"Puntos  de la recta: ("<<PR->verx1()<<","<<PR->very2()<<")"<<endl;
	cout<<"Puntos  de la recta: ("<<PR->verx2()<<","<<PR->very2()<<")"<<endl;
	cout<<PR->obtener_ecuacion()<<endl;
	cout<<"Ingrese el punto que desea verificar"<<endl;
	cin>>punto1.x;
	cin>>punto1.y;
	cout<<PR->pertenece(punto1)<<endl;
	
	
	return 0;
}
