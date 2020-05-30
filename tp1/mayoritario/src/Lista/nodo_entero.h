#ifndef NODO_ENTERO_H_INCLUDED
#define NODO_ENTERO_H_INCLUDED

class Nodo_entero {

    private:

        //Atributos.

        int dato;
        Nodo_entero* siguiente;

    public:

        //Métodos.

        //Constructor sin parámetros.
        /* Post: Inicializa un Nodo_entero nulo.
         */
        Nodo_entero ();

        //Constructor con dato.
        /* Pre: dato es un int válido.
         * Post: Inicializa el Nodo_entero con el valor de dato.
         */
        Nodo_entero (int dato);

        //Destructor.
        virtual ~Nodo_entero();

        /* Pre: nuevo_dato es un int válido.
         * Post: Cambia el valor de dato por el de nuevo_dato.
         */
        void asignar_dato (int nuevo_dato);

        /* Post: Devuelve el dato.
         */
        int obtener_dato ();

        /* Pre: nuevo_siguiente es un puntero a Nodo_entero válido.
         * Post: Cambia siguiente por nuevo_siguiente.
         */
        void asignar_siguiente (Nodo_entero* nuevo_siguiente);

        /* Post: Devuelve siguiente.
         */
        Nodo_entero* obtener_siguiente ();

};

#endif
