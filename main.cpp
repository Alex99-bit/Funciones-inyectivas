#include <iostream>
#include <windows.h>
#include <cmath>
#include <pthread.h>
using namespace std;

#include "Funciones.h"

#define sys system

int main(){
	short int op;
	Funciones obj;
	cout<<"\n\t1.-Iniciar programa\n\t0.-Salir\n\n\t>> ";
	cin>>op;
	while(op){
		sys("cls");
		obj.set_ab();
		obj.ini_hilos();
		cout<<"\n\t";
		sys("pause");
		sys("cls");
		cout<<"\n\t1-Otro proceso\n\t0-Salir\n\n\t>> ";
		cin>>op;
		while(op<0 || op>1){
			cout<<"\n\tOpcion invalida"<<endl;
			cout<<"\n\t1-Otro proceso\n\t0-Salir\n\n\t>> ";
			cin>>op;
		}
	}
	return 0;
}
