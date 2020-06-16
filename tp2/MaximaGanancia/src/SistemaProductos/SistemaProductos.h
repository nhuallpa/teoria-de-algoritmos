//
// Created by nestor on 6/15/20.
//

#ifndef MAXIMAGANANCIA_SISTEMAPRODUCTOS_H
#define MAXIMAGANANCIA_SISTEMAPRODUCTOS_H
#include <iostream>
#include "Utils/Utils.h"
#include "SeleccionadorProductos/SeleccionadorProductos.h"
class SistemaProductos {

private:
    t_parametros parametros;

public:
    int ejecutar(int argc, char **argv);

    void mostrarResultados(const vector<Producto> &productosSeleccionados) const;
};


#endif //MAXIMAGANANCIA_SISTEMAPRODUCTOS_H
