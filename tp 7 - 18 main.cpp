#include <fstream>
#include "Arbol.h"
#include <iostream>
#include <stdlib.h>
#include <vector>




using namespace std;
	
	int main() {					//DECLARACION DE ARBOLES
	Arbol a = Arbol();
	Nodo *arbol = nullptr;
	int dato, opcion, contador = 0;
	
	a.insertarNodo(arbol, 2, nullptr);
	a.insertarNodo(arbol, 4, nullptr);
	a.insertarNodo(arbol, 4, nullptr);
	a.insertarNodo(arbol, 4, nullptr);
	a.insertarNodo(arbol, 3, nullptr);
	
	do {						//MENU DE OPCIONES
	
	<< endl;
	cout << "1-Agregar nuevo nodo" << endl;
	cout << "2-Mostrar arbol completo" << endl;
	cout << "ejercicio 13" << endl;
	cout << "3- El peso.\n"
	"4- El número de hojas.\n"
	"5- El número de veces que aparece un elemento dado.\n"
	"6-  El número de elementos que tiene el árbol en un nivel dado.\n"
	"7- La altura." << endl;
	cout << "ejercicio 14" << endl;
	cout << "8. La suma de sus elementos.\n"
	"9. La suma de sus elementos que son múltiplos de 3." << endl;
	cout << "ejercicio 18" << endl;
	cout << "10. Mostrar arbol en preorden.\n"
	"11- Mostrar arbol en inorden.\n"
	"12- Mostrar arbol en postorden.\n"
	"13- Mostrar arbol por niveles.\n"
	"14- Médoto que guarde árbol en disco.\n"
	"15- Método que recupere el árbol del disco.\n"
	"0- Abnadonar" << endl;
	<< endl;
	cout << "Seleccionar alguna opción: ";
	cin >> opcion;
	
	switch (opcion) {							//INGRESAR CASOS
	case 1:
	cout << "Ingrese  un número: ";
	cin >> dato;
	a.insertarNodo(arbol, dato, nullptr);
	cout << "\n";
	break;
	case 2:
	cout << "Árbol completo (acostado): \n";
	a.mostrarArbol(arbol, contador);
	cout << "\n";
	break;
	case 3: {
	cout << "Peso de Árbol (cantidad de nodos): " << a.peso(arbol);
	cout << "\n";
	}
	break;
	case 4:
	cout << "Numero de Hojas: " << a.contarHojas(arbol);
	cout << "\n";
	break;
	case 5:
	int num;
	cout << "Numero a encontrar: ";
	cin >> num;
	a.contarNumero(arbol, num);
	break;
	case 6: {
	int nivel;
	cout << "Seleccionar nivel: ";
	cin >> nivel;
	a.nivelDado(arbol, 1, nivel);
	cout << "" << endl;
	}
	break;
	case 7:
	cout << "Altura del Arbol: " << a.altura(arbol) << endl;
	break;
	case 8:
	cout << "Suma de elementos : " << a.sumarElementos(arbol) << endl;
	break;
	case 9:
	cout << "Suma de elementos Mutiplos de 3 : " << a.sumarElementosMultiplosTres(arbol) << endl;
	break;
	case 10:
	cout << "Recorrido en pre-orden:\n";
	a.preOrden(arbol);
	cout << "\n";
	break;
	case 11:
	cout << "Recorrido en in-orden:\n";
	a.inOrden(arbol);
	cout << "\n";
	break;
	case 12:
	cout << "Recorrido en pre-orden:\n";
	a.postOrden(arbol);
	cout << "\n";
	break;
	case 13:
	cout << "Arbol por niveles:\n";
	a.printLevelOrder(arbol);
	cout << "\n";
	break;
	case 14:
	cout << "Arbol almacenado en data.txt\n";
	a.guardarArbol(arbol,0,true);
	break;
	case 15:
	cout << "Arbol almacenado de data.txt\n";
	a.traerArbol();
	break;
	}
	
	} while (opcion >= 1 && opcion <= 15);
	return 0;
	}
