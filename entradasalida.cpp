#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void show(vector<string> v){
	for(int i=0;i<v.size();i++) { 
		cout << v[i] << endl;
	}
	cout << endl;
}

int main() {
	ifstream fL;
	ofstream fE;
	int cantidad=0;
	string provincias;
	fL.open("provincias.txt");
	
	vector<string> v;
	
	while(fL>>provincias){
		v.push_back(provincias);
	}
	show(v);
	fL.close();
	cout<<"Cantidad de Provincias Ingresadas :"<<v.size()<<endl;
	sort(v.begin(), v.end());
	show(v);
	
	fE.open("provincias.txt",ios::trunc);
	
	for(int i=0;i<v.size();i++) { 
		fE<<v[i]<<endl;
	}

	
	fE.close();
	
	return 0;
}

