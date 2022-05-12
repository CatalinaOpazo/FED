
#include <iostream>
#include "ArbolBinarioBusqueda.h"
using namespace std;


//map<int,map<int,int*>>
//sizeof devuelve la cantidad de bits de un arreglo, entonces por ejemplo si tenemos int array[n], entonces sizeof(array)/4 = n
//para concatenar arreglos, Arr_1=[1,2,3]
//vector con dos tipos de datos entonces mejor uso pair  vector<pair<int,string>>



//ARBOLEEESSS
// la sucesion de fibonacci a nivel de abstraccion puede ser representada como un arbol

//Como crear un arbol? Puede ser con nodos o con arreglos.
//Hoy veremos NODOS


int main(){
	int n;
	ArbolBinarioBusqueda arbol;

	cout<< "Cantidad de nodos a insertar: ";
	cin>> n;

	for(int i=0;i<n;i++){
		int val;
		cout<<"Valor a insertar: ";
		cin>>val;
		bool insertado=arbol.insertar(val);
		if (insertado)
			cout << val << " insertado!" <<endl;
		else{
			cout << val << " repetido :(, intente otro valor" << endl;
			i--
		}
	}
	arbol.inOrder();

	return 0;
}