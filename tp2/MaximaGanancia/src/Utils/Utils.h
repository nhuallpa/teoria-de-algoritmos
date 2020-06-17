#ifndef MAYORITARIO_UTIL_H
#define MAYORITARIO_UTIL_H
#include <string>
#include <getopt.h>
#include <vector>
#include <map>
#include "Producto/Producto.h"
#include <algorithm>

using std::string;

typedef struct parametros {
    std::string productosArchivo;
    std::string restriccionesArchivo;
} t_parametros;

class Utils {

public:
    static t_parametros tomarParametros(int argc, char **argv);

    static void mostrarAyuda();

    static std::vector<Producto> cargarProductos(std::string rutaArchivo);
    static std::map<string, string> cargarRestricciones(std::string rutaArchivo);

    static bool comparadorDosProductos(Producto unProducto, Producto otroProducto);

    static std::vector<std::string> split(const std::string& str, const std::string& delim);

};
#endif //MAYORITARIO_UTIL_H
