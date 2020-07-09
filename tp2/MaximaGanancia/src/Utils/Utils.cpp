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

        c = getopt_long(argc, argv, "p:r:",
                        long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c) {
            case 'p':
                params.productosArchivo = optarg;
                break;
            case 'r':
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

    std::vector<Producto> productos;
    Producto productoBase("", 0, 0);
    productos.push_back(productoBase);

    ifstream archivo;
    archivo.open(rutaArchivo.c_str(), std::ifstream::in);
    if (!archivo.is_open()) {
        throw invalid_argument("El archivo no se pudo abrir");
    }
    string lineaProducto;
    while (std::getline(archivo, lineaProducto)) {
        try {
            vector<string> campos = split(lineaProducto, ",");
            // validar longitud y tipo de datos en campos
            Producto unProducto(campos.at(0),atoi(campos.at(1).c_str()),atoi(campos.at(2).c_str()));
            productos.push_back(unProducto);
        } catch (exception &e) {
            throw invalid_argument("El formato del archivo de PRODUCTOS es incorrecto.");
        }
    }
    archivo.close();

    std::stable_sort(productos.begin(), productos.end(), comparadorDosProductos);

    return productos;
}


std::vector<std::pair<string, string> > Utils::cargarRestricciones(std::string rutaArchivo) {

    std::vector<std::pair<string, string> >  restricciones;

    ifstream archivo;
    archivo.open(rutaArchivo.c_str(), std::ifstream::in);
    if (!archivo.is_open()) {
        throw invalid_argument("El archivo no se pudo abrir");
    }
    string linea;
    while (std::getline(archivo, linea)) {
        try {
            vector<string> campos = split(linea, ",");
            // validar longitud y tipo de datos en campos
            restricciones.emplace_back(campos.at(0), campos.at(1));

        } catch (exception &e) {
            throw invalid_argument("El formato del archivo de RESTRICCIONES es incorrecto.");
        }
    }
    archivo.close();

    return restricciones;
}



std::vector<std::string> Utils::split(const std::string &str, const std::string &delim) {

    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;

}

bool Utils::comparadorDosProductos(Producto unProducto, Producto otroProducto) {

    if (!unProducto.mismoTrimestre(otroProducto)) {
        return unProducto.getTrimestre() < otroProducto.getTrimestre();
    }

    return unProducto.getGanancia() < otroProducto.getGanancia();
}
