//
// Created by nestor on 6/15/20.
//

#ifndef MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H
#define MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H

#include "Producto/Producto.h"
#include <vector>

using std::vector;

class SeleccionadorProductos {

public:
    static vector<Producto> seleccionarConMejorGanancia(std::vector<Producto> vector);
};


#endif //MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H
