#include "TDA_Lista_Enlazada.cpp"
#include "Algoritmo_de_Horner.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

float evaluador(tLista polinomio, float evaluar){
    return Horner(polinomio, evaluar);
}

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

    fstream resultado;
    resultado.open("salidaPolinomio.txt", ios::out);
    string operacion, evaluar = "EVALUAR", coeficiente = "COEFICIENTE";
    while (operacion != "EOF"){ //se verifica que el archivo aun no termina
        polinomios.read((char*)&operacion, sizeof(char)); //se lee la operacion a realizar
        if (operacion == evaluar){
            int posicion_Polinomio;
            float valor_Evaluar;
            polinomios.read((char*)&posicion_Polinomio, sizeof(int)); //se ubican los valores necesarios en variables
            polinomios.read((char*)&valor_Evaluar, sizeof(float));
            float evaluado = evaluador(lista_Polinomios[posicion_Polinomio], valor_Evaluar);
            resultado.write((char*)&evaluado, sizeof(float)); //se escribe la solucion en el archivo de respuesta
        };
        if (operacion == coeficiente){
            int num_polinomio;
            int valor_ext;
            polinomios.read((char*)&num_polinomio, sizeof(int));
            polinomios.read((char*)&valor_ext, sizeof(int));
            int g_a = valor_ext - 1; //exponente que se pide menos 1 
            int g = lista_Polinomios[num_polinomio][g_a]; //busca el polinomio que se necesita 
            int g_b = g.exponente //busca el exponente dentro del polinomio
            resultado.write((char*)&g_b, sizeof(int)); //se escribe la solucion en el archivo de respuesta
        };
    };
    resultado.close();
    polinomios.close();
    return 0;
};