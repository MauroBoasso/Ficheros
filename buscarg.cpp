#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;


int buscarg(char a[10]) {

	int comparacion=0;
	FILE *fichero;
	DATO d;
	fichero=fopen("Registro.txt","r+b");
	
	
	while(!feof(fichero))
	{
		fread(&d, sizeof(d), 1, fichero);
		comparacion=strcmp(a, d.id);
		if(comparacion==0)
		{
			return true;
			break;
		}
	}
	if(comparacion==-1){
		cout<<"El dato no existe";
	}
}

