#include "Arbol.h"
#include "queue.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
	
	
	
	
	void Arbol::insertarNodo (Nodo *&arbol, int n, Nodo *padre) { //creamos un nuevo nodo
	if (arbol == nullptr) {
	Nodo *nuevo_nodo = crearNodo(n, padre);
	arbol = nuevo_nodo;
	}
	else {
	int valorRaiz = arbol->dato;
	if (n < valorRaiz) {
	insertarNodo(arbol->izq, n, arbol);
	}
	else {
	insertarNodo(arbol->der, n, arbol);
	}
	}
	}
	
	Arbol::Arbol(){};					//creamos un arbol
	
	Nodo * Arbol::crearNodo (int n, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = nullptr;
	nuevo_nodo->izq = nullptr;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
	}
	
	void Arbol::mostrarArbol (Nodo *arbol, int cont) { //creamo una funcion para mostrar dicho arbol
	if (arbol == nullptr) {	
	return;
	}
	else {
	mostrarArbol(arbol->der, cont + 1);
	for (int i = 0; i<cont; i++) {
	cout << " ";
	}
	cout << arbol->dato << endl;
	mostrarArbol(arbol->izq, cont + 1);
	}
	}
	
	
	
	Nodo *Arbol::minimo(Nodo *arbol){    //creamos una funcion para el minimo
	if(arbol == nullptr){
	return nullptr;
	}
	if (arbol->izq){
	return minimo(arbol->izq);
	}
	else{
	return arbol;
	}
	}
	


	
	bool Arbol::busqueda (Nodo *arbol, int n) { //creamos una funcion para la busqueda en el arbol
	if (arbol == nullptr) {
	return false;
	} else if (arbol->dato == n) {
	return true;
	} else if (n < arbol->dato) {
	return busqueda(arbol->izq, n);
	} else {
	return busqueda(arbol->der, n);
	}
	}
	

	void Arbol::destruirNodo(Nodo *nodo){ // funcion para borrado
	nodo->izq = nullptr;
	nodo->der = nullptr;
	
	delete nodo;
	}
	
	void Arbol::reemplazar (Nodo *arbol, Nodo *nuevoNodo){ //fuincio de reemplazo (update)
	if(arbol->padre){
	//arbol→padre hay que asignarle su nuevo hijo
	if(arbol->dato == arbol->padre->izq->dato){
	arbol->padre->izq = nuevoNodo;
	}
	else if(arbol->dato == arbol->padre->der->dato){
	arbol->padre->der = nuevoNodo;
	}
	}
	if(nuevoNodo){				//agregar nuevo nodo
	//Asignamos su nuevo padre
	nuevoNodo->padre = arbol->padre;
	}
	}
	
	
	//eliminar el nodo encontrado (si es hoja, o tiene hijos)
	void Arbol::eliminarNodo (Nodo *nodoEliminar) {
	if (nodoEliminar->izq && nodoEliminar->der) { //nodo tiene hijo izquierdo y derecho?
	Nodo *menor = minimo(nodoEliminar->der);
	nodoEliminar->dato = menor->dato;
	eliminarNodo(menor);
	} else if (nodoEliminar->izq) {
	reemplazar(nodoEliminar, nodoEliminar->izq);
	destruirNodo(nodoEliminar);
	} else if (nodoEliminar->der) {
	reemplazar(nodoEliminar, nodoEliminar->der);
	destruirNodo(nodoEliminar);
	} else {
	reemplazar(nodoEliminar, nullptr);
	destruirNodo(nodoEliminar);
	}
	}
	
	void Arbol::eliminar(Nodo *arbol, int n) {
	if (arbol == nullptr) {
	return;
	} else if (n < arbol->dato) {
	eliminar(arbol->izq, n);
	} else if (n > arbol->dato) {
	eliminar(arbol->der, n);
	} else {
	eliminarNodo(arbol);
	}
	}
	
	void Arbol::vectorizar(Nodo *arbol, vector <int> &lista) {
	if (arbol != nullptr) {
	lista.push_back(arbol->dato);
	vectorizar(arbol->izq, lista);
	vectorizar(arbol->der, lista);
	
	}
	}
	
	void Arbol::contarNumero(Nodo *arbol, int n){
	vector <int> lista;
	vectorizar(arbol, lista);
	int cont = 0;
	for (int i=0 ; i<lista.size(); i++){
	if (n == lista[i]){
	cont++;
	}
	}
	cout<<cont<<endl;
	}
	
	int Arbol::sumarElementos(Nodo *arbol){
	vector <int> lista;
	vectorizar(arbol, lista);
	int sum = 0;
	for (int i=0 ; i<lista.size(); i++){
	sum+= lista[i];
	}
	return sum;
	}
	
	int Arbol::sumarElementosMultiplosTres(Nodo *arbol){
	vector <int> lista;
	vectorizar(arbol, lista);
	int sum = 0;
	for (int i=0 ; i<lista.size(); i++){
	if(lista[i]%3==0){
	sum+= lista[i];
	}
	}
	return sum;
	}
	
	int Arbol::peso (Nodo *arbol) { 			//Devuelve el peso del arbol
	if(!arbol)
	return 0;
	else
	return peso(arbol->izq) + 1 + peso(arbol->der);
	}
	
	int Arbol::contarHojas(struct Nodo* node) {		//numero de hojas
	if(node == NULL)
	return 0;
	if(node->izq == NULL && node->der==NULL)
	return 1;
	else
	return contarHojas(node->izq)+
	contarHojas(node->der);
	}
	
	void Arbol::nivelDado(Nodo* node, int clevel, int rlevel) {
	if (clevel == rlevel) {
	cout << node->dato << endl;
	}
	else {
	if (node->izq != NULL)
	nivelDado(node->izq, clevel + 1, rlevel);
	if (node->der != NULL)
	nivelDado(node->der, clevel + 1, rlevel);
	}
	}
	
	void Arbol:: preOrden(Nodo* node) {		//preorden	
	if ( node ) {
	cout << node->dato << " ";
	preOrden(node->izq);
	preOrden(node->der);
	}
	}
	
	void Arbol:: inOrden(Nodo* Root) {     		//inorden
	if(Root != NULL) {
	inOrden(Root->izq);
	cout << Root->dato << " ";
	inOrden(Root->der);
	}
	}
	
	void Arbol:: postOrden(Nodo* Root) {		//portorden
	if(Root != NULL) {
	postOrden(Root->izq);
	postOrden(Root->der);
	cout << Root->dato << " ";
	
	}
	}
	
	
	void Arbol::printGivenLevel(struct Nodo* root, int level) { 
	if (root == NULL)
	return;
	if (level == 1)
	printf("%d ", root->dato);
	else if (level > 1) {
	printGivenLevel(root->izq, level-1);
	printGivenLevel(root->der, level-1);
	}
	}
	
	int Arbol::altura(Nodo* arbol) {					//altura de arbol
	if (arbol == nullptr) return 0;
	return max(altura(arbol->izq), altura(arbol->der)) + 1;
	}
	
	
	void Arbol::printLevelOrder(struct Nodo* root) {
	int h = altura(root);
	int i;
	for (i=1; i<=h; i++) {
	printGivenLevel(root, i);
	printf("\n");
	}
	}
	
	ofstream outputfile;
	void Arbol::guardarArbol( Nodo * arbol , int cont, bool ban){
	if(ban==true) {
	outputfile.open("data.txt");
	outputfile << "ARBOL:" << endl;
	}
	if (arbol == nullptr) {
	return;
	}
	else {
	guardarArbol(arbol->der, cont + 1, false);
	for (int i = 0; i<cont; i++) {
	outputfile << " ";
	}
	outputfile << arbol->dato << endl;
	guardarArbol(arbol->izq, cont + 1, false);
	}
	}
	
	
	
	
	void Arbol::traerArbol() {
	string line;
	ifstream myfile("data.txt");
	if (myfile.is_open()) {
	while (!myfile.eof()) {
	getline(myfile, line);
	cout << line << endl;
	}
	myfile.close();
	}
	else cout << "Archivo no encontrado";
	
	} 
