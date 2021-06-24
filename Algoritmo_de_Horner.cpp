//Algoritmo de Horner
#include "TDA_Lista_Enlazada.cpp"

int Horner(tLista polinomio, int evaluar){
    tLista temp = polinomio; //se copia el valor del polinomio
    polinomio.moveToEnd();
    int b_n = polinomio.erase().coeficiente; //se obtiene y borra el valor del coeficiente de la expresion
    while (polinomio.length() != 0){
        b_n = polinomio.erase().coeficiente + (b_n * evaluar); //se suman los coeficientes anteriores con la multiplicacion correspondiente
    };
    polinomio = temp; //se restaura el valor original de polinomio 
    return b_n;
};