//
// Created by nestor on 6/15/20.
//

#include "Producto.h"

Producto::Producto(const string &nombre, int trimestre, int ganancia) : nombre(nombre), trimestre(trimestre),
                                                                        ganancia(ganancia) {}

int Producto::getGanancia() const {
    return ganancia;
}

