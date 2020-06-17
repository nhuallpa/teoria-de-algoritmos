#include "gtest/gtest.h"
#include <vector>
#include "Producto/Producto.h"
#include "SeleccionadorProductos/SeleccionadorProductos.h"
using std::vector;
using std::map;
TEST(MaximaGananciaFixture, SiHayUnProductoAElegirLaGananciaEsDeEseProducto) {

    vector<Producto> productos;

    Producto producto("Maiz", 1, 500);
    productos.push_back(producto);
    map<string, string> restricciones;

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    vector<Producto> productosSelecionados = seleccionadorProductos.seleccionar();

    EXPECT_EQ(productosSelecionados.at(0).getGanancia(), 500) << "Con unico producto debe devolver su misma ganancia";

}

TEST(MaximaGananciaFixture, SiHayVariosProductosAElegirSeleccionarLosQueDenMayorGanancia) {

    Producto ninguno("", 0, 0);
    Producto maiz1("Maiz", 1, 500);
    Producto cebada1("Cebada", 1, 600);
    Producto cebada2("Cebada", 2, 400);
    Producto arroz2("Arroz", 2, 700);
    Producto trigo3("Trigo", 3, 600);

    map<string, string> restricciones;
    restricciones["Cebada"] = "Maiz";
    restricciones["Arroz"] = "Trigo";

    vector<Producto> productos = {ninguno, maiz1, cebada1, cebada2, arroz2, trigo3};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    vector<Producto> productosSelecionados = seleccionadorProductos.seleccionar();

    int gananciaMaxima = 0;
    for (const auto &producto : productosSelecionados) {
        gananciaMaxima += producto.getGanancia();
    }

    EXPECT_EQ(gananciaMaxima, 1600) << "No es la ganancia maxima, se espera 1600";

}

TEST(MaximaGananciaFixture, SiHayVariosProductosAElegirSeleccionarLosQueDenMayorGananciaOtroOrden) {

    Producto ninguno("", 0, 0);
    Producto maiz1("Maiz", 1, 500);
    Producto cebada1("Cebada", 1, 600);
    Producto cebada2("Cebada", 2, 400);
    Producto arroz2("Arroz", 2, 700);
    Producto trigo3("Trigo", 3, 100);

    map<string, string> restricciones;
    restricciones["Cebada"] = "Maiz";
    restricciones["Arroz"] = "Trigo";

    vector<Producto> productos = {ninguno, maiz1, cebada1, cebada2, arroz2, trigo3};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    vector<Producto> productosSelecionados = seleccionadorProductos.seleccionar();

    int gananciaMaxima = 0;
    for (const auto &producto : productosSelecionados) {
        gananciaMaxima += producto.getGanancia();
    }

    EXPECT_EQ(gananciaMaxima, 1300) << "No es la ganancia maxima, se espera 1300";

}





TEST(MaximaGananciaFixture, ConVariosProductosYRestriccionesContruirPosiblesAnterioresOK) {

    Producto ninguno("", 0, 0);
    Producto maiz1("Maiz", 1, 500);
    Producto cebada1("Cebada", 1, 600);
    Producto arroz2("Arroz", 2, 700);
    Producto cebada2("Cebada", 2, 400);
    Producto trigo3("Trigo", 3, 600);

    map<string, string> restricciones;
    restricciones["Cebada"] = "Maiz";
    restricciones["Arroz"] = "Trigo";

    vector<Producto> productos = {ninguno, maiz1, cebada1, arroz2, cebada2, trigo3};

    SeleccionadorProductos seleccionadorProductos(productos,restricciones);
    map<int, int> anteriores_posibles = seleccionadorProductos.calcularAnteriorePosibles();

    EXPECT_EQ(anteriores_posibles[5], 4) << "El anterior de Trigo trimestre 3 es Cebada del trimestre 2";
    EXPECT_EQ(anteriores_posibles[4], 2) << "El anterior de Cebada trimestre 2 es Cebada del trimestre 1";
    EXPECT_EQ(anteriores_posibles[3], 2) << "El anterior de Arroz trimestre 2 es Cebada del trimestre 1";
    EXPECT_EQ(anteriores_posibles[2], 0) << "El anterior de Cebada trimestre 1 es ninguno";
    EXPECT_EQ(anteriores_posibles[1], 0) << "El anterior de Maiz trimestre 1 es ninguno";

}
