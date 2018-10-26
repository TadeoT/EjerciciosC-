#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T mayor (const T a,const T b){
	if(a>b){
		return a;
	}else return b;
}

template<typename T>
T mayorV (const vector<T> &v){
	T aux;
	for(int i=0;i<v.size();i++){
		if(v[i]>=aux)
			aux=v[i];
	}
	return aux;
}

int main() {
	cout<<"ingrese numero"<<endl;
	
	int a,b;
	cin>>a;
	cin>>b;
	string c="Union",d="Colon";
	
	cout<<mayor(c,d)<<endl;
	cout<<mayor<int>(a,b)<<endl;
	
	vector <int> V(5);
	for(int i=0;i<V.size();i++){
		V[i]=i*9;
	}
	cout<<mayorV<int>(V)<<endl;
	
	return 0;
}

