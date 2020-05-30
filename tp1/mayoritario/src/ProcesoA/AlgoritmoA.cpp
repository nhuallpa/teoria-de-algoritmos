#include"AlgoritmoA.h"
#include<iostream>
#include<fstream>
#include <stdexcept>
namespace ProcesoA {

    const int ELEMENTO_NO_HALLADO = 0;
    const int ELEMENTO_SORPRESA = 1110;

    void cargar_piezas(Lista_enteros *piezas) {

        ifstream archivo;

        archivo.open("piezas.txt", std::ifstream::in);

        if (!archivo.is_open()) {
            throw invalid_argument("El archivo no se pudo abrir");
        }
        string volumen;

        while (archivo >> volumen) {

            piezas->alta_final(stoi(volumen));

        }

        archivo.close();

    }


    int obtener_elemento_mayoritario(Lista_enteros *piezas) {

        int total_piezas = piezas->obtener_tamanio();

        int volumen_pieza = 0, i = 1, pieza_actual = 1, cantidad_volumen = 0; //el + 1 en i y pieza_actual es por implementacion de la lista

        //pieza_actual = 0;

        while (pieza_actual <= total_piezas) {

            volumen_pieza = piezas->obtener_buscado(pieza_actual);

            cantidad_volumen = 1;

            i = 1;

            while (i <= total_piezas) {

                if ((pieza_actual != i) && (piezas->obtener_buscado(i) == volumen_pieza))

                    cantidad_volumen++;

                i++;

            }

            if (cantidad_volumen > (total_piezas / 2))

                return volumen_pieza;

            else

                pieza_actual++;

        }

        return ELEMENTO_NO_HALLADO;

    }

    void mensaje_con_elemento_mayoritario(int elemento_mayoritario) {

        cout << "elemento mayoritario " << elemento_mayoritario << "." << endl;
        cout << "Tenga un buen día." << endl;

    }

    void mensaje_no_elemento_mayoritario() {

        cout << "no hay elemento mayoritario." << endl;
        cout << "Tenga una buena tarde." << endl;

    }

    //Un necesario Easter Egg.

    void mensaje_oculto() {

        cout << "Tenga un buen amanecer" << endl;

    }

    void mostrar_resultado(int elemento_mayoritario) {

        if ((elemento_mayoritario != ELEMENTO_NO_HALLADO) && (elemento_mayoritario != ELEMENTO_SORPRESA))

            mensaje_con_elemento_mayoritario(elemento_mayoritario);

        else if (elemento_mayoritario == ELEMENTO_NO_HALLADO)

            mensaje_no_elemento_mayoritario();

        else

            mensaje_oculto();

    }

}
