#include <iostream>
using namespace std;
class vec {
private:
	int m_e;
	int *m_ar;
	
public: vec(int e){
		m_e=e;
		m_ar= new int[e];
	}
	void cargarVector(){
		for(int i=0;i<m_e;i++){
			cout<<"ingrese vector"<<endl;
			cin>>m_ar[i];
		}
	}
	int* verVector(){return m_ar;}
	~vec(){
		delete [] m_ar;
	}
	
	
	
};
int main(int argc, char *argv[]) {
	int e;
	cout<<"Ingrese tamaño arreglo"<<endl;
	cin>>e;

	vec v1(e);
	v1.cargarVector();
	for(int i=0;i<e;i++){
		cout<<v1.verVector()[i]<<endl;
	}
	
	

	return 0;
}

