#include <iostream>
using namespace std;
class FECHA{
private:
	int dia,mes,anio;
	
public:
	FECHA(int a,int b,int c){dia=a;mes=b;anio=c;}
	void c_dia(int fecha){dia=fecha;}
	void c_mes(int fecha){mes=fecha;}
	void c_anio (int fecha){anio=fecha;}
	int verDia(){return dia;}
	int verMes(){return mes;}
	int verAnio(){return anio;}
	
};

bool operator<= (FECHA f1,FECHA f2){
	if(f1.verAnio()<f2.verAnio()){
		return true;
	}
	if(f1.verAnio()>f2.verAnio()){
		return false;
	}
	
	
	
	
	if(f1.verAnio()==f2.verAnio()){
		if(f1.verMes()<f2.verMes()){
			return true;
		}
		if (f1.verMes()>f2.verMes()){
			return false;
		}
		
		
		
		if(f1.verMes()==f2.verMes()){
			if(f1.verDia()<f2.verDia()){
				return true;
			}
			if (f1.verDia()>f2.verDia()){
				return false;
			}
			if (f1.verDia()==f2.verDia()){
				return true;
			}
	}
	}
}

int main(int argc, char *argv[]) {
	cout<<"ingrese Fecha dd/mm/aa "<<endl;
	int d,m,a;
	cin>>d;
	cin>>m;
	cin>>a;
	FECHA fecha1(d,m,a);
	cout<<"ingrese Fecha dd/mm/aa "<<endl;
	cin>>d;
	cin>>m;
	cin>>a;
	FECHA fecha2(d,m,a);
	
	if(fecha1<=fecha2){
		cout<<"La primer Fecha es Menor o igual"<<endl;
	}else{
		cout<<"La primer Fecha es Mayor"<<endl;
	}
	
	return 0;
}

