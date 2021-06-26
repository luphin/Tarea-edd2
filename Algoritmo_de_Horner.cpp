//Algoritmo de Horner
#include "TDA_Lista_Enlazada.cpp"

int Horner(tLista polinomio, int evaluar){   //se piden como datos iniciales la lista de polinomos y el dato a reempalzar
    //tLista temp = polinomio;
    int b_n = polinomio.getValue().coeficiente;  //toma el polinomio y retorna su valor, busca el coeficiente
    if (polinomio.currPos() == (polinomio.length() - 1)){  //Si se llego al final de la lista se retorna el valor almacenado en b_n
        return b_n;
    } else {
        polinomio.next();  //se cambia al siguiente valor de la lista 
        int b = b_n + (Horner(polinomio, evaluar) * evaluar);   //se agrega el valor y se suma con el de bucle al llamar a Horner()
        return b;  //retorna el valor de b 
    };
};

int HornerABB(tABB arbol, int evaluar){  //se piden como datos iniciales el arvol y el valor a reemplzar
    int cantidad = 1  //contador en 1 
    int b = arbol.inOrden().coeficiente;  //recore inOrden el arbol y se saca el valor del primer nodo
    if (cantidad == arbol.size()){ //si cantidad es slo mismo a el tamano del arbol
        return b; //retorna b 
    }else{
        arbol.remove();  //remuebe el nodo del arbol que se ocupo
        int bb = b + (HornerABB(arbol, evaluar)* evaluar); //se crea un bucle al llamar otra vez a HornetABB() para sumar otro valor
        return bb; //retorna bb
    }; 
};