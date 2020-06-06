#include"AlgoritmoC.h"
#include<fstream>
#include<iostream>

namespace ProcesoC {

    const int MAYORITARIO_NO_HALLADO = 0;
    const int ELEMENTO_SORPRESA = 3330;

    void cargar_piezas(Lista_enteros *piezas) {

        ifstream archivo("piezas.txt");

        string volumen;

        while (archivo >> volumen) {

            piezas->alta_final(stoi(volumen));

        }

        archivo.close();

    }

    int apariciones(Lista_enteros *piezas, int volumen_buscar) {

        int cantidad = 0;

        for (int i = 1; i <= (piezas->obtener_tamanio()); i++) {

            if (piezas->obtener_buscado(i) == volumen_buscar) {

                cantidad++;

            }

        }

        return cantidad;

    }

    Lista_enteros *hallar_pares_iguales(Lista_enteros *piezas) {

        Lista_enteros *ptr_pares_iguales = new Lista_enteros;

        if (piezas->obtener_tamanio() > 2) {

            for (int i = 0; i <= ((piezas->obtener_tamanio() / 2) - 1); i++) {

                if (piezas->obtener_buscado_v2(2 * i) == piezas->obtener_buscado_v2((2 * i) + 1)) {

                    ptr_pares_iguales->alta_final(piezas->obtener_buscado_v2(2 * i));

                }

            }

        } else {

            ptr_pares_iguales->alta_principio(piezas->obtener_primero());

        }

        return ptr_pares_iguales;

    }

    int obtener_candidato(Lista_enteros *piezas) {

        int candidato = 0;

        if ((piezas->obtener_tamanio()) == 0) {

            return candidato;

        } else if ((piezas->obtener_tamanio()) == 1) {

            return piezas->obtener_primero();

        } else {

            Lista_enteros *ptr_pares_iguales = hallar_pares_iguales(piezas);

            candidato = obtener_candidato(ptr_pares_iguales);

            delete ptr_pares_iguales;

            if ((((piezas->obtener_tamanio()) % 2) == 0) || (candidato != 0)) {

                return candidato;

            } else {

                return piezas->obtener_ultimo();

            }

        }

    }


    int obtener_elemento_mayoritario(Lista_enteros *piezas) {

        int el_candidato = obtener_candidato(piezas);

        if ((el_candidato == 0) || (apariciones(piezas, el_candidato) <= (piezas->obtener_tamanio() / 2))) {

            return MAYORITARIO_NO_HALLADO;

        } else {

            return el_candidato;

        }

    }

}