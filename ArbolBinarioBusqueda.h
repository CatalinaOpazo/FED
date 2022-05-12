#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H
#include <iostream>

class Nodo{  //Usualmente los nombres de las clases comienzan con mayuscula
	public:
		int valor;
		Nodo *izq;
		Nodo *der; //Aqui vimos los ATRIBUTOS, falta hacer el constructor y el destructor
		Nodo *padre;

		//El constructor es un METODO siempre tiene el nombre de la clase,
		Nodo(int valor);              //Constructor raiz
		Nodo(int valor, Nodo *padre); //Constructor nodo cualquiera
		~Nodo();                      //Destructor
}

class ArbolBinarioBusqueda{
	public:
		ArbolBinarioBusqueda();   //Constructor
		~ArbolBinarioBusqueda();  //Destructor
		bool insertar(int valor); //No acepta valores repetidos, si lo puede insertar devuelve TRUE si estaba repetido no lo inserta y devuelve FALSE
		Nodo *buscar(int valor);  //Si no existe, return null
		void inOrder();

	private:
		Nodo *raiz;                           //Puntero a la raiz
		bool insertar(int valor, Nodo *n);	  //Insertar un nodo en el nodo *n
		Nodo *buscar(int valor, Nodo *n);     //Si lo encuentra devuelve el nodo y si no me devuelve un puntero a null
		void inOrder(Nodo *n);				  //Recorre el arbol desde el nodo *n
		Nodo *mayor(Nodo *n); 				  //Retorna el nodo de mayor valor


}
