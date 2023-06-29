#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;

#include "eliminar.cpp"
int eliminar() {
	char id[10],confirmar[10];
	int comparacion=0;
	FILE *fichero;
	DATO d;
	int parar;
	do{
	system("cls");
	fichero=fopen("Registro.txt","r+b");
	fflush(stdin);
	cout<<"\nIngrese el id a eliminar: ";
	gets(id);
	
	while(!feof(fichero))
	{
		fread(&d, sizeof(d), 1, fichero);
		comparacion=strcmp(id, d.id);
		if(comparacion==0)
		{
			cout<<"\n _______________________________________________";
			cout<<"\n| ID........ "<<d.id<<"\t\t\t\t\t|";
			cout<<"\n| Nombre.... "<<d.nombre<<"\t\t\t\t|";
			cout<<"\n| Edad...... "<<d.edad<<"\t\t\t\t\t|";
			cout<<"\n| Pais...... "<<d.pais<<"\t\t\t\t|";
			cout<<"\n|_______________________________________________";
			cout<<endl<<"Estos son los Datos a Eliminar"<<endl;
			cout<<"s/n"<<endl;
			gets(confirmar);fflush(stdin);
			if(confirmar[0]=='s'){
				fclose(fichero);
				if(eliminaraux(id)==true){
					cout<<"Datos Eliminados"<<endl;
					system("pause");
					parar=0;
				}
			}
			
			break;
		}
	}
	if(comparacion==-1 or comparacion==1){
		cout<<"El dato no existe"<<endl;
		system("pause");
	}
	}while(parar!=0); 
}


