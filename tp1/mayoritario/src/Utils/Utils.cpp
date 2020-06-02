//
// Created by nestor on 6/1/20.
//

#include <iostream>
#include "Utils/Utils.h"
#include "ProcesoC/AlgoritmoC.h"
#include "ProcesoB/AlgoritmoB.h"
#include "ProcesoA/AlgoritmoA.h"
#include "Lista/lista_enteros.h"
#include "Utils.h"
#include <fstream>

t_parametros Utils::tomarParametros(int argc, char **argv) {
    int c;
    bool pendingParams = true;
    t_parametros params;
    params.tipoProceso = ' ';

    while (pendingParams) {
        static struct option long_options[] =
                {
                        {"proceso", required_argument, nullptr, 'p'},
                        {"archivo", required_argument, nullptr, 'a'},
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
                params.tipoProceso = optarg;
                break;
            case 'a':
                params.rutaArchivo = optarg;
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
    cout<<"---->Ejemplo: mayoritario -p [a|b|c] -a [ruta de archivo]<----"<<endl;
}

std::vector<int> Utils::cargarPiezas(std::string rutaArchivo) {

    std::vector<int> piezas;

    ifstream archivo;
    archivo.open(rutaArchivo.c_str(), std::ifstream::in);
    if (!archivo.is_open()) {
        throw invalid_argument("El archivo no se pudo abrir");
    }
    string volumen;
    while (archivo >> volumen) {
        piezas.push_back(stoi(volumen));
    }
    archivo.close();

    return piezas;
}