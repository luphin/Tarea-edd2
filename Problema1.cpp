#include "TDA_Lista_Enlazada.cpp"
#include "Algoritmo_de_Horner.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
    fstream polinomios; 
    polinomios.open("entradaPolinomio.txt", ios::in);   //se abre el archivo
    if(!polinomios.is_open()){
        cerr << "Error al abrir el archivo\n";
        exit(1); 
    };
    int n_polinomios;
    polinomios.read((char*)&n_polinomios, sizeof(int)); //se lee el numero de polinomios a establecer
    tLista* lista_Polinomios = new tLista[n_polinomios];    //arreglo de listas que contendran polinomios    

    for (int i = 0 ; i <= n_polinomios ; i++){
        int n_monomios;
        polinomios.read((char*)&n_monomios, sizeof(int)); //se lee el numero de monomios existentes en el polinomio actual
        for (int j = 0 ; j <= n_monomios ; j++){
            int exp;
            int coef;
            monomio nuevo;
            polinomios.read((char*)&exp, sizeof(int)); //se agrega el exponente del "x"
            polinomios.read((char*)&coef, sizeof(int)); // se agrega el coeficiente
            nuevo.coeficiente = coef;
            nuevo.exponente = exp;
            lista_Polinomios[i].moveToStart();
            while (lista_Polinomios[i].currPos() != exp){ //se revisa si el exponente concuerda con la posicion en la lista
                if (lista_Polinomios[i].currPos() == (lista_Polinomios[i].length()) - 1){
                    monomio vacio;
                    lista_Polinomios[i].insert(vacio); //si no lo hace, se llena con un "espacio vacio"
                };
                lista_Polinomios[i].next();
            };
            lista_Polinomios[i].insert(nuevo); //se inserta el monomio en la posicion correspondiente
        };
    };

    return 0;
};