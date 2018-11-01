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

void LinkedList::deleteList(ListNode *front) {
    ListNode *next;
    for (ListNode *ptr = front; ptr != nullptr; ptr = next) {
        next = ptr->next;
        delete ptr;
    }
}




void removeIndex(ListNode *&front, int index) {

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




void printList(ListNode *front) {

    for (ListNode *ptr = front; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->nlinea <<endl;
        cout << ptr->ninterno << endl;
        cout << ptr->cantasientos << endl;
    }

}



void addToFront(int elem1,int elem2,int elem3, ListNode* &front) {
    front = new ListNode{elem1,elem2,elem3, front};

    }



int main () {

    ListNode* front;// = ListNode; //new ListNode;


    int nlinea, ninterno, cantasientos;
    int fd;
    int inicio=0;
    int opcion;


    fd = open("archivo.txt", O_CREAT | O_WRONLY);


    if (fd == NULL){
        printf("No se pudo crear el archivo");
    }
    else {
        cout<<("Se creo el archivo")<<endl;
          //  write(fd, "HOLA ", 13);
          close(fd);
    }
    //removeIndex(front,0);
    addToFront(1, 1, 50, front);
    addToFront(1, 2, 45, front);


    while (!inicio){

        cout<<("1. Agregar bondi")<<endl;
        cout<<("2. Mostrar bondi")<<endl;

        scanf("%d", &opcion);

        switch (opcion){

            case 1: {
                printf("Ingrese numero de linea: ");
                scanf("%d", &nlinea);
                //write(fd, &nlinea, 13);

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
