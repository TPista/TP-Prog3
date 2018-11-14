// Created by pista on 17/10/18.
//Ejercicio Practica 6 - 3
//Integrantes: Agustin Carro, Carlos Rodriguez, Diego Monti, Tomas Pistarelli

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


using namespace std;

struct ListNode { //Creacion de lista de datos
    int nlinea, ninterno, cantasientos;
    ListNode *next;
};

void LinkedList::deleteList(ListNode *front) { //Metodo borrar lis
    ListNode *next;
    for (ListNode *ptr = front; ptr != nullptr; ptr = next) {
        next = ptr->next;
        delete ptr;
    }
}




void removeIndex(ListNode *&front, int index) { //Borrar los indices basura

    if (front == nullptr) {

        return;

    }

    if (index == 0) {

        ListNode *trash = front;

        front = front->next;

        delete trash;

    } else {

        ListNode *tmp = front;

        for (int i = 0; i < index - 1; i++) {

            tmp = tmp->next;

            if (tmp == nullptr) {

                return;

            }

        }

        ListNode *trash = tmp->next;

        tmp->next = tmp->next->next;

        delete trash;

    }

}




void printList(ListNode *front) { //Metodo para mostrar la lista

    for (ListNode *ptr = front; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->nlinea <<endl;
        cout << ptr->ninterno << endl;
        cout << ptr->cantasientos << endl;
    }

}



void addToFront(int elem1,int elem2,int elem3, ListNode* &front) { //Ordenar los elementos
    front = new ListNode{elem1,elem2,elem3, front};

    }



int main () { // funcion principal 

    ListNode* front;


    int nlinea, ninterno, cantasientos; //declaracion numeros e inicio
    int fd;
    int inicio=0;
    int opcion;


    fd = open("archivo.txt", O_CREAT | O_WRONLY); //Creacion y posterior verificacion de archivo


    if (fd == NULL){
        printf("No se pudo crear el archivo");
    }
    else {
        cout<<("Se creo el archivo")<<endl;
          //  write(fd, "HOLA ", 13);
          close(fd);
    }
   
    addToFront(1, 1, 50, front);
    addToFront(1, 2, 45, front);


    while (!inicio){ //Menu seleccion de funciones

        cout<<("1. Agregar bondi")<<endl;
        cout<<("2. Mostrar bondi")<<endl;

        scanf("%d", &opcion);

        switch (opcion){

            case 1: {
                printf("Ingrese numero de linea: ");
                scanf("%d", &nlinea);

                printf("I2ngrese numero de interno: ");
                scanf("%d", &ninterno);

                printf("Ingrese numero de asientos: ");
                scanf("%d", &cantasientos);

                addToFront(nlinea, ninterno, cantasientos, front);
                break;
            }
          case 2: {
              printList(front);
              break;
          }
        }
    }

}
