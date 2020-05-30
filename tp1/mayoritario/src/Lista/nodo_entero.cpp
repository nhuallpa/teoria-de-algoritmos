#include"nodo_entero.h"

using namespace std;

Nodo_entero::Nodo_entero () {

    dato = 0;
    siguiente = 0;

}

Nodo_entero::Nodo_entero (int dato) {

    this -> dato = dato;
    siguiente = 0;

}

Nodo_entero::~Nodo_entero() {

    //delete siguiente;

}

void Nodo_entero::asignar_dato (int nuevo_dato) {

    dato = nuevo_dato;

}

int Nodo_entero::obtener_dato () {

    return dato;
}

void Nodo_entero::asignar_siguiente (Nodo_entero* nuevo_siguiente) {

    //Nodo_entero* aux = siguiente;
    siguiente = nuevo_siguiente;
    //delete aux;

}

Nodo_entero* Nodo_entero::obtener_siguiente () {

    return siguiente;
}
