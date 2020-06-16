#ifndef MAYORITARIO_UTIL_H
#define MAYORITARIO_UTIL_H
#include <string>
#include <getopt.h>
#include <vector>
#include "Producto/Producto.h"

using std::string;

typedef struct parametros {
    std::string productosArchivo;
    std::string restriccionesArchivo;
} t_parametros;

class Utils {

public:
    static t_parametros tomarParametros(int argc, char **argv);

    static void mostrarAyuda();

    static std::vector<int> cargarProductos(std::string rutaArchivo);

};
#endif //MAYORITARIO_UTIL_H
