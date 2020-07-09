#include "gtest/gtest.h"
#include <vector>
#include "Producto/Producto.h"
#include "SeleccionadorProductos/SeleccionadorProductos.h"
using std::vector;
using std::map;

TEST(MaximaGananciaFixture, SiHayVariosProductosAElegirSeleccionarLosQueDenMayorGanancia) {

    Producto ninguno("", 0, 0);
    Producto maiz1("Maiz", 1, 500);
    Producto cebada1("Cebada", 1, 600);
    Producto cebada2("Cebada", 2, 400);
    Producto arroz2("Arroz", 2, 700);
    Producto trigo3("Trigo", 3, 600);

    std::vector<std::pair<string, string> >  restricciones;
    restricciones.emplace_back("Cebada", "Maiz");
    restricciones.emplace_back("Arroz", "Trigo");

    vector<Producto> productos = {ninguno, maiz1, cebada1, cebada2, arroz2, trigo3};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    vector<Producto> productosSelecionados = seleccionadorProductos.seleccionar();

    int gananciaMaxima = 0;
    for (const auto &producto : productosSelecionados) {
        gananciaMaxima += producto.getGanancia();
    }

    EXPECT_EQ(gananciaMaxima, 1500) << "No es la ganancia maxima, se espera 1600";

}

TEST(MaximaGananciaFixture, SiHayVariosProductosAElegirSeleccionarLosQueDenMayorGananciaOtroOrden) {

    Producto ninguno("", 0, 0);
    Producto maiz1("Maiz", 1, 500);
    Producto cebada1("Cebada", 1, 600);
    Producto cebada2("Cebada", 2, 400);
    Producto arroz2("Arroz", 2, 700);
    Producto trigo3("Trigo", 3, 100);


    std::vector<std::pair<string, string> >  restricciones;
    restricciones.emplace_back("Cebada", "Maiz");
    restricciones.emplace_back("Arroz", "Trigo");

    vector<Producto> productos = {ninguno, maiz1, cebada1, cebada2, arroz2, trigo3};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    vector<Producto> productosSelecionados = seleccionadorProductos.seleccionar();

    int gananciaMaxima = 0;
    for (const auto &producto : productosSelecionados) {
        gananciaMaxima += producto.getGanancia();
    }

    EXPECT_EQ(gananciaMaxima, 1300) << "No es la ganancia maxima, se espera 1300";

}



TEST(MaximaGananciaFixture, SiHayVariosProductosConMultiplesRetricciones) {

    Producto ninguno("", 0, 0);
    Producto cebada("Cebada", 1, 600);
    Producto maiz("Maiz", 1, 700);
    Producto pepino("Pepino", 2, 400);
    Producto arroz("Arroz", 2, 700);

    std::vector<std::pair<string, string> >  restricciones;
    restricciones.emplace_back("Maiz", "Arroz");
    restricciones.emplace_back("Cebada", "Arroz");
    restricciones.emplace_back("Maiz", "Pepino");


    vector<Producto> productos = {ninguno, cebada, maiz, pepino, arroz};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    vector<Producto> productosSelecionados = seleccionadorProductos.seleccionar();

    int gananciaMaxima = 0;
    for (const auto &producto : productosSelecionados) {
        gananciaMaxima += producto.getGanancia();
    }

    EXPECT_EQ(gananciaMaxima, 1000) << "No es la ganancia maxima, se espera 1300";

}

TEST(MaximaGananciaFixture, SiHayVariosProductosConMultiplesVerificoRestriciones) {

    Producto ninguno("", 0, 0);
    Producto cebada("Cebada", 1, 600);
    Producto maiz("Maiz", 1, 700);
    Producto pepino("Pepino", 2, 400);
    Producto arroz("Arroz", 2, 700);

    std::vector<std::pair<string, string> >  restricciones;
    restricciones.emplace_back("Maiz", "Arroz");
    restricciones.emplace_back("Cebada", "Arroz");
    restricciones.emplace_back("Maiz", "Pepino");

    vector<Producto> productos = {ninguno, cebada, maiz, pepino, arroz};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);

    ASSERT_TRUE(seleccionadorProductos.permiteSembrarSeguidos(cebada, pepino));
    ASSERT_FALSE(seleccionadorProductos.permiteSembrarSeguidos(cebada, arroz));
    ASSERT_FALSE(seleccionadorProductos.permiteSembrarSeguidos(maiz, arroz));
    ASSERT_FALSE(seleccionadorProductos.permiteSembrarSeguidos(maiz, pepino));
}


TEST(MaximaGananciaFixture, ConVariosProductosYRestriccionesContruirPosiblesAnterioresOK) {

    Producto ninguno("", 0, 0);
    Producto maiz1("Maiz", 1, 500);
    Producto cebada1("Cebada", 1, 600);
    Producto arroz2("Arroz", 2, 700);
    Producto cebada2("Cebada", 2, 400);
    Producto trigo3("Trigo", 3, 600);

    std::vector<std::pair<string, string> >  restricciones;
    restricciones.emplace_back("Cebada", "Maiz");
    restricciones.emplace_back("Arroz", "Trigo");

    vector<Producto> productos = {ninguno, maiz1, cebada1, cebada2, arroz2, trigo3};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    map<int, int> anteriores_posibles = seleccionadorProductos.calcularAnteriorePosibles();

    EXPECT_EQ(anteriores_posibles[5], 3) << "El anterior de Trigo trimestre 3 es Cebada del trimestre 2";
    EXPECT_EQ(anteriores_posibles[4], 2) << "El anterior de Arroz trimestre 2 es Cebada del trimestre 1";
    EXPECT_EQ(anteriores_posibles[3], 1) << "El anterior de Cebada trimestre 2 es Maiz del trimestre 1";
    EXPECT_EQ(anteriores_posibles[2], 0) << "El anterior de Cebada trimestre 1 es ninguno";
    EXPECT_EQ(anteriores_posibles[1], 0) << "El anterior de Maiz trimestre 1 es ninguno";

}


TEST(MaximaGananciaFixture, ConVariosProductosYVariasRestriccionesContruirPosiblesAnterioresOK) {


    Producto ninguno("", 0, 0);
    Producto cebada("Cebada", 1, 600);
    Producto maiz("Maiz", 1, 700);
    Producto pepino("Pepino", 2, 400);
    Producto arroz("Arroz", 2, 700);

    std::vector<std::pair<string, string> >  restricciones;
    restricciones.emplace_back("Maiz", "Arroz");
    restricciones.emplace_back("Cebada", "Arroz");
    restricciones.emplace_back("Maiz", "Pepino");

    vector<Producto> productos = {ninguno, cebada, maiz, pepino, arroz};
    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    map<int, int> anteriores_posibles = seleccionadorProductos.calcularAnteriorePosibles();

    EXPECT_EQ(anteriores_posibles[4], 0) << "El anterior de Arroz trimestre 2 es ninguno";
    EXPECT_EQ(anteriores_posibles[3], 1) << "El anterior de Pepino trimestre 2 es Cebada del trimestre 1";
    EXPECT_EQ(anteriores_posibles[2], 0) << "El anterior de Cebada trimestre 1 es ninguno";
    EXPECT_EQ(anteriores_posibles[1], 0) << "El anterior de Maiz trimestre 1 es ninguno";


}
