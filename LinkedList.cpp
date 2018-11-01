//
// Created by pista on 31/10/18.
//

#include "LinkedList.h"
#ifndef COLECTIVO_LINKEDLIST_H
#define COLECTIVO_LINKEDLIST_H
#include "Colectivo.h"
#include <iostream>using namespace std;struct ListNode {
Colectivo data;
struct ListNode* next;
};class LinkedList {public:
    void deleteList(ListNode *);
    void filtrar_discapacidad(ListNode *);
    void removeIndex(ListNode *&, int);
    int contar_asientos(ListNode *&);
    void sortedInsert(struct ListNode**, struct ListNode*);
    //void sortedInsertInterno(struct ListNode**, struct ListNode*);
    void insertionSort(struct ListNode **);
    void push(struct ListNode** , Colectivo );
    void printList(struct ListNode *);
    void saveList(struct ListNode *);
    void openList();
};


void LinkedList::filtrar_discapacidad(ListNode *front){
    //recorro lista para contar cantidad apto discapacidad
    vector<int> apto_discapacidad;
    int ban=0;
    for (ListNode *ptr = front; ptr != nullptr; ptr = ptr->next) {
        if(ban==0){
            ban=1;
            apto_discapacidad.push_back(ptr->data.getNum_linea());
            if(ptr->data.isApto_discapacidad()==1) {
                apto_discapacidad.push_back(1);
            }
            else{
                apto_discapacidad.push_back(0);
            }
        }
        else {
            int ban2=0;
            for (int i = 1; i < apto_discapacidad.size(); i+=2) {
                if(apto_discapacidad[i-1]==ptr->data.getNum_linea()){
                    ban2=1;
                    if(ptr->data.isApto_discapacidad()==1) {
                        apto_discapacidad[i]+=1;
                    }
                }
            }
            if(ban2==0){ //el num de linea no estaba en el vector, se carga
                apto_discapacidad.push_back(ptr->data.getNum_linea());
                if(ptr->data.isApto_discapacidad()==1) {
                    apto_discapacidad.push_back(1);
                }
                else{
                    apto_discapacidad.push_back(0);
                }
            }
        }
    }
    for (int i = 1; i < apto_discapacidad.size(); i+=2) {
        cout << "" << endl;
        cout << "N° Linea: " << apto_discapacidad[i-1] << endl;
        cout << "Cant de veiculos aptos discapacitados: " << apto_discapacidad[i] << endl;
    }


    int LinkedList::contar_asientos(ListNode *&front){
        //recorro lista para contar cantidad de asintos
        int cont=0;
        for (ListNode *ptr = front; ptr != nullptr; ptr = ptr->next) {
            if(ptr->data.getCant_asientos()>27){
                cont++;
            }
        }
        return cont;
    }


    void LinkedList::removeIndex(ListNode *&front, int index) {
        int i=0;
        for (ListNode *ptr = front; ptr != nullptr; ptr = ptr->next) {
            if(ptr->data.getNum_interno()==index){
                index=i;
            }
            i++;
        }
        if (front == nullptr) {
            return;
        }
        if (index == 0) {
            ListNode *trash = front;
            front = front->next;
            delete trash;
        }
        else {
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

    void LinkedList::insertionSort(struct ListNode **head_ref) {
        struct ListNode *sorted = NULL;
        struct ListNode *current = *head_ref;
        while (current != NULL) {
            struct ListNode *next = current->next;
            sortedInsert(&sorted, current);        current = next;
        }
        *head_ref = sorted;}void LinkedList::sortedInsert(struct ListNode** head_ref, struct ListNode* new_node) {
        struct ListNode* current;
        if (*head_ref == NULL || (*head_ref)->data.getNum_linea() >= new_node->data.getNum_linea() ) {        new_node->next = *head_ref;
            *head_ref = new_node;
        }
        else {
            current = *head_ref;
            while (current->next!=NULL && current->next->data.getNum_linea() < new_node->data.getNum_linea()){
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }void LinkedList::printList(struct ListNode *head){
        struct ListNode *temp = head;
        while(temp != NULL) {
            cout << "" << endl;
            cout << "N° Linea: " <<  temp->data.getNum_linea() << endl;
            cout << "N° Interno: " << temp->data.getNum_interno() << endl;
            cout << "Cantidad de asientos: " << temp->data.getCant_asientos() << endl;
            cout << "Apto discapacitados: " << temp->data.isApto_discapacidad() << endl;
            temp = temp->next;
        }
    }void LinkedList::saveList(struct ListNode *head){
        struct ListNode *temp = head;
        ofstream outputfile;
        outputfile.open("data.txt");
        outputfile  << "LISTADO DE COLECTIVOS: " << endl;    while(temp != NULL) {
            outputfile  << "" << endl;
            outputfile  << "N° Linea: " <<  temp->data.getNum_linea() << endl;
            outputfile  << "N° Interno: " << temp->data.getNum_interno() << endl;
            outputfile  << "Cantidad de asientos: " << temp->data.getCant_asientos() << endl;
            outputfile  << "Apto discapacitados: " << temp->data.isApto_discapacidad() << endl;
            temp = temp->next;
        }
    }void LinkedList::openList() {
        string line;
        ifstream myfile("data.txt");
        if (myfile.is_open()) {
            while (!myfile.eof()) {
                getline(myfile, line);
                cout << line << endl;
            }
            myfile.close();
        }
        else cout << "Archivo no encontrado";}
    void LinkedList::push(struct ListNode** head_ref, Colectivo new_data) {
        struct ListNode* new_node = new ListNode;
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }

}

