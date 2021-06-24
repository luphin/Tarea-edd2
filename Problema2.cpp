#include "TDA_Arbol_BB.cpp"
#include "Algoritmo_de_Horner.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    fstream polinomios; 
    polinomios.open("entradaPolinomio.txt", ios::in);
    if(!polinomios.is_open()){
        cerr << "Error al abrir el archivo\n";
        exit(1); 
    };
    int n_polinomios;
    polinomios.read((char*)&n_polinomios, sizeof(int));
    //Linea en que creamos los arboles para el manejo de elementos del problema
    //la verdad ni idea de como, pero ahi esta.

    for (int i = 0 ; i <= n_polinomios ; i++){
        int n_monomios;
        polinomios.read((char*)&n_monomios, sizeof(int));
        for (int j = 0 ; j <= n_monomios ; j++){
            int exponente;
            int coeficiente;
            //Linea donde se empiezan a almacenar los polinomios, un monomio a la vez
        };
    };

    return 0;
};