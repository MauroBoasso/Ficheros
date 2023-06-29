#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

#include "buscarg.cpp"


int guardar() {
	FILE *fichero;
	DATO d;
	int parar;
	do{
		system("cls");
	
	if((fichero = fopen("Registro.txt","ab"))==NULL){
		printf("\nFichero no existe! ");
	}else{
	cout<<"Ingrese el codigo"<<endl;fflush(stdin);
	gets(d.id);
	cout<<"Ingrese un nombre"<<endl;fflush(stdin);
	gets(d.nombre);
	cout<<"Ingrese una edad"<<endl;fflush(stdin);
	cin>>d.edad;
	cout<<"Ingrese un pais"<<endl;fflush(stdin);
	gets(d.pais);
	
	
	if(buscarg(d.id)==true){
		cout<<"Este Codigo ya esta registrado Por favor Ingrese Otro"<<endl;
		system("pause");
	}else{
		fwrite(&d, sizeof(d),1,fichero);
		cout<<"Datos Guardados"<<endl;
		system("pause");
		parar=0;
	}
	
	fclose(fichero);
	}
	}while(parar!=0);
}

