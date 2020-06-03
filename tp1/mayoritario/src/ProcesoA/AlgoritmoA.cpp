#include"AlgoritmoA.h"
#include <vector>
namespace ProcesoA {

    const int ELEMENTO_NO_HALLADO = 0;

    int obtener_elemento_mayoritario(std::vector<int> piezas) {
        int volumenMayoritario = ELEMENTO_NO_HALLADO;
        for (auto indicePiezaActual = piezas.begin(); indicePiezaActual != piezas.end(); indicePiezaActual++) {
            float cantidadPiezasIguales = 0;
            int volumenPieza = *indicePiezaActual;

            for (auto indiceOtraPieza = piezas.begin(); indiceOtraPieza != piezas.end(); indiceOtraPieza++) {
                if (volumenPieza == *indiceOtraPieza) {
                    cantidadPiezasIguales++;
                }
            }

            if (cantidadPiezasIguales > (float)piezas.size() / 2) {
                volumenMayoritario = volumenPieza;
            }
        }
        return volumenMayoritario;
    }

}
