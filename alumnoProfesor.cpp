#include <iostream>
using namespace std;
struct fecha{
	int dd,mm,aa;
	
};
class Persona{
private:
	string apellido,nombre;
	long dni;
	fecha f;
	char estadoC;
public:
	Persona(string ape,string nom,long dn,fecha fech,char eC){
	apellido=ape;nombre=nom;dni=dn;f=fech;estadoC=eC;
	}
	int calcular(fecha fechaActual){return f.dd;}
	void cargarDatos(string ape,string nom,long dn,fecha fech,char eC){
		apellido=ape;nombre=nom;dni=dn;f=fech;estadoC=eC;
	}
	string mostrar(){return apellido;}
	void mostrarF(){cout<<"Fecha "<<f.dd<<"/"<<f.mm<<"/"<<f.aa<<endl;}
	
};
class Alumno:public Persona{
private:
	int materiasA;
	float prom;
	
public:
	Alumno(string ape,string nom,long dn,fecha fech,char eC,int materias,float p):Persona(ape,nom,dn,fech,eC){
		materiasA=materias;prom=p;
		
	}
	float promedio(){
		return materiasA*prom;
	}
};
class Docente:public Persona{
private:
	fecha ingreso;
	
public:
	Docente(string ape,string nom,long dn,fecha fech,char eC,fecha Fingreso):Persona(ape,nom,dn,fech,eC){
		ingreso=Fingreso;
		
	}
	int Antiguedad(){
		return 2018-ingreso.aa;}
	};
int main(int argc, char *argv[]) {
	string apellido,nombre;
	long dni;
	fecha fechaN,fechaI;
	char estadoCivil;
	int materias;
	float promedio;
//	Alumno
	cout<<"Ingrese Apellido"<<endl;
	cin>>apellido;
	cout<<"Ingrese Nombre"<<endl;
	cin>>nombre;
	cout<<"Ingrese DNI"<<endl;
	cin>>dni;
	cout<<"Ingrese dia/mes/año"<<endl;
	cin>>fechaN.dd;
	cin>>fechaN.mm;
	cin>>fechaN.aa;
	cout<<"Ingrese EstadoCivil"<<endl;
	cin>>estadoCivil;
	cout<<"Ingrese materias aprobadas"<<endl;
	cin>>materias;
	cout<<"Ingrese promedio"<<endl;
	cin>>promedio;
	Alumno a1(apellido,nombre,dni,fechaN,estadoCivil,materias,promedio);	
//	PROFESOR
	cout<<"Ingrese Apellido"<<endl;
	cin>>apellido;
	cout<<"Ingrese Nombre"<<endl;
	cin>>nombre;
	cout<<"Ingrese DNI"<<endl;
	cin>>dni;
	cout<<"Ingrese dia/mes/año"<<endl;
	cin>>fechaN.dd;
	cin>>fechaN.mm;
	cin>>fechaN.aa;
	cout<<"Ingrese EstadoCivil"<<endl;
	cin>>estadoCivil;
	cout<<"Ingrese Fecha Ingreso"<<endl;
	cin>>fechaI.dd;
	cin>>fechaI.mm;
	cin>>fechaI.aa;
	Docente d1(apellido,nombre,dni,fechaN,estadoCivil,fechaI);
	//COUTSSSS
	cout<<"ALUMNO    "<<endl;
	cout<<a1.mostrar()<<endl;
	cout<<"Rendimiento Academico: "<<a1.promedio()<<endl;
	a1.mostrarF();
	
	cout<<"DOCENTE    "<<endl;
	cout<<d1.mostrar()<<endl;
	cout<<"Antiguidad: "<<d1.Antiguedad()<<endl;
	
	
	return 0;
}

