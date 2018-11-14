// Created by agustin on 07/09/18.
//Ejercicio Practica 3 - 11
//Integrantes: Agustin Carro, Carlos Rodriguez, Diego Monti, Tomas Pistarelli
#include <iostream>

using namespace std;
#ifndef CALCULADORA_CALCULADORA_H
#define CALCULADORA_CALCULADORA_H


class Calculadora {

public:

    void suma (int a, int b){
        cout<<"la suma es=" <<a+b<< endl;
    }

    void resta (int a, int b){
        if(a>b){
            cout<<"Ladivision es="<<a-b<<endl;
        }if(b>a){
            cout<<"NO SE PUEDE REALIZAR LA RESTA"<<endl;
        }
    }

    void multiplicacion(int a, int b){

        cout<<"La multiplicacion es="<<a*b<<endl;
    }

    void division (int a, int b){
        if(a>b){
            cout<< "La division es="<<a/b<<endl;
        }if(b>a){
            cout<<"NO SE PUEDE HACER LA DIVISION"<<endl;
        }
    }

};


#endif //CALCULADORA_CALCULADORA_H
