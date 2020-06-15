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

    vector<Producto> productosSelecionados = SeleccionadorProductos::seleccionarConMejorGanancia(productos);

    EXPECT_EQ(productosSelecionados.at(0).getGanancia(), 500) << "Con unico producto debe devolver su misma ganancia";

}

TEST(MaximaGananciaFixture, SiHayVariosProductosAElegirSeleccionarLosQueDenMayorGanancia) {

    Producto producto1("Maiz", 1, 500);
    Producto producto2("Cebada", 1, 600);
    Producto producto3("Arroz", 2, 700);
    Producto producto4("Cebada", 2, 400);
    Producto producto5("Trigo", 3, 600);

    map<string, string> restricciones;
    restricciones["Cebada"] = "Maiz";
    restricciones["Arroz"] = "Trigo";

    vector<Producto> productos = {producto1, producto2, producto3, producto3, producto4, producto5};

    vector<Producto> productosSelecionados = SeleccionadorProductos::seleccionarConMejorGanancia(productos);

    int gananciaMaxima = 0;
    for (const auto &producto : productosSelecionados) {
        gananciaMaxima += producto.getGanancia();
    }

    EXPECT_EQ(gananciaMaxima, 1600) << "No es la ganancia maxima, se espera 1600";

}