// Hannia Edith Martinez Adame
// 1961244
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
struct cita {
	int numcita;
	string nombre;
	string hora;
	string tratamiento;
	string descripcion;
	int unitario;
	int cantidad;
	int total;
	cita* anterior = nullptr;
	cita* siguiente =nullptr;
};
int cita_actual = 0;
cita* primera_cita = nullptr;
cita* ultima_cita = nullptr;
cita* auxiliar = nullptr;
void registrar_cita(int numcita) {
	cita* nueva_cita = new cita;
	cita_actual++;
	int t = 1;
	nueva_cita->numcita = cita_actual;
	system("cls");
	cout << "Introduzca su nombre completo" << endl;
	cin.ignore();
	getline(cin, nueva_cita->nombre);
	system("cls");
	cout << "Introduzca la hora de la cita en formato 24 horas. (Ejemplo: 13:35)" << endl;
	cin >> nueva_cita->hora;
	p:
	system("cls");
	cout << "Elija el tratamiento deseado." << endl << endl;
	cout << "Tratamiento #1:" << endl << "Nombre: Diagnostico y Prevencion." << endl << "Descripcion: Examinar su dentadura para descubrir si se sufre de algun problema aun no detectado y dar una limpieza dental." << endl << "Precio Unitario: $100" << endl << endl;
	cout << "Tratamiento #2:" << endl << "Nombre: Ortodoncia." << endl << "Descripcion: Se utiliza para corregir la mordedura deficiente u oclusion dental defectuosa (cuando los dientes están amontonados o torcidos)." << endl << "Precio Unitario: $525" << endl << endl;
	cout << "Tratamiento #3:" << endl << "Nombre: Estetica Dental." << endl << "Descripcion: Se ocupa de problemas relacionados con la armonia bucal, marcandose el objetivo de conseguir la sonrisa perfecta." << endl << "Precio Unitario: $1645" << endl << endl;
	cout << "Tratamiento #4:" << endl << "Nombre: Estraccion." << endl << "Descripcion: Quitar un diente, por lo general a causa de alguna enfermedad o traumatismo o porque hay dientes amontonados." << endl << "Precio Unitario: $750" << endl << endl;
	cin >> t;
	switch (t) {
	case 1:
		nueva_cita->tratamiento = "Diagnostico y Prevencion";
		nueva_cita->descripcion = "Examinar su dentadura para descubrir si se sufre de algun problema aun no detectado y dar una limpieza dental.";
		nueva_cita->unitario = 10;
		break;
	case 2:
		nueva_cita->tratamiento = "Ortodoncia";
		nueva_cita->descripcion = "Se utiliza para corregir la mordedura deficiente u oclusion dental defectuosa (cuando los dientes están amontonados o torcidos)";
		nueva_cita->unitario = 525;
		break;
	case 3:
		nueva_cita->tratamiento = "Estetica Dental";
		nueva_cita->descripcion = "Se ocupa de problemas relacionados con la armonia bucal, marcandose el objetivo de conseguir la sonrisa perfecta.";
		nueva_cita->unitario = 1645;
		break;
	case 4:
		nueva_cita->tratamiento = "Estraccion";
		nueva_cita->descripcion = "Quitar un diente, por lo general a causa de alguna enfermedad o traumatismo o porque hay dientes amontonados.";
		nueva_cita->unitario = 750;
		break;
	defautl:
		system("cls");
		cout << "Introduzca una opcion valida";
		system("pause");
		goto p;
	}
	system("cls");
	cout << "Introduzca cantidad de tratamiento " << endl;
	cin >> nueva_cita->cantidad;
	nueva_cita->total = nueva_cita->unitario * nueva_cita->cantidad;
	system("cls");
	if (cita_actual == 1) {
		primera_cita = nueva_cita;
		ultima_cita = nueva_cita;
	}
	else {
		nueva_cita->anterior = ultima_cita;
		ultima_cita->siguiente = nueva_cita;
		ultima_cita = nueva_cita;
	}
	cout << "Cita agendada" << endl;
	system("pause");
}
void imprimir_citas() {
	auxiliar = primera_cita;
	if (!auxiliar) {
		system("cls");
		cout << "No hay citas registradas";
	}
	else {
		int j = 0;
		while (auxiliar) {
			j++;
			cout << "Cita # " << j << endl;
			cout << "Nombre: " << auxiliar->nombre << endl;
			cout << "Hora: " << auxiliar->hora << endl;
			cout << "Nombre del tratamiento: " << auxiliar->tratamiento << endl;
			cout << "Descripcion: " << auxiliar->descripcion << endl;
			cout << "Precio Unitario: " <<"$" << auxiliar->unitario << endl;
			cout << "Cantidad pedido: " << auxiliar->cantidad << endl;
			cout << "Total a pagar: " <<"$" << auxiliar->total << endl;
			cout << endl;
			system("pause");
			auxiliar = auxiliar->siguiente;
		}
	}
}
void guardar_citas() {
	ofstream archivo;
	archivo.open("CitasGuardadas.txt");
		if (archivo.is_open()) {
			auxiliar = primera_cita;
			while (auxiliar) {
				archivo << auxiliar->numcita << endl;
				archivo << auxiliar->nombre << endl;
				archivo << auxiliar->hora << endl;
				archivo << auxiliar->tratamiento << endl;
				archivo << auxiliar->descripcion << endl;
				archivo << auxiliar->unitario << endl;
				archivo << auxiliar->cantidad << endl;
				archivo << auxiliar->total << endl;
				archivo << endl;
				auxiliar = auxiliar->siguiente;
			}
			archivo.close();
		}
		else {
			cout << "No sé pudo crear el archivo" << endl;
		}
}
void leer_citas() {
	ifstream escritura;
	int liena;
	escritura.open("CitasGuardadas.txt", ios::in);
	if (escritura.is_open()) {
		while (!escritura.eof()) {
		
		}
	}
	else {
		system("cls");
		cout << "No existe el archivo" << endl;
	}
}
void modificar() {
	system("cls");
	int q = 0;
	cout << endl << endl << "Elija el numero de la cita que quiera modificar" << endl;
	cin >> q;
	auxiliar = primera_cita;
	while (auxiliar->numcita < q) {
		auxiliar = auxiliar->siguiente;
	}
	system("cls");
	cout << "Introduzca su nombre completo" << endl;
	cin.ignore();
	getline(cin, auxiliar->nombre);
	system("cls");
	cout << "Introduzca la hora de la cita en formato 24 horas. (Ejemplo: 13:35)" << endl;
	cin >> auxiliar->hora;
p:
	system("cls");
	int t = 0;
	cout << "Elija el tratamiento deseado." << endl << endl;
	cout << "Tratamiento #1:" << endl << "Nombre: Diagnostico y Prevencion." << endl << "Descripcion: Examinar su dentadura para descubrir si se sufre de algun problema aun no detectado y dar una limpieza dental." << endl << "Precio Unitario: $100" << endl << endl;
	cout << "Tratamiento #2:" << endl << "Nombre: Ortodoncia." << endl << "Descripcion: Se utiliza para corregir la mordedura deficiente u oclusion dental defectuosa (cuando los dientes están amontonados o torcidos)." << endl << "Precio Unitario: $525" << endl << endl;
	cout << "Tratamiento #3:" << endl << "Nombre: Estetica Dental." << endl << "Descripcion: Se ocupa de problemas relacionados con la armonia bucal, marcandose el objetivo de conseguir la sonrisa perfecta." << endl << "Precio Unitario: $1645" << endl << endl;
	cout << "Tratamiento #4:" << endl << "Nombre: Estraccion." << endl << "Descripcion: Quitar un diente, por lo general a causa de alguna enfermedad o traumatismo o porque hay dientes amontonados." << endl << "Precio Unitario: $750" << endl << endl;
	cin >> t;
	switch (t) {
	case 1:
		auxiliar->tratamiento = "Diagnostico y Prevencion";
		auxiliar->descripcion = "Examinar su dentadura para descubrir si se sufre de algun problema aun no detectado y dar una limpieza dental.";
		auxiliar->unitario = 10;
		break;
	case 2:
		auxiliar->tratamiento = "Ortodoncia";
		auxiliar->descripcion = "Se utiliza para corregir la mordedura deficiente u oclusion dental defectuosa (cuando los dientes están amontonados o torcidos)";
		auxiliar->unitario = 525;
		break;
	case 3:
		auxiliar->tratamiento = "Estetica Dental";
		auxiliar->descripcion = "Se ocupa de problemas relacionados con la armonia bucal, marcandose el objetivo de conseguir la sonrisa perfecta.";
		auxiliar->unitario = 1645;
		break;
	case 4:
		auxiliar->tratamiento = "Estraccion";
		auxiliar->descripcion = "Quitar un diente, por lo general a causa de alguna enfermedad o traumatismo o porque hay dientes amontonados.";
		auxiliar->unitario = 750;
		break;
	defautl:
		system("cls");
		cout << "Introduzca una opcion valida";
		goto p;
	}
	system("cls");
	cout << "Introduzca cantidad de tratamiento " << endl;
	cin >> auxiliar->cantidad;
	auxiliar->total = auxiliar->unitario * auxiliar->cantidad;
}
void eliminar() {
	system("cls");
	int q = 0;
	i:
	cout << endl << endl << "Elija el numero de la cita que quiera eliminar" << endl;
	cin >> q;
	auxiliar = primera_cita;
	if (q>ultima_cita->numcita)
	{
	system("cls");
	cout << "La cita introducida no existe" << endl;
	system("pause");
	goto i;
	}
	while (auxiliar->numcita < q) {
		auxiliar = auxiliar->siguiente;
	}
	if (auxiliar->numcita = 1) {
		primera_cita = primera_cita->siguiente;
	}
	else if (auxiliar == ultima_cita) {
		ultima_cita->anterior = ultima_cita;
	} 
	else {
		auxiliar = auxiliar->siguiente;
	}
	system("cls");
}
int main() {
	int r = 0;
e:
	system("cls");
	cout << "Bienvenido" << endl << "Elija la opcion deseada";
	cout << endl << "1. Agendar cita.";
	cout << endl << "2. Modificar cita.";
	cout << endl << "3. Eliminar cita.";
	cout << endl << "4. Lista de citas vigentes.";
	cout << endl << "5. Salir." << endl;
	cin >> r;
	system("cls");
	switch (r) {
	case 1:
		registrar_cita(0);
		guardar_citas();
		goto e;
		break;
	case 2:
		system("cls");
		cout << "Se mostraran las citas para que vea cual se quiere modificar" << endl << endl;
		system("pause");
		system("cls");
		imprimir_citas();
		modificar();
		goto e;
		break;
	case 3:
		system("cls");
		cout << "Se mostraran las citas para que vea cual se quiere eliminar" << endl << endl;
		system("pause");
		imprimir_citas();
		system("cls");
		eliminar();
		goto e;
		break;
	case 4:
		imprimir_citas();
		goto e;
		break;
	case 5:
		exit(0);
		break;
	defautl:
		system("cls");
		cout << "Introduzca una respuesta valida" << endl;
		system("pause");
		goto e;
	}

}
