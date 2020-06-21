#include "gtest/gtest.h"
#include <vector>
#include "ProcesoC/AlgoritmoC.h"

TEST(MayoritarioCFixture, SiLaCantidadElementosEsParYExisteUnMayoritarioSeEncuentra) {

    std::vector<int> piezas = {10,20,20,20,20,10};

    int mayoritario = ProcesoC::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(mayoritario, 20) << "El mayoritario tenia que ser el volumen 20";

}
TEST(MayoritarioCFixture, SiLaCantidadElementosEsParYNOExisteUnMayoritarioNOSeEncuentra) {

    std::vector<int> piezas = {10,20,30,20,20,10};

    int mayoritario = ProcesoC::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}

TEST(MayoritarioCFixture, SiLaCantidadElementosEsImparYExisteUnMayoritarioSeEncuentra) {

    std::vector<int> piezas = {10,10,20,20,20};

    int mayoritario = ProcesoC::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(mayoritario, 20) << "El mayoritario tenia que ser el volumen 20";

}

TEST(MayoritarioCFixture, SiLaCantidadElementosEsImParYNOExisteUnMayoritarioNOSeEncuentra) {

    std::vector<int> piezas = {10,20,30,20,40};

    int mayoritario = ProcesoC::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}


TEST(MayoritarioCFixture, SiLaCantidadElementosEsImParYNOExisteUnMayoritarioNOSeEncuentraEnPeorCaso) {

    std::vector<int> piezas = {10,20,30,40,50};

    int mayoritario = ProcesoC::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}
