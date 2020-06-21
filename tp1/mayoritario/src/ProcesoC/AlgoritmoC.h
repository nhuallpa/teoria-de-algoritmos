#ifndef ALGORITMO_C_FUNCIONES_H_INCLUDED
#define ALGORITMO_C_FUNCIONES_H_INCLUDED

#include <vector>
#include <algorithm>

using namespace std;

namespace ProcesoC {

    int apariciones(std::vector<int> piezas, int volumen);

    std::vector<int> hallar_pares_iguales(std::vector<int> piezas);

    int obtener_candidato(std::vector<int> piezas);

    int obtener_elemento_mayoritario(std::vector<int> piezas);

}
#endif
