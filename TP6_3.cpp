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


int main () {

    string discapacitados;
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
        scanf("%d", &opcion);

        switch (opcion){

            case 1:
                printf("Ingrese numero de linea: ");
                scanf("%d", &nlinea);
                write(fd, &nlinea, 13);

                printf("Ingrese numero de interno: ");
                scanf("%d", &ninterno);


                printf("Ingrese numero de asientos: ");
                scanf("%d", &cantasientos);

                printf("Ingrese si es APTO o NO APTO para discapacitados: ");
                scanf("%s", &discapacitados);

                
        }




    }

}
