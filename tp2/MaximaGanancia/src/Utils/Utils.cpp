//
// Created by nestor on 6/1/20.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Utils/Utils.h"

using namespace std;

t_parametros Utils::tomarParametros(int argc, char **argv) {
    int c;
    bool pendingParams = true;
    t_parametros params;
    params.productosArchivo = ' ';

    while (pendingParams) {
        static struct option long_options[] =
                {
                        {"productos", required_argument, nullptr, 'p'},
                        {"restricciones", required_argument, nullptr, 'r'},
                        {0, 0, 0, 0}
                };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long(argc, argv, "p:a:",
                        long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c) {
            case 'p':
                params.productosArchivo = optarg;
                break;
            case 'a':
                params.restriccionesArchivo = optarg;
                break;
            case '?':
                /* getopt_long already printed an error message. */
                break;

            default:
                pendingParams = false;
        }
    }

    return params;

}

void Utils::mostrarAyuda() {
    cout<<"---->Ejemplo: MaximaGanancia -p [ruta de archivo] -r [ruta de archivo]<----"<<endl;
}

std::vector<Producto> Utils::cargarProductos(std::string rutaArchivo) {

    std::vector<int> piezas;

    ifstream archivo;
    archivo.open(rutaArchivo.c_str(), std::ifstream::in);
    if (!archivo.is_open()) {
        throw invalid_argument("El archivo no se pudo abrir");
    }
    string volumen;
    while (archivo >> volumen) {
        try {
            piezas.push_back(stoi(volumen));
        } catch (exception &e) {
            throw invalid_argument("El formato del archivo es incorrecto. Solo debe contener numeros.");
        }
    }
    archivo.close();

    return piezas;
}