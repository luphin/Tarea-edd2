#include "Algoritmo_de_Horner.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    monomio monomio1;
    monomio monomio2;
    monomio monomio3;
    monomio monomio4;
    monomio monomio5;
    monomio monomio6;
    tLista polinomio;
    monomio1.coeficiente = 2;
    monomio1.exponente = 0;
    monomio2.coeficiente = 0;
    monomio2.exponente = 1;
    monomio3.coeficiente = 8;
    monomio3.exponente = 2;
    monomio4.coeficiente = 4;
    monomio4.exponente = 3;
    monomio5.coeficiente = 18;
    monomio5.exponente = 4;
    monomio6.coeficiente = 0;
    monomio6.exponente = 5;
    polinomio.append(monomio1);
    polinomio.append(monomio2);
    polinomio.append(monomio3);
    polinomio.append(monomio4);
    polinomio.append(monomio5);
    polinomio.append(monomio6);
    polinomio.moveToStart();
    float evaluar = 5;
    float horner = Horner(polinomio, evaluar);
    cout << horner << endl;
    return 0;
};