#include "Lista/lista_enteros.h"
#include "ProcesoA/AlgoritmoA.h"
#include "ProcesoB/AlgoritmoB.h"
#include "ProcesoC/AlgoritmoC.h"

void ejecutarProcesoA();

void ejecutarProcesoB();

void ejecutarProcesoC();


// TODO: AGREGAR TEST
// TODO: Agregar getopt para obtener el tipo de proceso y el archivo a procesar
// TODO: Separar la lectura del archivo del algoritmo
// TODO: Cambiar por listas de STL en PROCESO A
// TODO: Cambiar por listas de STL en PROCESO B
// TODO: Cambiar por listas de STL en PROCESO B
// TODO: manejar excepciones
// TODO: Refactor de nombres de metodos y archivos
// TODO: Validaciones y help usage para la ejecución por linea de comando
// TODO: Docuementar en readme
int main() {

    ejecutarProcesoA();
    ejecutarProcesoB();
    ejecutarProcesoC();


    return 0;
}

void ejecutarProcesoC() {
    Lista_enteros piezas;
    Lista_enteros* ptr_piezas = &piezas;

    ProcesoC::cargar_piezas(ptr_piezas);

    int elemento_mayoritario = ProcesoC::obtener_elemento_mayoritario(ptr_piezas);

    ProcesoC::mostrar_resultado(elemento_mayoritario);
}

void ejecutarProcesoB() {
    int* cargador_piezas = new int [ProcesoB::MAX_TAMANIO_VECTOR];

    int total_piezas = ProcesoB::cargar_piezas(cargador_piezas);

    int* piezas = ProcesoB::asegurar_vector_completo(cargador_piezas, total_piezas);

    delete []cargador_piezas;

    int elemento_mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas, total_piezas);

    ProcesoB::mostrar_resultado(elemento_mayoritario);

    delete []piezas;
}

void ejecutarProcesoA() {

    Lista_enteros piezas;
    Lista_enteros* ptr_piezas = &piezas;

    ProcesoA::cargar_piezas(ptr_piezas);

    int elemento_mayoritario = ProcesoA::obtener_elemento_mayoritario(ptr_piezas);

    ProcesoA::mostrar_resultado(elemento_mayoritario);
}
