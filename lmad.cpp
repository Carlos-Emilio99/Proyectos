#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct datos {
	int ID, Bclave;
	char Nombre[40], NSub[20];
	float precio;
	ofstream Temp;
};
typedef struct datos DATO;

int menu();

string Agregar() {
	ofstream archivo("Agregar.txt",ios::app);
	string Nombre,NSub[' '],IDSub[' '], ID, Precio, PSub[' '];
	int  op1, op2,i=0,k=0,v1=1000,v2=9999,v3=01,v4=99,z;
	bool valido = false;

	system("cls");
	do {
		cout << "Ha escogido la opcion de Agregar Servicios" << endl;
		do{
			cout << "1.Agregar Servicios\n2.Regresar al Menu Principal " << endl;
			cin >> op1;
			fflush(stdin);
		}while(op1 < 1 || op1 > 2);
		if (op1 == 1)
		{
			system("cls");
			if (!archivo.is_open())
			{
				archivo.open("Agregar.txt", ios::out);
			}
			cout << "Cual es el nombre del Servicio?" << endl;
			cin >> Nombre;
			fflush(stdin);
			do{
					cout << "Cual es el numero de identificacion del servicio?" << endl;
					getline(cin, ID);
					stringstream mystream(ID);
					if(mystream >> z){
						if(z >= v1 && z <= v2) valido = true;
					}
        			if(!valido) cout << "error Solo 4 Digitos Y ningun Caracter" << endl;
			}while(!valido);
			valido= false;
			system("cls");
			cout << "cuantos Subservicios Habran" << endl;
			cin >> i;
			fflush(stdin);
			system("cls");
				for(k=0;k<i;k++){
					cout << "Cual es el Nombre del Subservicio?"<< endl;
					getline(cin, NSub[k]);
					do{
						cout << "Cual es el numero de identificacion del subservicio?"<<endl;
						getline(cin, IDSub[k]);
						stringstream mystream(IDSub[k]);
						if(mystream >> z){
							if(z >= v1 && z <= v2) valido = true;
						}
						if(!valido) cout << "error Solo 2 Digitos Y ningun Caracter" << endl;
					}while(!valido);
					while(true){
						cout << "Cual es el precio del subservicio?" << endl;
						getline(cin, PSub[k]);
						stringstream mystream(PSub[k]);
						if(mystream >> z) break;
					};
					system("cls");
				}
			cout << "Se agrego el Subservicio con exito...\n" << endl;
			cout << endl;
			system("Pause");
			system("cls");
			do{
				cout << "1.Guardar el Servicio Completo\n 2. Regresar" << endl;
				cin >> op2;
				fflush(stdin);
			}while(op2 < 1 || op2 >2);
			system("cls");
			if (op2 == 1);
			{
				cout << "ID " << "\t" << "Nombre del Servicio" << endl;
				cout << ID << "\t" << Nombre <<  endl;
				cout << "ID " << "Nombre del Subservicio" << "Precio    " << endl;
				for(k=0;k<i;k++){
					cout << IDSub[k] << "\t" << NSub[k] << "\t" << PSub[k] << endl;
				}
				archivo << endl;
				archivo << ID << "\t" << Nombre << "\n" << endl;
				for(k=0;k<i;k++){
					archivo << IDSub[k] << "\t" << NSub[k] << "\t" << "$" << PSub[k] << endl;
				}
				cout << "Se agrego el Servicio con Exito...\n";
				system("Pause");
				system("cls");

			}
			archivo.close();
		}
		
	} while (op1 != 2);
	menu();
}

string Consultar() {
	system("cls");
	cout << "Ha escogido la opcion de Consulta de servicios\n" << endl;
	/*ifstream archivo;
	string texto;
	archivo.open("Agregar.txt",ios::in);
	if (archivo.fail()) {
		cout << "no se pudo abrir el archivo" << endl;
		exit(1);
	}
	while (!archivo.eof()) {
		getline(archivo, texto);
		cout << texto << endl;
	}
	archivo.close();*/
	
	FILE *archivo;
	char caracter;
	
	archivo = fopen("Agregar.txt","r");
	
	if(archivo == NULL){
		cout << "Error en la apertura del archivo" << endl;
	}
	else {
		while((caracter = fgetc(archivo)) != EOF){
			printf("%c",caracter);
		}
	}
	fclose(archivo);
	system ("pause");
	menu();
}

