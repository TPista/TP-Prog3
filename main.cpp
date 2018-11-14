//TP DE BUSQUEDAS, GRUPO: CARRO,PISTARELLI, RODRIGUEZ, MONTI
#include <iostream>
using namespace std;
int main() {
    int numeros[] = {3,2,1,5,4};
    int aux, pos, i, j;

//primer for hago una lectura de la fila de enteros, donde tomo cada numero en el auxiliar
    for  (i=0; i<5 ; i++){
        pos = i;
        aux = numeros [i];

     //en el while comparo el valor del aux con la posicion del siguiente y lo corro hacia la izquierda si es mas chico

        while ((pos>0) && numeros [ pos-1 ] > aux){

            numeros[pos]= numeros [pos-1];

            pos --;
        }
        numeros [pos] = aux;
    }

    cout<<"Ascendente Inserción : ";
    for(i=0;i<5;i++){

        cout<<numeros[i]<<" ";
    }


    cout<< "\nDescendente Inserción: ";
    for(i=4; i>=0; i--){

        cout<<numeros[i]<< " ";
    }

    //BURBUJEO

    for(i=0; i<5; i++){                        //
        for(j=0; j<5; j++){
            if(numeros[j] > numeros[ j+1]){
                numeros[ j]= numeros [ j+1];
                numeros [ j+1]= aux;
            }
        }
    }

    cout<< "\nAscendente Burbujeo: ";
    for(i=0;i<5;i++){
        cout<<numeros[i]<<" ";
    }


    cout<<"\n Descendente Burbujeo: ";

    for(i=4; i>=0; i--){

        cout<<numeros[ i]<<" ";
    }



    }
