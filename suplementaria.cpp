#include <iostream>
#include <sstream>
using namespace std;
struct fecha{
	int dd,mm,aa;
};

class Fechas{
private:
	fecha m_fecha;
	
public:
	Fechas (fecha f1){m_fecha.dd = f1.dd; m_fecha.mm=f1.mm; m_fecha.aa = f1.aa;}
	string verFecha();
	string diferenciaAnios(Fechas f2);
	int verDia(){return m_fecha.dd;}
	int verMes(){return m_fecha.mm;}
	int verAnio(){return m_fecha.aa;}
	
};


int main(int argc, char *argv[]) {
	fecha cumple;
	cout<<"Ingrese la fecha: dd/mm/aa"<<endl;
	cin>>cumple.dd;
	cin>>cumple.mm;
	cin>>cumple.aa;

	Fechas f1 (cumple);
	cout<<"Ingrese la fecha 2: dd/mm/aa"<<endl;
	cin>>cumple.dd;
	cin>>cumple.mm;
	cin>>cumple.aa;
	Fechas f2 (cumple);
	
	cout<<f1.verFecha()<<endl;
	cout<<f2.verFecha()<<endl;
	cout<<f1.diferenciaAnios(f2)<<endl;
	
	
	return 0;
}
string Fechas::verFecha(){
	stringstream aux;
	aux.str("");
	aux<<"La fecha ingresada: "<<m_fecha.dd<<"/"<<m_fecha.mm<<"/"<<m_fecha.aa<<endl;
	return aux.str();
}
string Fechas::diferenciaAnios(Fechas f2){
	int dias;
	dias= (((m_fecha.aa - f2.verAnio())*12)*30)+((m_fecha.mm - f2.verMes())*30)+(m_fecha.dd - f2.verDia());
	stringstream aux;
	aux.str("");
	aux<<"Diferencia: "<<dias<<"dias"<<endl;
	return aux.str();
	
}

