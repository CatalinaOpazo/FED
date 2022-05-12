#include "ArbolBinarioBusqueda.h"

// ---- Metodos de clase Nodo ---- //


//Constructor nodo raiz
Nodo::Nodo(int valor){

		izq = NULL;
		der = NULL;
		padre =NULL;
		this -> valor = valor;  //el de la derecha es elq ue le pasa la funcion y el de la izq es el de la clase
}

//Constructor nodo no raiz
Nodo::Nodo(int valor, Nodo *padre){

		izq = NULL;
		der = NULL;
		this -> padre = padre;
		this -> valor = valor;

}

//Destructor

Nodo::~Nodo(){

		delete izq;
		delete der;
}




// ---- Metodos del arbol binario ---- //

//Constructor 
ArbolBinarioBusqueda::ArbolBinarioBusqueda(){
		raiz = NULL;
}

//Constructor 
ArbolBinarioBusqueda::ArbolBinarioBusqueda(){
		//IMPLEMENTAR: eliminar todos los nodos hacia abajo
		delete raiz;
}



//Metodo publico para insertar
bool ArbolBinarioBusqueda::insertar(int valor){

		if (raiz == NULL){
			raiz = new Nodo(valor);
			return true; //retorna true pq lo coloco
		}
		return insertar(valor, raiz);
}


//Metodo privado para insertar
bool ArbolBinarioBusqueda::insertar(int valor, Nodo *n){

		//---- Caso base principal
		// Si el valor esta repetido no se inserta el nodo
		if (valor == n -> valor){  //Porque pedimos la clase por referencia (Nodo *n)
			return false;
		}
		

		//Si el valor a insertar es menor al del nodo, hacia la izquierda
		if (valor < n -> valor){

			//si el hijo izq ta vacio
			if (n -> izq == NULL){
				n -> izq = new Nodo(valor,n);
				return true;
			}

			//si el hijo izq no esta vacio hay que seguir bajando
			return insertar(valor,n -> izq);
		}

		//En otro caso insertamos en el nodo derecho
		if (n->der == NULL){
			n -> der = new Nodo(valor,n);
			return true;
		}

		return insertar(valor, n -> der);
}


//Public: buscar
Nodo *ArbolBinarioBusqueda::buscar(int valor){

		return buscar(int valor,raiz);
}

//Private: buscar
Nodo *ArbolBinarioBusqueda::buscar(int valor, Nodo *n){

		// ---- Casos Base ---- //

		//Si es una hoja o una raiz, el valor n existe
		if(n==NULL) return NULL;

		//Si encontramos el valor, retornar direccion del nodo
		if(n-> valor == valor) return n;


		// ---- Casos recursivos ----//
		if (valor < n -> valor) return buscar(valor, n -> izq);

		return buscar(valor, n->der); //si no entra a ninguno de los if anteriores busca en la derecha

}


//Public: imprimir el arbol en orden (inOrder)
void ArbolBinarioBusqueda::inOrder(){

		cout << "In Order: " endl;
		inOrder(raiz);
		cout << endl;
}


//Private: imprimir nodo in Order
void ArbolBinarioBusqueda::inOrder(Nodo *n){

		// ---- Caso Base ----//
		// Si llegamos a una hoja no hay que seguir bajando
		if(n=NULL)
			return;
		inOrder(n -> izq);           //L
		cout << n -> valor << " ";   //V
		inOrder(n -> der);           //R             //Preorder VLR y Postorder LRV
}


//Mayor

