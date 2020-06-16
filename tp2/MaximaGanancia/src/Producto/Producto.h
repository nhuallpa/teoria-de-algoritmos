//
// Created by nestor on 6/15/20.
//

#ifndef MAXIMAGANANCIA_PRODUCTO_H
#define MAXIMAGANANCIA_PRODUCTO_H

#include <string>
using std::string;

class Producto {
private:
    string nombre;
    int trimestre;
    int ganancia;
public:

    Producto(const string &nombre, int trimestre, int ganancia);

    int getGanancia() const;

    const string &getNombre() const;

    int getTrimestre() const;

    bool mismoNombre(string otroNombre);

    bool mismoTrimestre(const Producto & otroProducto);
};


#endif //MAXIMAGANANCIA_PRODUCTO_H
