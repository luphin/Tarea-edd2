#include "TDA_Lista_Enlazada.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct monomio{
    int coeficiente;
    int exponente;
};

int main(){
    fstream polinomios; 
    polinomios.open("entradaPolinomio.txt", ios::in);
    if(!polinomios.is_open()){
        cerr << "Error al abrir el archivo\n";
        exit(1); 
    };
    int n_polinomios;
    polinomios.read((char*)&n_polinomios, sizeof(int));
    tLista* lista_Polinomios = new tLista[n_polinomios];

    for (int i = 0 ; i <= n_polinomios ; i++){
        int n_monomios;
        polinomios.read((char*)&n_monomios, sizeof(int));
        for (int j = 0 ; j <= n_monomios ; j++){
            int exp;
            int coef;
            monomio nuevo;
            polinomios.read((char*)&exp, sizeof(int));
            polinomios.read((char*)&coef, sizeof(int));
            nuevo.coeficiente = coef;
            nuevo.exponente = exp;
            lista_Polinomios[i].append(nuevo);
        };
    };

    return 0;
};