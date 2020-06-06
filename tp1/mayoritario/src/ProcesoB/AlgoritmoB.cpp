#include"AlgoritmoB.h"
#include<fstream>
#include<iostream>

namespace ProcesoB {

    const int MAYORITARIO_NO_HALLADO = 0;

    int obtener_elemento_mayoritario(std::vector<int> volumenes) {
        std::stable_sort(volumenes.begin(), volumenes.end());
        int piezas_iguales = 1;
        for (int i = 0; i < volumenes.size()-1 ; i++) {

            if (volumenes.at(i) == volumenes.at(i+1)) {
                piezas_iguales++;
            } else {
                piezas_iguales = 1;
            }

            if ((float)piezas_iguales > (float)volumenes.size() / 2) {
                return volumenes.at(i);
            }
        }
        return MAYORITARIO_NO_HALLADO;
    }


}