// Created by tomas,carlos on 12/09/18.
//Ejercicio Practica 
//Integrantes: Agustin Carro, Carlos Rodriguez, Diego Monti, Tomas Pistarelli



#ifndef ARBOLES_ARBOL_H
#define ARBOLES_ARBOL_H
#include <vector>
#include "queue.h"
#include <iostream>
using namespace std;
			
		//DECLARACION DE DATOS 
 
	

	struct Nodo {
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
	};
	
	
	class Arbol {						//ASIGNAMOS PARAMETROS A LAS FUNCIONES
	
	public:
	Arbol();
	
	Nodo *crearNodo(int, Nodo *);
	
	void insertarNodo(Nodo *&, int, Nodo *);
	
	void mostrarArbol(Nodo *, int);
	
	bool busqueda(Nodo *, int);
	
	Nodo *minimo(Nodo *);
	
	void destruirNodo(Nodo *);
	
	void reemplazar(Nodo *, Nodo *);
	
	void eliminarNodo(Nodo *);
	
	void eliminar(Nodo *, int );
	
	void vectorizar(Nodo *, vector <int> &);
	
	void contarNumero(Nodo *, int );
	
	int sumarElementos(Nodo * );
	
	int altura(Nodo*);
	
	int peso(Nodo *);
	
	void nivelDado(Nodo* , int , int);
	
	int contarHojas(struct Nodo* );
	
	int sumarElementosMultiplosTres(Nodo * );
	
	void preOrden(Nodo *);
	
	void inOrden(Nodo *);
	
	void postOrden(Nodo *);
	
	void printLevelOrder(struct Nodo*);
	
	void printGivenLevel(struct Nodo*, int);
	
	void guardarArbol( Nodo *, int, bool);
	
	void traerArbol();
	
	};
	
	#endif //ARBOLES_ARBOL_H