string Eliminar() {
	system("cls");
	char Nombre[40], NSub[20];
	int ID, Bclave, Sclave, op1, IDSub, op2;
	cout << "Ha escogido la opcion de Eliminar Servicios" << endl;
	ifstream archivo;
	ofstream Temp;
	archivo.open("Agregar.txt", ios::app);
	Temp.open("Temp.txt");
	archivo >> Nombre;
	bool encontrado = false;
	cout << "ingrese el ID del servicio que desea eliminar" << endl;
	cin >> Bclave;
	system("cls");
	while (!archivo.eof()) {
		archivo >> ID;
		if (ID == Bclave); {
			encontrado = true;
			cout << "Nombre...." << Nombre << endl;
			cout << "ID..." << ID << endl;
			cout << endl;
			cout << "Eliminado" << endl;
		}
	}
	archivo >> Nombre;
	if (encontrado == false) {
		cout << "el ID no se encontro" << endl;
	}
	
	cout << "Presiona cualquier tecla para continuar" << endl;
	cin >> op2;
	fflush(stdin);
	system("cls");
	
	cout << "Tambien quiere eliminar subservicios?" << endl;
	cout << "1.Si\n2.No" << endl;
	cin >> op1;
	fflush(stdin);
	system("cls");
	if (op1 == 1) {
		archivo >> NSub;
		bool encontrado = false;
		cout << "Ingrese el numero de identificacion del subservicio que desea eliminar" << endl;
		cin >> Sclave;
		fflush(stdin);
		while (!archivo.eof()) {
			archivo >> IDSub;
			if (IDSub == Sclave); {
				encontrado = true;
				cout << "El Nombre del subservicio es..." << NSub << endl;
				cout << "El ID del subservicio es ..." << IDSub << endl;
				cout << endl << endl;
				cout << "Eliminado..." << endl;
			}
			archivo >> NSub;
			if (encontrado = false) {
				cout << "El ID no se encontro... " << endl;
			
			}
		}
	}
	
	archivo.close();
	Temp.close();
	remove("Agregar.txt");
	rename("Temp.txt", "Agregar.txt");
	system("cls");
	menu();
}

string Modificar() {
	system("cls");
	int ID, Bclave, IDSub, Sclave, op1, op2;
	char Nombre[40], NewN[40], NSub[20], NewS[20];
	float precio, P$, PSub, NP$;
	ifstream archivo;
	ofstream Temp;

	cout << "Ha escogido la opcion de Modificar Servicios" << endl;
	archivo.open("Agregar.txt", ios::app);
	Temp.open("Temp.txt");
	archivo >> Nombre;
	bool encontrado = false;
	cout << "Ingresar la ID del servicio para modificarlo" << endl;
	cin >> Bclave;
	fflush(stdin);

	while (archivo.eof()) {
		archivo >> ID;
		if (ID == Bclave); {
			encontrado = true;
			cout << "El nombre es..." << Nombre << endl;
			cout << "El ID es..." << ID << endl;
			cout << endl << endl;
			system("cls");
			cout << "Ingrese el nuevo nombre" << endl;
			cin >> NewN;
			fflush(stdin);
			 }
		Temp << NewN << "" << ID << endl;
		Temp << P$ << "" << ID << endl;
		cout << "Modificado" << endl;
	}

	archivo >> Nombre;
	if (encontrado = false) {
		cout << "El ID no fue encontrado" << endl;
	}
	cout << "Presiona cualquier tecla para continuar" << endl;
	cin >> op1;
	fflush(stdin);
	system("cls");

	cout << "Tambien quiere modificar los subservicios" << endl;
	cout << "1.Si\n2.No" << endl;
	cin >> op2;
	system("cls");
	if (op2 == 1) {
		archivo >> NSub;
		bool encontrado = false;
		cout << "Ingrese el ID del subservicio que quiere modificar" << endl;
		cin >> Sclave;
		fflush(stdin);
		cout << "Ingrese el precio del producto" << endl;
		cin >> PSub;
		fflush(stdin);
		cout << "Modificado..." << endl;
     }
	archivo >> NSub;
	if (encontrado = false) {
		cout << "El ID no se encontro" << endl;
	}

	archivo.close();
	Temp.close();
	remove("Agregar.txt");
	rename("Temp.txt", "Agregar.txt");
	system("pause");
	system("cls");
	menu();
}

