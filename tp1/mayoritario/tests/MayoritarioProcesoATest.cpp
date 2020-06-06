#include "gtest/gtest.h"
#include <vector>
#include "ProcesoA/AlgoritmoA.h"

TEST(MayoritarioFixture, SiLaCantidadElementosEsParYExisteUnMayoritarioSeEncuentra) {

    std::vector<int> piezas = {10,20,20,20,20,10};

    int mayoritario = ProcesoA::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(mayoritario, 20) << "El mayoritario tenia que ser el volumen 20";

}
TEST(MayoritarioFixture, SiLaCantidadElementosEsParYNOExisteUnMayoritarioNOSeEncuentra) {

    std::vector<int> piezas = {10,20,30,20,20,10};

    int mayoritario = ProcesoA::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}

TEST(MayoritarioFixture, SiLaCantidadElementosEsImparYExisteUnMayoritarioSeEncuentra) {

    std::vector<int> piezas = {10,10,20,20,20};

    int mayoritario = ProcesoA::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(mayoritario, 20) << "El mayoritario tenia que ser el volumen 20";

}

TEST(MayoritarioFixture, SiLaCantidadElementosEsImParYNOExisteUnMayoritarioNOSeEncuentra) {

    std::vector<int> piezas = {10,20,30,20,40};

    int mayoritario = ProcesoA::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}

TEST(MayoritarioFixture, SiLaCantidadElementosEsImParYNOExisteUnMayoritarioNOSeEncuentraEnPeorCaso) {

    std::vector<int> piezas = {10,20,30,40,50};

    int mayoritario = ProcesoA::obtener_elemento_mayoritario(piezas);
    EXPECT_EQ(0, mayoritario) << "No tiene que haber elemento mayoritario";

}
