//
// Created by pista on 31/10/18.
//

#ifndef TP_PROG3_LINKEDLIST_H
#define TP_PROG3_LINKEDLIST_H


#include "LinkedList.h"
#ifndef COLECTIVO_LINKEDLIST_H
#define COLECTIVO_LINKEDLIST_H
#include "Colectivo.h"
#include <iostream>

using namespace std;
struct ListNode {Colectivo data; struct ListNode* next;

    };

class LinkedList {public:
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
#endif //TP_PROG3_LINKEDLIST_H
