#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
using namespace std;
struct datos{
	string nombre;
	int nota1,nota2;
	float promedio;
	bool condicion;
};

void Actualizar(vector<datos> &a,datos nuevo){
	for(unsigned int i=0;i<a.size();i++){
		if(nuevo.nombre==a[i].nombre){
			a[i].nota1=nuevo.nota1;
			a[i].nota2=nuevo.nota2;
			a[i].promedio=(nuevo.nota1+nuevo.nota2)/2;
				if(a[i].promedio>=60){
				a[i].condicion=true;
			}else a[i].condicion=false;
		}
	}
}


int main() {
	
	ifstream fR;
	ofstream fW;
	int ban=0;
	datos aux,modificar;
	vector<datos>  Alumnos;
	
	
	fR.open("lista.txt");
	if(fR.is_open()){
	while(getline(fR,aux.nombre) && fR>>aux.nota1>>aux.nota2){
		aux.promedio=(aux.nota1+aux.nota2)/2.0;
		if(aux.promedio>=60){
			aux.condicion=true;
		}else aux.condicion=false;
		Alumnos.push_back(aux);
		cout<<Alumnos[ban].nombre<<endl;
		cout<<"Nombre: "<<aux.nombre<<endl;
		cout<<"Nota1: "<<aux.nota1<<"   ||   Nota2 "<<aux.nota2<<endl;
		cout<<"Promedio : "<<aux.promedio<<endl;
		if(aux.condicion){
			cout<<"Condicion: Aprobado"<<endl;
		}else cout<<"Condicion: Desaprobado"<<endl;
		cout<<"---------------------------------------------------"<<endl;
		
		
		fR.ignore();
		ban++;
	}
	}else {
		cout<<"No se pudo abrir el archivo"<<endl;
		return 0;
	}
	
	fR.close();
	
	
	cout<<"INGRESE EL NOMBRE DEL ALUMNO A MODIFICAR"<<endl;
	getline(cin,modificar.nombre);
	cout<<"INGRESE NOTA 1"<<endl;
	cin>>modificar.nota1;
	cout<<"INGRESE NOTA 2"<<endl;
	cin>>modificar.nota2;
	
	Actualizar(Alumnos,modificar);
	
	
	
	fW.open("lista.txt",ios::trunc);
	for(int i=0;i<Alumnos.size();i++){
		fW<<Alumnos[i].nombre<<endl;
		fW<<Alumnos[i].nota1<<endl;
		fW<<Alumnos[i].nota2<<endl;
	}
	
	fW.close();
	
	
	fW.open("promedio.txt",ios::trunc);
	
	for(int i=0;i<Alumnos.size();i++)    {
		fW<<"Nombre :"<<Alumnos[i].nombre<<endl;
		fW<<"Promedio :"<<Alumnos[i].promedio<<endl;
		fW<<"Condicion : "<<Alumnos[i].condicion<<endl;
	}
	fW.close();
	
	return 0;
}

