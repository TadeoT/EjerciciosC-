#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Alumno{
	char nombre[50];
	int nota1,nota2;
	
};
template<typename T>
class ManejadorArchivo{
private:
	string direccion;
	vector <T> v;
public:
	ManejadorArchivo(string ruta){
		direccion=ruta;
		T aux;
		fstream f (direccion,ios::in|ios::out|ios::binary|ios::ate);
		int tamanio_b =f.tellg();
		int tamanio_real= tamanio_b/sizeof(T);
		for(int i=0;i<tamanio_real;i++){
		f.seekg(i*(sizeof(T)),ios::beg);
		f.read(reinterpret_cast<char*>(&aux),sizeof(T));
		v.push_back(aux);
		
		}
		f.close();
		
	}
	T obtenerRegistro(int posicion){
		T aux;
		aux=v[posicion];
		return aux;
	}
	void modificarRegistro(int posicion,T aux){
		v[posicion]=aux;
	}
	void agregarRegistro(T aux){
		v.push_back(aux);
	}
	void grabar(){
		fstream f(direccion,ios::binary|ios::in|ios::out);
		for(unsigned int i=0;i<v.size();i++){
			f.write(reinterpret_cast<char*>(&v[i]),sizeof(T));
		}
		f.close();
	}
	void eliminarRegistro(int posicion){
		
	}
	vector<T> verDatos(){return v;}
	
	
};
int main() {
	Alumno aux;
	int numeroUsuario,decision;
	string nombreNuevo="nombre";
	vector<Alumno> datos;
	ManejadorArchivo<Alumno> L1 ("listas.dat");
	datos= L1.verDatos();
	for(unsigned int i=0;i<datos.size();i++){
		cout<<i<<"-"<<datos[i].nombre<<" "<<datos[i].nota1<<" "<<datos[i].nota2<<endl;
	}
	
	cout<<"si desea agregar un nuevo usuario ingrese 1, modificar 2 y 3 si desea eliminar"<<endl;
	cin>>decision;
	if(decision == 2){
		cout<<"Ingrese usuario a modificar"<<endl;
		cin>>numeroUsuario;
		cout<<"Ingrese nombre nuevo, NOTA1 y NOTA2"<<endl;
		cin>>nombreNuevo;
		cin>>aux.nota1;
		cin>>aux.nota2;
		strcpy(aux.nombre,nombreNuevo.c_str());
		L1.modificarRegistro(numeroUsuario,aux);
		L1.grabar();
	} if (decision == 1){
		cout<<"Ingrese nombre nuevo, NOTA1 y NOTA2"<<endl;
		cin>>nombreNuevo;
		cin>>aux.nota1;
		cin>>aux.nota2;
		strcpy(aux.nombre,nombreNuevo.c_str());
		L1.agregarRegistro(aux);
		L1.grabar();
	}if(decision == 3){
		cout<<"Ingrese la posicion que desea eliminar"<<endl;
		cin>>numeroUsuario;
		L1.eliminarRegistro(numeroUsuario);
		L1.grabar();
	}
	
	datos= L1.verDatos();
	for(unsigned int i=0;i<datos.size();i++){
		cout<<i<<"-"<<datos[i].nombre<<" "<<datos[i].nota1<<" "<<datos[i].nota2<<endl;
	}
	
	
	return 0;
}

