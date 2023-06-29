#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void buscarPersona (ifstream %Lec){
	system("cls");
	Lec.open ("Personas.txt" , ios::in);
	string nom,ape,id,idaux;
	bool encontrado=false;
	cout << "Digite la Id: ";
	cin >> idaux;
	Lec>> nom;
	while(!Lec.eof() && !encontrado){
		Lec >> ape;
		Lec >> id;
			if (id == idaux){
				system("cls");
				cout<<"1. Guardar"<<endl;
				cout<<"2. Mostrar"<<endl;
				cout<<"3. Buscar"<<endl;
				cout<<"4. Actualizar"<<endl;
				cout<<"5. Eliminar"<<endl;
				cout<<"0. Salir"<<endl;
				encontrado=true;
				
			}
			Lec >> nom;
	}
	Lec.close();
	if(!encontrado)
		cout << "Dato no encontrado" << endl;
	system("pause");
	
}


void modificar (ifstream &Lec){
	system("cls");
	string nom,id,ape,idaux,nomaux;
	Lec.open("Personas.txt" , ios::in);
	ofstream aux ("auxiliar.txt" , ios::out);
	
	if(Lec.is_open()){
		cout << "Id "<< endl;
		cin >> idaux;
		Lec>> nom;
		
		while(!Lec.eof()){
			Lec>> ape;
			Lec >> id;
			if (id == idaux){
				cout << "Nuevo Nombre ";
				cin >> nomaux;
				aux << nomaux<< " " << ape <<" " << id << endl;
			}
			else{
					aux << nom << " " << ape << " " << id << endl;
					
				}
				
			
			Lec >> nom;
		}
		
		Lec.close();
		aux.close();
	}
	else 
		cout << "error" << endl;
	remove("Personas.txt");
	rename("auxiliar.txt", "Personas.txt");
}

void eliminar (ifstream &Lec){
	system("cls");
	string nom,id,ape,idaux,nomaux;
	Lec.open("Personas.txt" , ios::in);
	ofstream aux ("auxiliar.txt" , ios::out);
	
	if(Lec.is_open()){
		cout << "Id "<< endl;
		cin >> idaux;
		Lec>> nom;
		
		while(!Lec.eof()){
			Lec>> ape;
			Lec >> id;
			if (id == idaux){
				cout << "Eliminado" << endl;
				Sleep(1500);
				
			else{
					aux << nom << " " << ape << " " << id << endl;
					
			}
				
			}
			Lec >> nom;
		}
		
		Lec.close();
		aux.close();
	}
	else 
				   cout << "error" << endl;
	remove("Personas.txt");
	rename("auxiliar.txt", "Personas.txt");
}




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
					buscarPersona();
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
	
	return 0;
}

