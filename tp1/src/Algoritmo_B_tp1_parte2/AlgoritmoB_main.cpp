#include"Algoritmo_b_funciones.h"

using namespace std;

int main () {

    int* cargador_piezas = new int [MAX_TAMANIO_VECTOR];

    int total_piezas = cargar_piezas(cargador_piezas);

    int* piezas = asegurar_vector_completo(cargador_piezas, total_piezas);

    delete []cargador_piezas;

    int elemento_mayoritario = obtener_elemento_mayoritario(piezas, total_piezas);

    mostrar_resultado(elemento_mayoritario);

    delete []piezas;

    return 0;
}
