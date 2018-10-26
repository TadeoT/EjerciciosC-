#include <iostream>
using namespace std;

template<typename T>
void Clamp(T a, T b, T &var){
	if(var>a) var=a;
	if(var<b) var=b;
	
}

int main() {
	char a='Z',b='A',var;
	int num;
	bool bandera=true;
	while(bandera){
	cout<<"ingrese numero. Para que sea valido debe estar entre: "<<a<<" y "<<b<<endl;
	cin>>var;
	
	Clamp<char>(a,b,var);
	cout<<"el numero :"<<var<<endl;
	cout<<"Desea seguir presione 1"<<endl;
	cin>>num;
	if(num==1){
		bandera=true;
	}else bandera=false;
	}
	return 0;
}

