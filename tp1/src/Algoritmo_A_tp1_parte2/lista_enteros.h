#ifndef LISTA_ENTEROS_H_INCLUDED
#define LISTA_ENTEROS_H_INCLUDED

#include"nodo_entero.h"

class Lista_enteros {

    private:

        Nodo_entero* ultimo;
        Nodo_entero* primero;
        int tamanio;

        //Métodos privados

        bool comparacion_igual (int buscado, int comparado);
        void mostrar_elemento (int elemento);

    public:

        //Constructor.
        /* Post: Inicializa la Lista_enteros como nula.
         */
        Lista_enteros ();

        //Destructor.
        /* Pre: Lista_enteros no vacía.
         * Post: Libera el espacio ocupado por la Lista_enteros.
         */
        ~Lista_enteros ();

        //Altas.

        /* Pre: entrante es un int válido.
         * Post: Introduce a entrante al principio de la lista.
         */
        void alta_principio (int entrante);

        /* Pre: entrante es un int válido.
         * Post: Introduce a entrante a lo último de la lista.
         */
        void alta_final (int entrante);

        /* Pre: entrante es un int válido.
         *      posicion es un int válido.
         *      posicion no es mayor a tamanio + 1;
         * Post: Introduce a entrante en Lista_enteros en la posicion.
         */
        void alta_posicion_determinada (int entrante, int posicion);

        //Bajas.

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Elimina el primer elemento de la Lista_enteros.
         */
        void baja_primero ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Elimina el último elemento de Lista_enteros.
         */
        void baja_ultimo ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         *      posicion es un int válido.
         *      posicion no es mayor a tamanio.
         * Post: Elimina el elemento de Lista_enteros en posicion;
         */
        void baja_posicion_determinada (int posicion);

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         *      buscado esta en Lista_enteros.
         * Post: Elimina el primer elemento de Lista_enteros con el valor buscado.
         */
        void baja_primer_buscado (int buscado);

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         *      buscado está en Lista_enteros.
         * Post: Elimina todos los elementos de Lista_enteros con el valor buscado.
         */
        void baja_buscado (int buscado);

        //Obtener.

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Devuelve el primer elemento de Lista_enteros.
         */
        int obtener_primero ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Devuelve el último elemento de Lista_enteros.
         */
        int obtener_ultimo ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         *      posicion es un int válido.
         *      posicion no es mayor a tamanio.
         * Post: Devuelve el elemento en posicion de Lista_enteros.
         */
        int obtener_buscado (int posicion);

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Devuelve el máximo elemento de Lista_enteros.
         */
        int obtener_maximo ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Devuelve el mínimo elemento de Lista_enteros.
         */
        int obtener_minimo ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Devuelve el valor de tamanio.
         */
        int obtener_tamanio ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Devuelve el promedio de los elementos de la lista.
         */
        int obtener_promedio ();

        //Mostrar

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0)
         * Post: Muestra todos los elementos de Lista_enteros de primero a ultimo.
         */
        void listar ();

        /* Pre: Lista_enteros no vacía (tamanio es mayor a 0).
         * Post: Muestra todos los elementos de Lista_enteros de ultimo a primero.
         */
        void listar_inverso ();

};

#endif
