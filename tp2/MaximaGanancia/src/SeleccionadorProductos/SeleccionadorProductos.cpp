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
        auto search = this->restricciones.find(productos.at(j).getNombre());
        if (search != this->restricciones.end() &&
            productos.at(i).mismoNombre(this->restricciones.at(productos.at(j).getNombre()))) {
            j -= 1;
        } else if (productos.at(i).mismoTrimestre(productos.at(j))) {
            j -= 1;
        } else {
            anteriorPosible[i] = j;
            i -= 1;
        }
    }
    return anteriorPosible;
}

SeleccionadorProductos::SeleccionadorProductos(const vector<Producto> &productos,
                                               const map<string, string> &restricciones) : productos(productos),
                                                                                           restricciones(
                                                                                                   restricciones) {}
