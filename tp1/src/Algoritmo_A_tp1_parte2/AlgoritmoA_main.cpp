#include<iostream>
#include"algoritmo_a_funciones.h"
#include"lista_enteros.h"

using namespace std;

int main () {

    Lista_enteros piezas;
    Lista_enteros* ptr_piezas = &piezas;

    cargar_piezas(ptr_piezas);

    int elemento_mayoritario = obtener_elemento_mayoritario(ptr_piezas);

    mostrar_resultado(elemento_mayoritario);

    return 0;
}
