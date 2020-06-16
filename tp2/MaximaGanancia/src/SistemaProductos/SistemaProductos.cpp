//
// Created by nestor on 6/15/20.
//

#include "SistemaProductos.h"
using namespace std;

int SistemaProductos::ejecutar(int argc, char **argv) {

    try {

        this->parametros = Utils::tomarParametros(argc, argv);

        vector<Producto> &productos =
                std::map<string, string> &restricciones;

        SeleccionadorProductos seleccionadorProductos()


    } catch (exception & e) {
        cout<<e.what()<<endl;
        Utils::mostrarAyuda();
        return 1;
    }

    return 0;
}
