	#include <iostream>
	#include <conio.h>
	#include <stdio.h>
	#include <cstdlib>
	#include <string.h>
	using namespace std;
	
	int buscar() {
		char id[10];
		int comparacion=0;
		FILE *fichero;
		DATO d;
		fichero=fopen("Registro.txt","r+b");
		cout<<"\nIngrese el id a buscar: ";
		fflush(stdin);
		gets(id);
		system("pause");
		
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
				cout<<"\n|_______________________________________________"<<endl;
				break;
			}
		}
		if(comparacion==-1){
			cout<<"El dato no existe" << endl;
		}
	}

