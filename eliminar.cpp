#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;


int eliminaraux(char a[10]) {
	
	FILE *fichero, *ficheroaux;
	DATO d;
	ficheroaux=fopen("Registro2.txt","wb");
	fichero=fopen("Registro.txt","rb");
	
	if(!fichero){
		printf("Fichero no existe");
	}
	else{
		
	
		//Recibe los mismo parametros que fwrite
		while(fread(&d, sizeof(datos),1, fichero)){
			
			if (strcmp(d.id,a))
				fwrite(&d, sizeof(datos),1, ficheroaux);
		}
		
		
	}
	fclose(fichero);
	fclose(ficheroaux);
	remove("Registro.txt");
	rename("Registro2.txt","Registro.txt");
	return true;
	
}

