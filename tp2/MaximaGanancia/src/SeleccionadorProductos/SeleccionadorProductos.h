//
// Created by nestor on 6/15/20.
//

#ifndef MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H
#define MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H

#include "Producto/Producto.h"
#include <vector>
#include <map>
#include <algorithm>
using std::vector;
using std::map;

class SeleccionadorProductos {

private:

    vector<Producto> productos;
    std::vector<std::pair<string, string> >  restricciones;

    std::map<string, std::map<string, string> > restriccionesAgrupadas;

public:
    SeleccionadorProductos(const vector<Producto> &productos, const std::vector<std::pair<string, string> >  &restricciones);

public:
    /**
     * Selecciona los productos que maximicen la ganancia.
     * @param productos
     * @param restricciones Un mapa donde indica que el producto A no podemos plantar el producto B. <code>restricciones[A]=B</code>
     * @return
     */
    vector<Producto> seleccionar();

    map<int, int> calcularAnteriorePosibles();

    bool permiteSembrarSeguidos(Producto &producto, Producto &producto1);
};


#endif //MAXIMAGANANCIA_SELECCIONADORPRODUCTOS_H
