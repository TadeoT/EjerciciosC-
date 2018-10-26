#include <iostream>
using namespace std;

class Cuerpo{
	float a,b,volumen;
	string name;
public:
	Cuerpo(float ladRad1,float lado2,string nombre){a=ladRad1;b=lado2;name=nombre;}
	virtual float calcular_volumen()=0;
	float verA(){return a;}
	float verB(){return b;}
	float verVolumen(){return volumen;}
	void cargarVolumen(float vol){volumen=vol;}
	void cargarA(float a){this->a=a;}
	void cargarB(float b){this->b=b;}
	string verNombre(){return name;};
	
};
class Prismacuadrado:public Cuerpo{
public:
	Prismacuadrado(float ladoradio,float lado2,string name="Cuadrado"):Cuerpo(ladoradio,lado2,name){name="cuadrado";}
	float calcular_volumen() override;
	
};
class Cilindro:public Cuerpo{
public:
	Cilindro(float ladoradio,float altura,string name="cilindro"):Cuerpo(ladoradio,altura,name){name="Cilindro";}
	float calcular_volumen() override;
};

Prismacuadrado operator+(Prismacuadrado Prismacuadrado1,Prismacuadrado Prismacuadrado2){
	float a,b;
	a=Prismacuadrado1.verA()+Prismacuadrado2.verA();
	b=Prismacuadrado1.verB()+Prismacuadrado2.verB();
	
	
	Prismacuadrado aux(a,b);
	return aux;
}
ostream &operator<< (ostream &salida,Cuerpo &c){
salida<<"el volumen del "<<c.verNombre()<<" es: "<<c.calcular_volumen()<<endl;;
	return salida;
}

int main(int argc, char *argv[]) {
	Cuerpo *pr;
	Prismacuadrado cuadrado1(2,4),cuadrado2(4,2),cuadrado3(0,0);
	Cilindro cil1(2,4);
	pr=&cuadrado1;
	cout<<*pr;
	pr=&cil1;
	cout<<*pr;
	cuadrado3=cuadrado1+cuadrado2;
	pr=&cuadrado2;
	cout<<*pr;
	pr=&cuadrado3;
	cout<<*pr;
	
	return 0;
}

float Prismacuadrado::calcular_volumen(){
	float aux;
	aux=verA()*verB();
	cargarVolumen(aux);
	return verVolumen();
}
float Cilindro::calcular_volumen(){
	float aux;
	aux=(verA()*verA())*3.1415*verB();
	cargarVolumen(aux);
	return verVolumen();
}
