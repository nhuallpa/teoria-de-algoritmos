//
// Created by nestor on 6/2/20.
//

#ifndef MAYORITARIO_SISTEMAMAYORITARIO_H
#define MAYORITARIO_SISTEMAMAYORITARIO_H
#include "Lista/lista_enteros.h"
#include "ProcesoA/AlgoritmoA.h"
#include "ProcesoB/AlgoritmoB.h"
#include "ProcesoC/AlgoritmoC.h"
#include "Utils/Utils.h"
#include <iostream>


class SistemaMayoritario {
private:

    t_parametros parametros;
    int elementoMayotario = 0;

    int ejecutarProcesoA(t_parametros parametros);
    void ejecutarProcesoC(t_parametros parametros);
    void ejecutarProcesoB(t_parametros parametros);
    void encontrarMayoritario();
    void mostrarElementoMayoritario();
    void validarOpciones();

public:
    int ejecutar(int argc, char **argv);
};


#endif //MAYORITARIO_SISTEMAMAYORITARIO_H
