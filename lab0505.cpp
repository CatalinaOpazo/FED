#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

//Correo ayudante
//Timus es un juez virtual que traen problemas https://acm.timus.ru/probelam.aspx?space=18&num=1585
//Nos dan el input, el output para un caso de prueba.

//cuando nos entreguen los datos debemos pensar como leerlos. En el ejemplo, primero hay que guardar el 7 como un entero:


/*int main(){
	int n;
	string p;

	cin>>n;

	int m = 0,l = 0,e = 0;

	for (int i=0;i<n;i++){
		//cin>>p;
		getline(cin,p); //in es para recibir, getline lee la linea completa
		getchar();
		if (p == "Emperor Penguin") e++; //tambien se puede usar p.compare("Emperor Penguin")
		else if (p=="Macaroni Penguin") m++;
		else l++;
	}

	if (e>m && e>l) cout<< "Emperor Penguin" <<endl;
	else if(m > e && m>l) cout<<"Macaroni Penguin"<<endl;
	else cout <<"Little Penguin" << endl;

	return 0;
}
*/



//https://acm.timus.ru/problem.aspx?space=1&num=1100
//1100

bool comp(const pair<int,int> &p1,const pair<int,int> &p2){  //const hace que NO SE PUEDAN CAMBIAR LOS DATOS DE LA ENTRADA
	//El amperson es para no tener que ir creando copias de las ws
	return p2.second < p1.secont  //para ordenar de mayor a menor
}


int main(){
	int n;
	cin<< n;

	vector<pair<int,int>> pares; //para crear el vector

	for(int i=0;i<n;i++){
		cin >> a;
		cin >> b; 
		pares.pushback(make_pair(a,b));
	}
	stable_sort(pares.begin(),pares.end(),&comp);

	cout << "Sorted" << endl;
	for(int i=0; i <n; i++){
		cout << pares[i].first << " " << pares[i].second << endl;
	}	


	return 0
}
