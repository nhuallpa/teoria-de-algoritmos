#include "gtest/gtest.h"
#include <vector>
#include "ProcesoB/AlgoritmoB.h"

TEST(MayoritarioBFixture, SiLaCantidadElementosEsParYExisteUnMayoritarioSeEncuentra) {

    std::vector<int> piezas = {10,20,20,20,20,10};

    int mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(mayoritario, 20) << "El mayoritario tenia que ser el volumen 20";

}
TEST(MayoritarioBFixture, SiLaCantidadElementosEsParYNOExisteUnMayoritarioNOSeEncuentra) {

    std::vector<int> piezas = {10,20,30,20,20,10};

    int mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}

TEST(MayoritarioBFixture, SiLaCantidadElementosEsImparYExisteUnMayoritarioSeEncuentra) {

    std::vector<int> piezas = {10,10,20,20,20};

    int mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(mayoritario, 20) << "El mayoritario tenia que ser el volumen 20";

}

TEST(MayoritarioBFixture, SiLaCantidadElementosEsImParYNOExisteUnMayoritarioNOSeEncuentra) {

    std::vector<int> piezas = {10,20,30,20,40};

    int mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}


TEST(MayoritarioBFixture, SiLaCantidadElementosEsImParYNOExisteUnMayoritarioNOSeEncuentraEnPeorCaso) {

    std::vector<int> piezas = {10,20,30,40,50};

    int mayoritario = ProcesoB::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}
