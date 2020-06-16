//
// Created by nestor on 6/15/20.
//

#ifndef MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H
#define MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H

#include "Producto/Producto.h"
#include <vector>
#include <map>
using std::vector;
using std::map;

class SeleccionadorProductos {

private:
    vector<Producto> productos;
    std::map<string, string> restricciones;

public:
    SeleccionadorProductos(const vector<Producto> &productos, const std::map<string, string> &restricciones);

public:
    /**
     * Selecciona los productos que maximicen la ganancia.
     * @param productos
     * @param restricciones Un mapa donde indica que el producto A no podemos plantar el producto B. <code>restricciones[A]=B</code>
     * @return
     */
    vector<Producto> seleccionar();

    map<int, int> calcularAnteriorePosibles();
};


#endif //MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H
