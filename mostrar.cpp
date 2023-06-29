#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;


int mostrar() {
	FILE *fichero;
	DATO d;
	
	if((fichero=fopen("Registro.txt","rb"))==NULL){
		cout<<"No existe fichero";
	}else{
		fread(&d,sizeof(d),1,fichero);
		while(!feof(fichero)){
			cout<<"\n _______________________________________________";
			cout<<"\n| ID........ "<<d.id<<"\t\t\t\t\t|";
			cout<<"\n| Nombre.... "<<d.nombre<<"\t\t\t\t|";
			cout<<"\n| Edad...... "<<d.edad<<"\t\t\t\t\t|";
			cout<<"\n| Pais...... "<<d.pais<<"\t\t\t\t|";
			cout<<"\n|_______________________________________________"<<endl;
			
			fread(&d,sizeof(d),1,fichero);
		}
	}
	fclose(fichero);
	system("pause");
}

