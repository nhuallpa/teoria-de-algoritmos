#ifndef ALGORITMOS_B_FUNCIONES_H_INCLUDED
#define ALGORITMOS_B_FUNCIONES_H_INCLUDED

using namespace std;

const int MAX_TAMANIO_VECTOR = 50; //Modificar según sea necesario.

/* Precondiciones de cargar_piezas:
 *
 * -El archivo con el volumen de las piezas debe encontrarse en el mismo directorio que el ejecutable del programa
 * -El archivo con el volumen de las piezas debe llamarse "piezas.txt"
 * -El archivo con el volumen de las piezas debe tener el formato presentado en la consigna del trabajo práctico 1
 * -El puntero a array de enteros "cargador_piezas" debe apuntar a un array de enteros válido y vacío.
 *
 * Postcondiciones de cargar pieza:
 *
 * -El vector al cual apunta "cargador_piezas" será cargado con la información de volumen presente en "piezas.txt"
 *
 */

int cargar_piezas (int cargador_piezas[]);

/* Precondiciones de asegurar_vector_completo:
 *
 * -Todas las variables en la firma de la función deben ser válidas.
 *
 * Postcondición:
 *
 * -Si el "vector_con_sobra" tiene espacio sobrante, elimina el espacio sobrante.
 *
 */
//Esta función asegura que si la carga deja espacio sobrante en el vector de carga, este espacio sea eliminado.

int* asegurar_vector_completo(int* vector_con_sobra, int tamanio_vector_lleno);

/* Precondiciones de obtener_elemento_mayoritario:
 *
 * -El puntero "referencia_piezas" debe apuntar a una Lista_enteros válida y cargada.
 *
 * Postcondiciones de obtener_elemento_mayoritario
 *
 * -Si existe un elemento mayoritario en la Lista_enteros a la que apunta "referencia_piezas", devuelve su volumen.
 * -Caso contrario, devuelve un valor inválido.
 *
 */

int obtener_elemento_mayoritario (int referencia_piezas[], int tamanio_piezas);

/* Precondiciones de mostrar_resultado:
 *
 * -"elemento_mayoritario" es una variable de tipo int válida
 * -"elemento_mayoritario" fue obtenido a partir de utilizar correctamente "obtener_elemento_mayoritario"
 *
 * Postcondiciones de mostrar_resultado:
 *
 * -Muestra en pantalla el resultado provocado por "elemento_mayoritario".
 *
 */

void mostrar_resultado(int elemento_mayoritario);

#endif
