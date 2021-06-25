//Algoritmo de Horner
#include "TDA_Lista_Enlazada.cpp"

int Horner(tLista polinomio, int evaluar){
    //tLista temp = polinomio;
    int b_n = polinomio.getValue().coeficiente;
    if (polinomio.currPos() == (polinomio.length() - 1)){
        return b_n;
    } else {
        polinomio.next();
        int b = b_n + (Horner(polinomio, evaluar) * evaluar);
        return b;
    };
};