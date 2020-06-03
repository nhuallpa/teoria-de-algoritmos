#ifndef ALGORITMO_A_FUNCIONES_H_INCLUDED
#define ALGORITMO_A_FUNCIONES_H_INCLUDED

#include <vector>

using namespace std;

namespace ProcesoA {

    /* Precondiciones de obtener_elemento_mayoritario:
     *
     * -El puntero "referencia_a_piezas" debe apuntar a una Lista_enteros válida y cargada.
     *
     * Postcondiciones de obtener_elemento_mayoritario
     *
     * -Si existe un elemento mayoritario en la Lista_enteros a la que apunta "referencia_a_piezas", devuelve su volumen.
     * -Caso contrario, devuelve un valor inválido.
     *
     */

    int obtener_elemento_mayoritario (std::vector<int> piezas);

}

#endif
