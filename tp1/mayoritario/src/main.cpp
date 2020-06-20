// TODO: AGREGAR TEST
// TODO: Agregar getopt para obtener el tipo de proceso y el archivo a procesar (Listo)
// TODO: Separar la lectura del archivo del algoritmo (Listo en A)
// TODO: Cambiar por listas de STL en PROCESO A (Listo)
// TODO: Cambiar por listas de STL en PROCESO B
// TODO: Cambiar por listas de STL en PROCESO C
// TODO: manejar excepciones  (Listo)
// TODO: Refactor de nombres de metodos y archivos (Casi)
// TODO: Validaciones y help usage para la ejecución por linea de comando (Listo)
// TODO: Docuementar en readme

#include <SistemaMayoritario/SistemaMayoritario.h>

int main(int argc, char* argv[]) {
    SistemaMayoritario sistemaMayoritario;
    sistemaMayoritario.ejecutar(argc, argv);
}

