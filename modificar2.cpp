#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;

int modificar() {
	char id[10],confirmar[2];
	int comparacion=0,opcion=0;
	FILE *fichero;
	DATO d;
	
	
	do{
		system("cls");
		fichero=fopen("Registro.txt","r+b");
		fflush(stdin);
		cout<<"\nIngrese el id a buscar: ";
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
				cout<<"\n|_______________________________________________"<<endl;
				
				
				cout<<"\n Estos son los datos? s/n";
				cin>>confirmar[0];
				
				if(confirmar[0]=='s'){
					do{
						cout<<"1. Modificar todos los datos \n";
						cout<<"2. Modificar nombre \n";
						cout<<"3. Modificar edad \n";
						cout<<"4. Modificar pais \n";
						cout<<"5. Salir \n";
						fflush(stdin);
						cin>>opcion;
						
						switch(opcion){
						case 1:{
							fflush(stdin);
							cout<<"Ingrese el nombre nuevo: ";fflush(stdin);
							gets(d.nombre);
							cout<<"Ingrese la edad nueva: ";fflush(stdin);
							cin>>d.edad;
							cout<<"Ingrese el pais nuevo: ";fflush(stdin);
							gets(d.pais);
							int pos=ftell(fichero)-sizeof(d);
							fseek(fichero,pos,SEEK_SET);
							fwrite(&d, sizeof(d), 1, fichero);
							comparacion=-1;
							break;
						}
						case 2:{
							fflush(stdin);
							cout<<"Ingrese el nombre nuevo: ";fflush(stdin);
							gets(d.nombre);
							int pos1=ftell(fichero)-sizeof(d);
							fseek(fichero,pos1,SEEK_SET);
							fwrite(&d, sizeof(d), 1, fichero);
							comparacion=-1;
							break;
							}
						case 3:{
							fflush(stdin);
							cout<<"Ingrese la edad nueva: ";fflush(stdin);
							cin>>d.edad;
							int pos2=ftell(fichero)-sizeof(d);
							fseek(fichero,pos2,SEEK_SET);
							fwrite(&d, sizeof(d), 1, fichero);
							comparacion=-1;
							break;
							}
						case 4:{
							fflush(stdin);
							cout<<"Ingrese el pais nuevo: ";fflush(stdin);
							gets(d.pais);
							int pos3=ftell(fichero)-sizeof(d);
							fseek(fichero,pos3,SEEK_SET);
							fwrite(&d, sizeof(d), 1, fichero);
							comparacion=-1;
							break;
							}
						case 5:{
							cout<<"Usted esta saliendo de la modificacion \n";
							comparacion=-1;
							break;
							}
						default:{
							cout<<"Opcion no valida \n";
							break;
							}
						}
					}while(opcion!=5);
					break;
				}else{
					comparacion=0;
					break;
				}
			}else{
				comparacion=1;
			}
		}
		if(comparacion==1 or comparacion==1){
			fflush(stdin);
			cout<<"El dato no existe";
			system("pause");
			comparacion=-1;
		}
		
		
	}while(comparacion!=-1);
	fclose(fichero);
	
}
