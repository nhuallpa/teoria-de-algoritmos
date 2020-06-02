#include"AlgoritmoA.h"

#include <vector>
namespace ProcesoA {

    const int ELEMENTO_NO_HALLADO = 0;

    int obtener_elemento_mayoritario(std::vector<int> piezas) {

        int volumenPieza = ELEMENTO_NO_HALLADO;
        int cantidadPiezasIguales = 0;

        for (auto indicePiezaActual = piezas.begin(); indicePiezaActual != piezas.end(); indicePiezaActual++) {
            volumenPieza = *indicePiezaActual;
            for (auto indiceOtraPieza = piezas.begin(); indiceOtraPieza != piezas.end(); indiceOtraPieza++) {
                if (indicePiezaActual != indiceOtraPieza &&  volumenPieza == *indiceOtraPieza) {
                    cantidadPiezasIguales++;
                }
            }

            if (cantidadPiezasIguales > piezas.size() / 2) {
               break;
            }
        }
        return volumenPieza;
    }

}
