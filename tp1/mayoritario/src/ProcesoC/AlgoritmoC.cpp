#include "AlgoritmoC.h"

namespace ProcesoC {

    const int MAYORITARIO_NO_HALLADO = 0;

    int apariciones(std::vector<int> piezas, int volumen) {
        int cantidad = 0;
        for ( auto it = piezas.begin(); it != piezas.end(); ++it) {
            if (*it == volumen) {
                cantidad++;
            }
        }
        return cantidad;
    }

    std::vector<int> hallar_pares_iguales(std::vector<int> piezas) {
        std::vector<int> pares_iguales;
        if (piezas.size() > 2) {
            for (int i = 0; i <= ((piezas.size() / 2) - 1); i++) {
                if (piezas.at(2 * i) == piezas.at((2 * i) + 1)) {
                    pares_iguales.push_back(piezas.at(2 * i));
                }
            }
        } else {
            pares_iguales.push_back(piezas.at(piezas.size()-1));
        }

        return pares_iguales;

    }

    int obtener_candidato(std::vector<int> piezas) {

        int candidato = 0;

        if ((piezas.size()) == 0) {
            return candidato;
        } else if (piezas.size() == 1) {
            return piezas.at(0);
        } else {
            std::vector<int> pares_iguales = hallar_pares_iguales(piezas);
            candidato = obtener_candidato(pares_iguales);

            if (piezas.size() % 2 == 0 || candidato != 0) {
                return candidato;
            } else {
                return piezas.at(piezas.size() - 1);
            }

        }

    }


    int obtener_elemento_mayoritario(std::vector<int> piezas) {

        int unCandidato = obtener_candidato(piezas);

        if (unCandidato == 0 || (apariciones(piezas, unCandidato) <= (piezas.size() / 2))) {
            return MAYORITARIO_NO_HALLADO;
        } else {
            return unCandidato;
        }

    }

}