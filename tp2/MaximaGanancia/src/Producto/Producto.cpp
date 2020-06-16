//
// Created by nestor on 6/15/20.
//

#include "Producto.h"

Producto::Producto(const string &nombre, int trimestre, int ganancia) : nombre(nombre), trimestre(trimestre),
                                                                        ganancia(ganancia) {}

int Producto::getGanancia() const {
    return ganancia;
}

const string &Producto::getNombre() const {
    return nombre;
}

int Producto::getTrimestre() const {
    return trimestre;
}

bool Producto::mismoNombre(string otroNombre) {
    return this->nombre.compare(otroNombre) == 0;
}

bool Producto::mismoTrimestre(const Producto &otroProducto) {
    return this->trimestre == otroProducto.trimestre;
}

std::ostream &operator<<(std::ostream &os, const Producto &producto) {
    os << "nombre: " << producto.nombre << " trimestre: " << producto.trimestre << " ganancia: " << producto.ganancia;
    return os;
}

