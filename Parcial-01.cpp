#include <iostream>
#include <vector>
using namespace std;
class vec {
private:
	int m_e;
	float *m_ar;
	
public: 
	vec(){}
	vec(int e){
	m_e=e;
	m_ar= new float[e];
}
	vec(vec &v2){
	m_e=v2.verCantidad();
	m_ar= new float [m_e];
	for(int i=0;i<m_e;i++){
		m_ar[i]=v2.verVector()[i];
	}
}
void cargarVector(){
	for(int i=0;i<m_e;i++){
		cout<<"ingrese vector"<<endl;
		cin>>m_ar[i];
	}
}
float* verVector(){return m_ar;}
~vec(){
	delete [] m_ar;
}
int verCantidad(){return m_e;}
};
class Perfomance{
private:
	int Cmaterias;
	vec Notas;
	
	
public:
	Perfomance(vec &nts){
		Cmaterias=nts.verCantidad();
		Notas = nts;
	}
	
	float verPromedio(){
	float p;
	int dividir;
	for(int i = 0; i<Cmaterias;i++){
		p+= Notas.verVector()[i];
		dividir=i;
	}
	p = (p / (dividir+1));
	return p;
}
	
	
	
	
};
int main(int argc, char *argv[]) {
	int materias;
	cout<<"ingrese materias"<<endl;
	cin>>materias;
	
	
	vec Valumno1 (materias);
	Valumno1.cargarVector();
	
	Perfomance a1(Valumno1);
	cout<<"El promedio es :"<<a1.verPromedio();
	
	
	return 0;
}

