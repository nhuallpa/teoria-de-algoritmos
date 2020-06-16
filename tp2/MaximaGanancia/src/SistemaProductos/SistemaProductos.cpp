//
// Created by nestor on 6/15/20.
//

#include "SistemaProductos.h"
using namespace std;

int SistemaProductos::ejecutar(int argc, char **argv) {

    try {
        this->parametros = Utils::tomarParametros(argc, argv);
        SeleccionadorProductos seleccionadorProductos(Utils::cargarProductos(parametros.productosArchivo),
                                                      Utils::cargarRestricciones(parametros.restriccionesArchivo));
        mostrarResultados(seleccionadorProductos.seleccionar());

    } catch (exception & e) {
        cout<<e.what()<<endl;
        Utils::mostrarAyuda();
        return 1;
    }

    return 0;
}

void SistemaProductos::mostrarResultados(const vector<Producto> &productosSeleccionados) const {
    int gananciaMaxima = 0;
    cout << "Productos seleccionados:" << endl;
    for (const auto &producto : productosSeleccionados) {
        cout << "*" << producto << endl;
        gananciaMaxima += producto.getGanancia();
    }
    cout << "* GANANCIA:" << gananciaMaxima << endl;
}
