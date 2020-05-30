#ifndef ALGORITMO_C_FUNCIONES_H_INCLUDED
#define ALGORITMO_C_FUNCIONES_H_INCLUDED

#include"Lista/lista_enteros.h"

using namespace std;

namespace ProcesoC {

    /* Precondiciones de cargar_piezas:
     *
     * -El archivo con el volumen de las piezas debe encontrarse en el mismo directorio que el ejecutable del programa
     * -El archivo con el volumen de las piezas debe llamarse "piezas.txt"
     * -El archivo con el volumen de las piezas debe tener el formato presentado en la consigna del trabajo práctico 1
     * -El puntero a Lista_enteros "referencia a piezas" debe apuntar a una Lista_enteros válida y vacía
     *
     * Postcondiciones de cargar pieza:
     *
     * -La lista a la cual apunta "referencia_a_piezas" será cargada con la información de volumen presente en "piezas.txt"
     *
     */

    void cargar_piezas(Lista_enteros *referencia_a_piezas);

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

    int obtener_elemento_mayoritario(Lista_enteros *referencia_a_piezas);

    /* Precondiciones de mostrar_resultado:
     *
     * -"elemento_mayoritario" es una variable de tipo int válida
     * -"elemento_mayoritario" fue obtenido a partir de utilizar correctamente "obtener_elemento_mayoritario"
     *
     * Postcondiciones de mostrar_resultado:
     *
     * -Muestra en pantalla el resultado provocado por "elemento_mayoritario".
     *
     */

    void mostrar_resultado(int elemento_mayoritario);

}
#endif
