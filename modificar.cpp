#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;
struct datos{
	char id[10];
	char nombre[50];
	int edad;
	char pais[50];
};
typedef struct datos DATO;

int main(int argc, char *argv[]) {
	char id[10],confirmar[2];
	int comparacion=0;
	FILE *fichero;
	DATO d;
	
	
	do{
		fichero=fopen("Registro.txt","r+b");
		fflush(stdin);
		cout<<"\nIngrese el nombre a buscar: ";
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
				
				
				cout<<"\n Estos son los datos? s/n";
				cin>>confirmar[0];
				
				if(confirmar[0]=='s'){
					fflush(stdin);
					cout<<"Ingrese el nombre nuevo: ";
					gets(d.nombre);
					int pos=ftell(fichero)-sizeof(d);
					fseek(fichero,pos,SEEK_SET);
					fwrite(&d, sizeof(d), 1, fichero);
					comparacion=-1;
					break;
				}else{
					comparacion=0;
					break;
				}
			}else{
				comparacion=1;
			}
		}
		if(comparacion==1){
			fflush(stdin);
			cout<<"El dato no existe";
			comparacion=-1;
		}
		
		
	}while(comparacion!=-1);
	fclose(fichero);
	
}

