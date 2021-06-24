//Algoritmo de Horner
#include "TDA_Lista_Enlazada.cpp"

int Horner(tLista polinomio, int evaluar){
    tLista temp = polinomio;
    polinomio.moveToEnd();
    int b_n = polinomio.erase().coeficiente;
    while (polinomio.length() != 0){
        b_n = polinomio.erase().coeficiente + (b_n * evaluar);
    };
    polinomio = temp;
    return b_n;
};