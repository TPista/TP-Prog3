//
// Created by pista on 17/10/18.
//

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


using namespace std;

struct ListNode {
    int nlinea, ninterno, cantasientos;
    ListNode *next;
};



void printList(ListNode *front) {

    for (ListNode *ptr = front; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->nlinea << " ";
    }

}



void addToFront(int elem1,int elem2,int elem3, ListNode* &front) {
    front = new ListNode{elem1,elem2,elem3, front};

    }



int main () {

    ListNode* front = new ListNode();


    int nlinea, ninterno, cantasientos;
    int fd;
    int p=0;
    int opcion;


    fd = open("archivo.txt", O_CREAT | O_WRONLY, 0600);


    if ( fd == NULL) {
        printf("No se pudo crear el archivo");
        }

        else {
            cout<<("Se creo el archivo")<<endl;
          //  write(fd, "HOLA ", 13);
           close(fd);
            }


    while (!p){

        cout<<("1. Agregar bondi")<<endl;
        cout<<("2. Mostrar bondi")<<endl;

        scanf("%d", &opcion);

        switch (opcion){

            case 1: {
                printf("Ingrese numero de linea: ");
                scanf("%d", &nlinea);
                //write(fd, &nlinea, 13);
                front->nlinea = nlinea;


                printf("Ingrese numero de interno: ");
                scanf("%d", &ninterno);
                ListNode *front = new ListNode();
                addToFront(ninterno, front);


                printf("Ingrese numero de asientos: ");
                scanf("%d", &cantasientos);
                front->cantasientos = cantasientos;

                break;
            }
          case 2: {
              printList(front);
              break;
          }
x
        }




    }

}
