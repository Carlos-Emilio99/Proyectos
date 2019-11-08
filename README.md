# Proyectos
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

struct datos {
	int ID, Bclave;
	char Nombre[40], NSub[20];
	float precio;
	ofstream Temp;
};
typedef struct datos DATO;

string Agregar() {
	ofstream archivo("Agregar.txt");
	string Nombre,NSub,IDSub, ID, Precio, PSub;
	int  op1, op2, ops1;


	do {
		cout << "Ha escogido la opcion de Agregar Servicios" << endl;
		cout << "1.Agregar Servicios\n2.Regresar al Menu Principal " << endl;
		cin >> op1;
		fflush(stdin);
		
		if (op1 == 1)
		{
			if (!archivo.is_open())
			{
				archivo.open("Agregar.txt", ios::out);
			}
			cout << "Cual es el nombre del Servicio?" << endl;
			cin >> Nombre;
			fflush(stdin);
			cout << "Cual es el numero de identificacion del servicio?" << endl;
			cin >> ID;
			fflush(stdin);
			/*cout << "Cual es el precio del Servicio?" << endl;
			getline(cin, Precio);
			cout << endl;
			system("cls");*/
			cout << "Desea Agregar Tambien Subservicios" << endl;
			cout << "1.Si\n2.No" << endl;
			cin >> ops1;
			fflush(stdin);

			if (ops1 == 1);
			{
				cout << "Cual es el Nombre del Subservicio?"<< endl;
				getline(cin, NSub);
				cout << "Cual es el numero de identificacion del subservicio?"<<endl;
				getline(cin, IDSub);
				cout << "Cual es el precio del subservicio?" << endl;
				getline(cin, PSub);
				cout << endl;
				cout << "Se agrego el Subservicio con exito...\n" << endl;
				system("Pause");
				system("cls");
			}
			
			cout << "1.Guardar el Servicio Completo\n 2. Regresar" << endl;
			cin >> op2;
			fflush(stdin);

			if (op2 == 1);
			{
				cout << "ID " << "Nombre del Servicio" << "Precio          " << endl;
				cout << ID << Nombre << Precio << endl;
				cout << "ID " << "Nombre del Subservicio" << "Precio    " << endl;
				cout << IDSub << "\n\n\n\n" << NSub << "\n\n" << PSub << endl;
				cout << "Se agrego el Servicio con Exito...\n";
				system("Pause");
				system("cls");

			}
			archivo.close();
		}
		
	} while (op1 != 2);
}

string Consultar() {
	cout << "Ha escogido la opcion de Consulta de servicios\n" << endl;
	ifstream archivo;
	string texto;

	archivo.open("Agregar.txt", ios::app);

	if (archivo.fail()) {
		cout << "no se pudo abrir el archivo" << endl;
		exit(1);
	}
	while (!archivo.eof()) {
		getline(archivo, texto);
		cout << texto << endl;
	}
	archivo.close();
	return 0;
}

string Eliminar() {
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
	return 0;
}

string Modificar() {
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
	cout << "Ingrese el precio del servicio" << endl;
	cin >> precio;
	fflush(stdin);

	while (archivo.eof()) {
		archivo >> ID;
		if (ID == Bclave); {
			encontrado = true;
			cout << "El nombre es..." << Nombre << endl;
			cout << "El ID es..." << ID << endl;
			cout << "El precio es ..." << precio << endl;
			cout << endl << endl;
			system("cls");
			cout << "Ingrese el nuevo nombre" << endl;
			cin >> NewN;
			fflush(stdin);
			cout << "Ingrese el nuevo precio" << endl;
			cin >> P$; }
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
	return 0;
}

string CrearNota() {
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
	return 0;
}

string ConsultarNota() {
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
	return 0;
}





int main() {
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

