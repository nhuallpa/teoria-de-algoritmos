//
// Created by nestor on 6/2/20.
//

#include "SistemaMayoritario.h"

static const char *const PROCESO_A = "a";
static const char *const PROCESO_B = "b";
static const char *const PROCESO_C = "c";

using std::cout;
using std::endl;


int SistemaMayoritario::ejecutar(int argc, char **argv) {
    try {

        parametros = Utils::tomarParametros(argc, argv);
        validarOpciones();
        encontrarMayoritario();
        mostrarElementoMayoritario();

    } catch (exception & e) {
        cout<<e.what()<<endl;
        Utils::mostrarAyuda();
        return 1;
    }

    return 0;
}


void SistemaMayoritario::ejecutarProcesoC(t_parametros parametros) {
    Lista_enteros piezas;
    Lista_enteros* ptr_piezas = &piezas;

    ProcesoC::cargar_piezas(ptr_piezas);

    int elemento_mayoritario = ProcesoC::obtener_elemento_mayoritario(ptr_piezas);

    ProcesoC::mostrar_resultado(elemento_mayoritario);
}

void SistemaMayoritario::ejecutarProcesoB(t_parametros parametros) {
    int* cargador_piezas = new int [ProcesoB::MAX_TAMANIO_VECTOR];

    int total_piezas = ProcesoB::cargar_piezas(cargador_piezas);

    int* piezas = ProcesoB::asegurar_vector_completo(cargador_piezas, total_piezas);

    delete []cargador_piezas;

    int elemento_mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas, total_piezas);

    ProcesoB::mostrar_resultado(elemento_mayoritario);

    delete []piezas;
}

int SistemaMayoritario::ejecutarProcesoA(t_parametros parametros) {
    std::vector<int> piezas = Utils::cargarPiezas(parametros.rutaArchivo);
    return ProcesoA::obtener_elemento_mayoritario(piezas);
}

void SistemaMayoritario::encontrarMayoritario() {
    if (parametros.tipoProceso.compare(PROCESO_A) == 0 ) {
        elementoMayotario = ejecutarProcesoA(parametros);
    } else if (parametros.tipoProceso.compare(PROCESO_B) == 0 ) {
        ejecutarProcesoB(parametros);
    } else if (parametros.tipoProceso.compare(PROCESO_C) == 0 ) {
        ejecutarProcesoC(parametros);
    } else {
        throw invalid_argument("El parametro '-p' de tipo de proceso es incorrecto");
    }
}


void SistemaMayoritario::validarOpciones() {
    if (parametros.tipoProceso.size() == 0 || parametros.rutaArchivo.size() == 0 ) {
        throw invalid_argument("El tipo de proceso y el archivo son obligatorios");
    }
}

void SistemaMayoritario::mostrarElementoMayoritario() {
    if (elementoMayotario == 0) {
        cout<<"No existe un elemento mayoritario"<<endl;
    } else {
        cout<<"El elemento mayoritario es: " << elementoMayotario<<endl;
    }
}