string CrearNota() {
	system("cls");
	int ID, op3, op4, i, Bclave;
	char Nombre[40];
	float precio, Psuma;
	ifstream archivo;
	ofstream Temp2;
	Psuma = 0;

	do {
		cout << "Ha escogido la opcion de Crear Nota " << endl;
		cout << "1.Crear su Nota \n2. Regresar al Menu Principal" << endl;
		bool encontrado = false;
		cin >> op3;
		fflush(stdin);
		system("cls");

		if (op3 == 1) {
			archivo.open("Agregar.txt", ios::app);
			Temp2.open("Temp.txt");
			cout << "Ingrese la cantidad de Servicios que desea utilizar" << endl;
			cin >> op4;
			fflush(stdin);
			for (i = 1; i <= op4; i++);
			cout << "Ingrese el ID del  Servicio\n";
			cin >> ID;
			cout << "Ingrese el precio estimado del servicio" << endl;
			cin >> precio;
			fflush(stdin);
			while (archivo.eof()) {

				archivo >> Bclave;
				if (ID == Bclave) {
					encontrado = true;
					cout << "El nombre del Servicio es:" << Nombre << endl;
					cout << " El ID del servicio es:" << ID << endl;
					cout << " El Precio del servicio es" << precio << endl;
					for (i = 1; i <= op4; i++) {
						Psuma = Psuma + precio;
					}
					cout << "La nota fue creada con exito\n\n";
					system("cls");
					cout << "La Nota es:" << endl;
					cout << Nombre << ID << endl;
					cout << "El total es:" << Psuma << endl;
				}
				archivo >> Nombre;
				if (encontrado = false) {
					cout << "El ID no fue encontrado en el registro" << endl;
				}
				archivo.close();
				Temp2.close();
				remove("Agregar.txt");
				rename("Temp.txt", "Agregar.txt");
				system("Pause");
				system("cls");
			}
		}
	} while (op3 != 2);
	menu();
}

string ConsultarNota() {
	system("cls");
	cout << "Ha escogido la opcion de Consulta de Notas\n" << endl;
	ifstream Temp2;
	string texto;

	Temp2.open("Temp2.txt", ios::app);

	if (Temp2.fail()) {
		cout << "no se pudo abrir el archivo" << endl;
		exit(1);
	}
	while (!Temp2.eof()) {
		getline(Temp2, texto);
		cout << texto << endl;
	}
	Temp2.close();
	menu();
}

int main(){
	system("cls");
	menu();
	return 0;
}

int menu() {
	system("cls");
	int op;
	do {
	
	
	cout << "Bienvenido a la Lavanderia\n" << endl;
	cout << "Seleccione la opcion que desea" << endl;
	cout << "1.Consulta de Servicios" << endl;
	cout << "2.Agregar Servicos" << endl;
	cout << "3.Modificar Servicios" << endl;
	cout << "4.Eliminar Servicios" << endl;
	cout << "5.Crear Nota" << endl;
	cout << "6.Consultar Notas" << endl;
	cout << "7.Salir del sistema" << endl;
	cin >> op;
	fflush(stdin);
	system("cls");


	
		switch (op) {
		case 1:
			Consultar();
			break;
		case 2:
			Agregar();
			break;
		case 3:
			Modificar();
			break;
		case 4:
			Eliminar();
			break;
		case 5:
			CrearNota();
			break;
		case 6:
			ConsultarNota();
			break;
		case 7:
			cout << "Ha escogido la opcion de Salir del Sistema" << endl;
			break;
		}
	} while (op != 7);
	return 0;
}
