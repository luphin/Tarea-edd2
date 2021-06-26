#include "TDA_Lista_Enlazada.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int Horner(tLista polinomio, int evaluar){
    if (polinomio.currPos() == (0)){
        return polinomio.getValue().coeficiente;
    } else {
        int b_n = polinomio.getValue().coeficiente;
        polinomio.prev();
        int b = b_n + (Horner(polinomio, evaluar) * evaluar);
        return b;
    };
};

int main(){
    fstream polinomios; 
    polinomios.open("entradaPolinomio.txt", ios::in);   //se abre el archivo
    if(!polinomios.is_open()){
        cerr << "Error al abrir el archivo\n";
        exit(1); 
    };
    int n_polinomios;
    polinomios >> n_polinomios; //se lee el numero de polinomios a establecer
    tLista* lista_Polinomios = new tLista[n_polinomios];    //arreglo de listas que contendran polinomios  

    for (int i = 0 ; i < n_polinomios ; i++){
        int n_monomios;
        polinomios >> n_monomios; //se lee el numero de monomios existentes en el polinomio actual
        for (int j = 0 ; j < n_monomios ; j++){
            int exp;
            int coef;
            monomio nuevo;
            polinomios >> exp; //se agrega el exponente del "x"
            polinomios >> coef; // se agrega el coeficiente
            nuevo.coeficiente = coef;
            nuevo.exponente = exp;
            lista_Polinomios[i].insert(nuevo); //se inserta el monomio
        };
    };
    fstream resultado;
    resultado.open("salidaPolinomio.txt", ios::out);
    string operacion, op_evaluar = "EVALUAR", op_coeficiente = "COEFICIENTE";
    while (!polinomios.eof()){ //se verifica que el archivo aun no termina
        polinomios >> operacion; //se lee la operacion a realizar
        if (operacion == op_evaluar){
            int posicion_Polinomio;
            float valor_Evaluar;
            polinomios >> posicion_Polinomio; //se ubican los valores necesarios en variables
            polinomios >> valor_Evaluar;
            lista_Polinomios[posicion_Polinomio].moveToEnd();
            float evaluado = Horner(lista_Polinomios[posicion_Polinomio], valor_Evaluar); //se ejecuta el algoritmo de horner para evaluar
            resultado << evaluado; //se escribe la solucion en el archivo de respuesta
            resultado << "\n";
        };
        if (operacion == op_coeficiente){
            int num_polinomio;
            int valor_ext;
            polinomios >> num_polinomio;
            polinomios >> valor_ext; //exponente que se pide
            lista_Polinomios[num_polinomio].moveToStart(); 
            while (lista_Polinomios[num_polinomio].getValue().exponente != valor_ext){
                lista_Polinomios[num_polinomio].next(); //mover a la posicion del polinomio requerido
            }; 
            int g = lista_Polinomios[num_polinomio].getValue().coeficiente; //busca el polinomio que se necesita, y su coeficiente 
            resultado << g; //se escribe la solucion en el archivo de respuesta
            resultado << "\n";
        };
    };
    resultado.close();
    polinomios.close();
    delete[](lista_Polinomios);
    return 0;
};