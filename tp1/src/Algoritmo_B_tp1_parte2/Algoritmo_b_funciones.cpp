#include"Algoritmo_b_funciones.h"
#include<fstream>
#include<iostream>

const int TAM_VECTOR_UNITARIO = 1;

const int MAYORITARIO_NO_HALLADO = 0;
const int ELEMENTO_SORPRESA = 2220;

int cargar_piezas (int cargador_piezas[]) {

    ifstream archivo("piezas.txt");

    string volumen;

    int i = 0;

    while ((archivo>>volumen) && (i < MAX_TAMANIO_VECTOR)) {

        cargador_piezas[i] = stoi(volumen);
        i++;

    }

    archivo.close();

    return i;

}

int* asegurar_vector_completo (int* vector_con_sobra, int tamanio_vector_lleno) {

    int* vector_para_llenar = new int [tamanio_vector_lleno];

    for (int i = 0; i < tamanio_vector_lleno; i++) {

        vector_para_llenar[i] = vector_con_sobra[i];

    }

    return vector_para_llenar;

}

void ordenar_vector (int un_vector[], int tamanio_vector) {

    int auxiliar = 0;

    for(int x = 1; x < tamanio_vector; x++) {

        for(int y = 0; y < (tamanio_vector - x); y++) {

            if(un_vector[y] > un_vector[y+1]){

                auxiliar = un_vector[y];
                un_vector[y] = un_vector[y+1];
                un_vector[y+1] = auxiliar;

            }

        }

    }

}


int obtener_elemento_mayoritario (int piezas[], int total_piezas) {

    ordenar_vector(piezas, total_piezas);

    int volumen_pieza = 0, i = 0, cantidad_volumen = 0;

    bool mismo_volumen = true;

    while (i < total_piezas) {

        volumen_pieza = piezas[i];

        cantidad_volumen = 1;

        mismo_volumen = true;

        i++;

        while ((i < total_piezas) && (mismo_volumen)) {

            if (piezas[i] == volumen_pieza) {

                cantidad_volumen++;
                i++;

            } else {

                if (cantidad_volumen > (total_piezas/2)) {

                    return volumen_pieza;

                } else {

                    mismo_volumen = false;

                }

            }

        }

    }

    return MAYORITARIO_NO_HALLADO; //indica que el lote debe ser descartado, al no haber elemento mayoritario.

}

void mensaje_con_elemento_mayoritario (int elemento_mayoritario) {

    cout << "elemento mayoritario " << elemento_mayoritario << "." << endl;
    cout << "Tenga un buen día." << endl;

}

void mensaje_no_elemento_mayoritario () {

    cout << "no hay elemento mayoritario." << endl;
    cout << "Tenga una buena tarde." << endl;

}

//Otro necesario Easter Egg.

void mensaje_oculto () {

    cout << "Tenga un buen anochecer" << endl;

}

void mostrar_resultado (int elemento_mayoritario) {

    if ((elemento_mayoritario != MAYORITARIO_NO_HALLADO) && (elemento_mayoritario != ELEMENTO_SORPRESA))

        mensaje_con_elemento_mayoritario(elemento_mayoritario);

    else if (elemento_mayoritario == MAYORITARIO_NO_HALLADO)

        mensaje_no_elemento_mayoritario();

    else

        mensaje_oculto();

}
