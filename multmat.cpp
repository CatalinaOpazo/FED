#include <iostream>
using namespace std;


// declarar funcion para imprimir matriz por filas
void printMat(int **mat, int n, int m){
		for(int i=0; i<n; i++){  
			for(int j=0; j<m; j++){
				cout << mat[i][j] << " ";
			}
			cout << endl;
	}
	
}


int **pedirMat(int n, int m){
	int **mat = new int*[n];

	for(int i=0; i<n; i++){
		mat[i] = new int[m];
	}

	for(int i=0; i<n; i++){  //las pide por fila
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}

	printMat(mat,n,m);
	return mat;
}

int **pedirMatTR(int n, int m){

	int **mat = new int*[m];

	for(int i=0; i<m; ++i){
		mat[i] = new int[n];
	}
	
	for(int i=0;i<n;++i){
		for(int j=0; j<m;++j){
			cin >> mat[j][i];
		}
	}

	printMat(mat,m,n);
	return mat;
}

int **crearMat(int n,int m){
	int **mat = new int*[n];

	for(int i=0; i<n; i++){
		mat[i] = new int[m];
	}
	return(mat);
}

int **multMat(int** mat1,int n1,int m1, int** mat2,int n2,int m2){
	int **mat=crearMat(n1,m2);

	for(int i=0; i<n1; i++){
	   	for(int j=0; j<m2; j++){
	   		mat[i][j]=0;
	   		for(int l=0; l<m1; l++){
	   			mat[i][j]+= mat1[i][l]*mat2[l][j];
	   		}
	   	}
	}
	return(mat);
}

int **multMatOpt(int n1, int m1, int n2, int m2){
	int **mat1=pedirMat(n1,m1);
	int **mat2=pedirMatTR(n2,m2);

	int **mat=crearMat(n1,m2);

	for(int i=0; i<n1; ++i){
	   	for(int j=0; j<m2; ++j){
	   		mat[i][j]=0;
	   		for(int k=0; k<m2; ++k){
	   			mat[i][j]+= mat1[i][k]*mat2[j][k];
	   			
	   		}
	   	}
	}


	delete[] mat1;
	delete[] mat2;
	return(mat);
}

int main(){
	int n1,m1,n2,m2;
	cout << "n1 xd";
	cin >> n1;
	cout << "m1 ";
	cin >> m1;
	cout << "n2 ";
	cin >> n2;
	cout << "m2 ";
	cin >> m2;

	if(n1 != m2){
		cout <<"no se puede XD";
		return (0);
	}

	int **res=multMatOpt(n1,m1,n2,m2);
	printMat(res,n1,m2);
	return(0);
}