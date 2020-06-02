#include "Lista/lista_enteros.h"
#include "ProcesoA/AlgoritmoA.h"
#include "ProcesoB/AlgoritmoB.h"
#include "ProcesoC/AlgoritmoC.h"
#include "Utils/Utils.h"
#include <iostream>

static const char *const PROCESO_A = "a";
static const char *const PROCESO_B = "b";
static const char *const PROCESO_C = "c";
using std::cout;
using std::endl;

t_parametros parametros;
int elementoMayotario = 0;

void ejecutarProcesoC(t_parametros parametros) {
    Lista_enteros piezas;
    Lista_enteros* ptr_piezas = &piezas;

    ProcesoC::cargar_piezas(ptr_piezas);

    int elemento_mayoritario = ProcesoC::obtener_elemento_mayoritario(ptr_piezas);

    ProcesoC::mostrar_resultado(elemento_mayoritario);
}

void ejecutarProcesoB(t_parametros parametros) {
    int* cargador_piezas = new int [ProcesoB::MAX_TAMANIO_VECTOR];

    int total_piezas = ProcesoB::cargar_piezas(cargador_piezas);

    int* piezas = ProcesoB::asegurar_vector_completo(cargador_piezas, total_piezas);

    delete []cargador_piezas;

    int elemento_mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas, total_piezas);

    ProcesoB::mostrar_resultado(elemento_mayoritario);

    delete []piezas;
}

void ejecutarProcesoA(t_parametros parametros) {

    Lista_enteros piezas;
    Lista_enteros* ptr_piezas = &piezas;

    ProcesoA::cargar_piezas(ptr_piezas);

    int elemento_mayoritario = ProcesoA::obtener_elemento_mayoritario(ptr_piezas);

    ProcesoA::mostrar_resultado(elemento_mayoritario);
}

void encontrarMayoritario() {
    if (parametros.tipoProceso.compare(PROCESO_A) == 0 ) {
        ejecutarProcesoA(parametros);
    } else if (parametros.tipoProceso.compare(PROCESO_B) == 0 ) {
        ejecutarProcesoB(parametros);
    } else if (parametros.tipoProceso.compare(PROCESO_C) == 0 ) {
        ejecutarProcesoC(parametros);
    } else {
        throw invalid_argument("El parametro '-p' de tipo de proceso es incorrecto");
    }
}


void validarOpciones() {
    if (parametros.tipoProceso.size() == 0 || parametros.rutaArchivo.size() == 0 ) {
        throw invalid_argument("El tipo de proceso y el archivo son obligatorios");
    }
}


// TODO: AGREGAR TEST
// TODO: Agregar getopt para obtener el tipo de proceso y el archivo a procesar
// TODO: Separar la lectura del archivo del algoritmo
// TODO: Cambiar por listas de STL en PROCESO A
// TODO: Cambiar por listas de STL en PROCESO B
// TODO: Cambiar por listas de STL en PROCESO C
// TODO: manejar excepciones
// TODO: Refactor de nombres de metodos y archivos
// TODO: Validaciones y help usage para la ejecución por linea de comando
// TODO: Docuementar en readme

int main(int argc, char* argv[]) {
    try {
        Utils::tomarParametros(argc, argv);

        validarOpciones();

        encontrarMayoritario();

    } catch (exception & e) {
        cout<<e.what()<<endl;
        Utils::mostrarAyuda();
        return 1;
    }

    return 0;
}

