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

int HornerABB(tABB arbol, int evaluar){
    int cantidad = 1;
    int b = arbol.inOrden().coeficiente;
    if (cantidad == arbol.size()){
        return b;
    }else{
        arbol.inOrden();
        int bb = b + (HornerABB(arbol, evaluar)* evaluar);
        return bb;
    }; 
};