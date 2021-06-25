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
    tLista* lista_Polinomios = new tLista[n_polinomios];

    for (int i = 0 ; i <= n_polinomios ; i++){
        tNodoArbolBin *arbol = nullptr;
        int n_monomios;
        polinomios.read((char*)&n_monomios, sizeof(int));
        for (int j = 0 ; j <= n_monomios ; j++){
            int exponente;
            int coeficiente;
            monomio nuevo;
            polinomios.read((char*)&exp, sizeof(int)); //se agrega el exponente del "x"
            polinomios.read((char*)&coef, sizeof(int)); // se agrega el coeficiente
            nuevo.coeficiente = coef;
            nuevo.exponente = exp;

            arbol.insert(nuevo);

        };
        lista_Polinomios[i].insert(arbol);
        lista_Polinomios.next();
    };

    fstream resultado;
    resultado.open("salidaPolinomio.txt", ios::out);
    string operacion, evaluar = "EVALUAR", coeficiente = "COEFICIENTE";
    while (operacion != "EOF"){ //se verifica que el archivo aun no termina
        polinomios.read((char*)&operacion, sizeof(char)); //se lee la operacion a realizar
        if (operacion == evaluar){
            int posicion_Polinomio;  //guarda posicion del polinomio    
            float valor_Evaluar;   //guarda valor con el que se va a a evaluar
            polinomios.read((char*)&posicion_Polinomio, sizeof(int)); //se ubican los valores necesarios en variables
            polinomios.read((char*)&valor_Evaluar, sizeof(float));
            
            //recorrer el archivo y cambiar las variables.


            resultado.write((char*)&evaluado, sizeof(float)); //se escribe la solucion en el archivo de respuesta
        };
        if (operacion == coeficiente){
            int num_polinomio; //guarad numero polinomio
            int valor_ext;  //gaurda valor a buscar 
            polinomios.read((char*)&num_polinomio, sizeof(int));  //asigna los valores del .txt
            polinomios.read((char*)&valor_ext, sizeof(int));
            lista_Polinomios.moveToPos(num_polinomio); //busca la posicion en la lista 
            lista_Polinomios.getValue().find(valor_ext);  //busca el valor dentro del arbol
            //verificar si esta bien porque hay que busca dentrod e cada nodo igual
            

            resultado.write((char*)&g_b, sizeof(float)); //se escribe la solucion en el archivo de respuesta
        };

    };
    resultado.close();   //cerrar los .txt abiertos
    polinomios.close();  
    delete lista_Polinomios;  //borra listas_Polinomios
    return 0;
};