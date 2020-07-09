//
// Created by nestor on 6/15/20.
//

#include <vector>
#include <map>
#include <Utils/Utils.h>
#include "SeleccionadorProductos.h"
using std::vector;
using std::map;

vector<Producto> SeleccionadorProductos::seleccionar() {

    map<int, int> optimos;
    map<int, bool> elegidos;

    optimos[0] = 0;
    optimos[1] = productos.at(1).getGanancia();
    elegidos[0]= false;
    elegidos[1]= true;


    map<int, int> anterior_posible = this->calcularAnteriorePosibles();

    for (int i = 2; i < productos.size(); i++) {
        int gananciaOptimoAnterior = optimos.at(anterior_posible.at(i));
        int estaSembrado = productos.at(i).getGanancia() + gananciaOptimoAnterior;
        int noEstaSembrado = optimos[i-1];

        elegidos[i] = estaSembrado > noEstaSembrado;

        optimos[i] = std::max(estaSembrado, noEstaSembrado);
    }

    int i = productos.size() -1 ; // i = n
    vector<Producto> productosSeleccionados;
    while (i>0) {
        if (elegidos.at(i)) {
            productosSeleccionados.push_back(productos.at(i));
            i = anterior_posible[i];
        } else {
            i = i - 1;
        }
    }

    return productosSeleccionados;
}

map<int, int> SeleccionadorProductos::calcularAnteriorePosibles() {

    int n = productos.size()-1;
    int i = n;
    int j = n - 1;
    map<int, int> anteriorPosible;
    while ( i > 1) {

        if (!this->permiteSembrarSeguidos(productos.at(j), productos.at(i))) {
            j -= 1;
        } else {
            anteriorPosible[i] = j;
            i -= 1;
            j = i - 1;
        }
    }
    return anteriorPosible;
}

SeleccionadorProductos::SeleccionadorProductos(const vector<Producto> &productos,
                                               const std::vector<std::pair<string, string> >  &restricciones) : productos(productos),
                                                                                           restricciones(
                                                                                                   restricciones) {
    for (std::pair<string, string> element : this->restricciones) {
        string nombreProducto = element.first;
        string nombreRestringido = element.second;
        std::pair<string, string> B(nombreRestringido,nombreRestringido);
        auto restriccionProducto = this->restriccionesAgrupadas.find(nombreProducto);

        if (restriccionProducto != this->restriccionesAgrupadas.end()) {
            restriccionProducto->second.insert(B);
        } else {
            std::map<string, string> nuevaRestriccion;
            nuevaRestriccion.insert(B);
            this->restriccionesAgrupadas.insert(std::pair<string, std::map<string, string>>(nombreProducto, nuevaRestriccion));
        }

    }
}

bool SeleccionadorProductos::permiteSembrarSeguidos(Producto &productoA, Producto &productoB) {
    bool estaPermitido = false;
    auto unProductoAnterior = this->restriccionesAgrupadas.find(productoA.getNombre());

    if (!productoA.mismoNombre(productoB.getNombre()) && !productoA.mismoTrimestre(productoB)) {
        if (unProductoAnterior == this->restriccionesAgrupadas.end())  {
            estaPermitido = true;
        } else if (unProductoAnterior->second.find(productoB.getNombre()) == unProductoAnterior->second.end()) {
            estaPermitido = true;
        }
    }

    return estaPermitido;
}
