#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string.h>
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
void actualizar();

string Agregar() {
	ofstream archivo("Agregar.txt",ios::app);
	ofstream main("Servicio.txt",ios::app);
	ofstream Smain("Subservicio.txt",ios::app);
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
							if(z >= v3 && z <= v4) valido = true;
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
			if (op2 == 1)
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
				main << endl;
				main << ID << "," << Nombre << "\n" << endl;
				for(k=0;k<i;k++){
					Smain << endl;
					Smain << ID << "," << IDSub[k] << "," << NSub[k] << "," << "$" << PSub[k] << endl;
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

string Eliminar() {/////////////////////////////////////////////////////////////////////////////////////7
	
}

string Modificar(){
	int ops1,ops2,ID,SubID,precio,strAsInt;;
	system("cls");
	cout << " por razones de sentido programacional editar un servicio ha sido desabilitado"<< endl;
	do{
		cout << " elige la ID que rige al SubServicio a Modificar"<<endl;
		cin >> ops1;
		fflush(stdin);
		if(ops1<1000 || ops1>9999)
			cout << " La ID que rige es de 4 digitos ";
	}while(ops1<1000 || ops1>9999);
	fstream archivo ("Subservicio.txt",ios::in|ios::out);
	while(!archivo.eof()){
		string s[4];
		string line,Name;
		int pos = archivo.tellg();
		getline (archivo , line);
		if (line.length()>0){
			stringstream sline(line);
			for(int i=0;i<4;i++){
				getline(sline,s[i],',');
				if(i=0){
					sline>>strAsInt;
				}
			}
			if(strAsInt==ops1){
				archivo.seekp(pos);
				cout <<"Elige que opcion quieres modificar \n[1]-ID del servicio \n[2]-SubID\n[3]-Nombre\n[4]-precio"<<endl;
				cin >>ops2;
				fflush(stdin);
				switch(ops2){
					case 1:{
						do{
							cout << "escribe por que quieres cambiar el ID del servicio"<<endl;
							cin >> ID;
							fflush(stdin);
							if(ID<1000 || ID>9999)
								cout << " La ID que rige es de 4 digitos ";
						}while (ID<1000 || ID>9999);
						archivo << ID <<",";
						archivo <<s[1]<<","<<s[2]<<","<<s[3];
						break;
					}
					case 2:{
						do{
							cout << "escribe por que quieres cambiar el SubID"<<endl;
							cin >> SubID;
							fflush(stdin);
							if(SubID<01 || SubID>99)
								cout << " el SUBID se rige es de 2 digitos ";
						}while(SubID<01 || SubID>99);
						archivo << s[0]<<",";
						archivo <<SubID<<",";
						archivo <<s[2]<<","<<s[3];
						break;
					}
					case 3:{
						cout << "escribe por que quieres cambiar el nombre"<<endl;
						cin >> Name;
						fflush(stdin);
						archivo << s[0]<<","<<s[1]<<",";
						archivo <<Name<<",";
						archivo <<s[3];
						break;
					}
					case 4:{
						do{
							cout << "escribe por que quieres cambiar el precio"<<endl;
							cin >> precio;
							fflush(stdin);
							if(precio<0)
								cout << " el precio siempre tiene que ser entero "<<endl;
						}while(precio<01 || precio>99);
						archivo << s[0]<<","<<s[1]<<","<<s[3]<<",";
						archivo <<precio;
						break;
					}
				}
			}
			pos=archivo.tellg();
		}
	}
	archivo.close();
	system("cls");
	menu();
}

string CrearNota() {
	system("cls");
	int i,ops1,ops2,ops3,strAsInt,strAsInt2,ops4;
	ofstream temp("ticket.txt",ios::out);
	cout << " acabas de Ingresar a la Seccion de Crear Nota "<<endl;
	do{
		
	do{
		cout << "Ingresa la ID del Servicio a Usar"<<endl;
		cin >> ops1;
		fflush(stdin);
		cout <<"ingresa el SUBID a Usar"<<endl;
		cin >> ops2;
		fflush(stdin);
		cout << " Usaras la ID "<<ops1 << "y la SubID "<< ops2<<endl;
		cout << "es correcto? [1]-si	/	[2]-no"<<endl;
		cin >> ops3;
		fflush(stdin);
	}while(ops3==2);
	fstream archivo("Servicio.txt",ios::in);
	while(!archivo.eof()){
		string s[4];
		string line;
		int pos = archivo.tellg();
		if(line.length()>0){
			stringstream sline(line);
			for(i=0;i<4;i++){
				getline(sline,s[i],',');
				if(i==0)
					sline>>strAsInt;
				if(i==1)
					sline>>strAsInt2;
			}
			if(strAsInt==ops1 && strAsInt2==ops2){
				cout << "|"<<s[i];
				temp << s[0] << "," << s[1] << "," << s[2] << "," << s[3];
			}
		}
	}
	archivo.close();
	cout <<"quieres ingresar mas servicios y subservicios a utilizar?\n[1]-si\n[2]-no"<<endl;
	cin >>ops4;
}while(ops4==2);
	temp.close();
	menu();
}

string ConsultarNota() {
	system("cls");
	cout << "Ha escogido la opcion de Consulta de Notas\n" << endl;
	
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
