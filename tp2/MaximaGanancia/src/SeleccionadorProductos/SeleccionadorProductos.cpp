//
// Created by nestor on 6/15/20.
//

#include <vector>
#include "SeleccionadorProductos.h"
using std::vector;

vector <Producto> SeleccionadorProductos::seleccionarConMejorGanancia(std::vector<Producto> productos) {
    vector<Producto> productosSeleccionados;
    productosSeleccionados.push_back(productos.at(0));
    return productosSeleccionados;
}
