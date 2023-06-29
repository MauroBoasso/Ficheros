#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <fstring>

using namespace std;
struct datos{
	char id[10];
	char nombre[50];
	int edad;
	char pais[50];
};
typedef struct datos DATO;
#include "guardar.cpp"
#include "mostrar.cpp"
#include "buscar.cpp"
#include "modificar2.cpp"
#include "EliminarA.cpp"
int main(int argc, char *argv[]) {
		int opcion;
		do{
			system("cls");
			cout<<"1. Guardar"<<endl;
			cout<<"2. Mostrar"<<endl;
			cout<<"3. Buscar"<<endl;
			cout<<"4. Actualizar"<<endl;
			cout<<"5. Eliminar"<<endl;
			cout<<"0. Salir"<<endl;
			cin>>opcion;
			
			switch(opcion){
			case 1:{
				guardar();
				break;
			}
			case 2:{
					
			 system("cls");
				 mostrar();
				break;
			}
			case 3:{
				 system("cls");
				 buscar();
				break;
			}
			case 4:{
					 
				system("cls");
				modificar();
					 break;
			}
			case 5:{
					
				system("cls");
				eliminar();
					break;
			}
			case 0:{
					cout<<"Gracias Por Usar Nuestro Programa"<<endl;
				system("pause");
				break;
				}
			default:{
				cout<<"Esta Opcion No Existe "<<endl;
				system("pause");
				break;
		    }
								
			}
		} while(opcion!=0);

}

