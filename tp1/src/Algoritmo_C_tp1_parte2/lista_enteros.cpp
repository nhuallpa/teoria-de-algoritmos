#include"nodo_entero.h"
#include"lista_enteros.h"
#include<iostream>

using namespace std;

Lista_enteros::Lista_enteros () {

    primero = 0;
    ultimo = 0;
    tamanio = 0;

}

Lista_enteros::~Lista_enteros () {

    for (int i = 1; i <= tamanio; i++) {

        baja_primero();

    }

}

void Lista_enteros::alta_principio (int entrante) {

    if (tamanio == 0) {

        Nodo_entero* principio = new Nodo_entero(entrante);
        primero = principio;
        ultimo = principio;

    } else {

        Nodo_entero* nuevo_principio = new Nodo_entero(entrante);
        nuevo_principio -> asignar_siguiente(primero);
        primero = nuevo_principio;

    }

    tamanio++;
}

void Lista_enteros::alta_final (int entrante) {

    if (tamanio == 0) {

        Nodo_entero* nuevo_ultimo = new Nodo_entero(entrante);
        ultimo = nuevo_ultimo;
        primero = nuevo_ultimo;

    } else {

        Nodo_entero* nuevo_final = new Nodo_entero(entrante);
        ultimo -> asignar_siguiente(nuevo_final);
        ultimo = nuevo_final;

    }

    tamanio++;

}

void Lista_enteros::alta_posicion_determinada (int entrante, int posicion) {

    if (posicion == 1) {

        alta_principio(entrante);

    } else if (posicion == tamanio + 1) {

        alta_final(entrante);

    } else {

        Nodo_entero* anterior = 0;
        anterior -> asignar_siguiente(primero -> obtener_siguiente());

        for (int i = 1; i < posicion; i++) {

            anterior -> asignar_siguiente(anterior -> obtener_siguiente());

        }

        Nodo_entero* nueva_entrada = new Nodo_entero(entrante);
        nueva_entrada -> asignar_siguiente(anterior -> obtener_siguiente());
        anterior -> asignar_siguiente(nueva_entrada);

    }

    tamanio++;

}

void Lista_enteros::baja_primero () {

    if (tamanio == 1) {

        delete primero;

    } else {

        Nodo_entero* auxiliar = primero;
        primero = primero -> obtener_siguiente();
        delete auxiliar;

    }

    tamanio--;

}

//semiimplementado.

void Lista_enteros::baja_ultimo () {

    // En caso de que no funcione, completar lo comentado y descomentarlo.
    //Puede ser un problema por no asignarle nulo al siguiente del anterior al ultimo.
    /*if (tamanio == 1) {

        delete ultimo;

    } else {



    }*/
    delete ultimo;

    tamanio--;

}

void Lista_enteros::baja_posicion_determinada (int posicion) {

    if (posicion == 1) {

        baja_primero();

    } else if (posicion == tamanio) {

        baja_ultimo();

    } else {

        Nodo_entero* anterior = primero -> obtener_siguiente ();

        for (int i = 1; i < posicion; i++) {

            anterior = anterior -> obtener_siguiente();

        }

        Nodo_entero* a_eliminar = anterior -> obtener_siguiente();
        anterior -> asignar_siguiente(a_eliminar -> obtener_siguiente());
        delete a_eliminar;

    }

    tamanio--;

}

bool Lista_enteros::comparacion_igual (int buscado, int comparado) {

    return (buscado == comparado);
}

void Lista_enteros::baja_primer_buscado (int buscado) {

    Nodo_entero* auxiliar = primero;

    int i = 1;

    while (!(comparacion_igual(buscado, auxiliar -> obtener_dato())) && (i < tamanio)) {

        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }

    if (i != tamanio) {

        baja_posicion_determinada(i);

    } else if (comparacion_igual(buscado, ultimo -> obtener_dato())) {

        baja_ultimo();

    }

}

void Lista_enteros::baja_buscado (int buscado) {

    Nodo_entero* auxiliar = primero;

    int i = 1;

    while ((comparacion_igual(buscado, auxiliar -> obtener_dato())) && (i <= tamanio)) {  //Si el primero es el buscado repetidas veces

        baja_primero();
        auxiliar = primero;
        i++;

    }

    for (int j = 1; j <= tamanio; j++) {                            //Esta parte trabaja con dos nodos, ya que si trabajo con uno y lo borro, debería comenzar desde el principio cada vez.

        Nodo_entero* siguiente = auxiliar -> obtener_siguiente();
        if (comparacion_igual(buscado, siguiente -> obtener_dato())) {

            baja_posicion_determinada (j + 1);

        }
        if (j != tamanio)
            auxiliar = auxiliar -> obtener_siguiente();

    }

}

int Lista_enteros::obtener_primero () {

    return primero -> obtener_dato();
}

int Lista_enteros::obtener_ultimo () {

    return ultimo -> obtener_dato();
}

int Lista_enteros::obtener_buscado (int posicion) {

    int retorno = -1;

    if ((posicion == 1)) {

        return obtener_primero();

    } else if (posicion == tamanio) {

        return obtener_ultimo();

    } else {

        Nodo_entero* auxiliar = primero;

        for (int i = 1; i <= posicion; i++) {

            auxiliar = auxiliar -> obtener_siguiente();

        }

        retorno = auxiliar -> obtener_dato();

    }

    return retorno;
}


int Lista_enteros::obtener_buscado_v2(int posicion) {

    return obtener_buscado(posicion + 1);

}

int Lista_enteros::obtener_maximo () {

    Nodo_entero* auxiliar = primero;
    int maximo = auxiliar -> obtener_dato();

    for (int i = 1; i <= tamanio; i++) {

        auxiliar = auxiliar -> obtener_siguiente();
        if (maximo <= auxiliar -> obtener_dato())
            maximo = auxiliar -> obtener_dato();

    }

    return maximo;

}

int Lista_enteros::obtener_minimo () {

    Nodo_entero* auxiliar = primero;
    int minimo = auxiliar -> obtener_dato();

    for (int i = 1; i <= tamanio; i++) {

        auxiliar = auxiliar -> obtener_siguiente();
        if (minimo >= auxiliar -> obtener_dato())
            minimo = auxiliar -> obtener_dato();

    }

    return minimo;

}

int Lista_enteros::obtener_tamanio () {

    return tamanio;
}

int Lista_enteros::obtener_promedio () {

    Nodo_entero* auxiliar = primero;
    int promedio = auxiliar -> obtener_dato();

    for (int i = 1; i <= tamanio; i++) {

        auxiliar = auxiliar -> obtener_siguiente();
        promedio += auxiliar -> obtener_dato();

    }

    return promedio;

}

void Lista_enteros::mostrar_elemento (int elemento) {

    cout << elemento << endl;

}

void Lista_enteros::modificar_buscado (int posicion, int nuevo_valor) {

    if (posicion == 1) {

       primero -> asignar_dato(nuevo_valor);

    } else if (posicion == tamanio) {

        ultimo -> asignar_dato(nuevo_valor);

    } else {

        Nodo_entero* auxiliar = primero;

        for (int i = 1; i <= posicion; i++) {

            auxiliar = auxiliar -> obtener_siguiente();

        }

        auxiliar -> asignar_dato(nuevo_valor);
    }

}

void Lista_enteros::listar () {

    Nodo_entero* auxiliar = primero;

    for (int i = 1; i <= tamanio; i++) {

        mostrar_elemento(auxiliar -> obtener_dato());
        auxiliar = auxiliar -> obtener_siguiente();

    }

}

//Todavía no lo implementé

void Lista_enteros::listar_inverso () {


}




