typedef int tipoElem;

struct tNodoArbolBin{
    tipoElem info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};

class tABB {
    private:

        tNodoArbolBin* raiz;
        int nElems;

    public:

        tABB();

        void clear();       // elimina todos los elementos de un ABB, dejándolo vacío

        void insert(tipoElem item);        // inserta un elemento “item” en el ABB

        void remove(tipoElem item);        // elimina un elemento “item” de un ABB

        int find(tipoElem item);        // busca un “item” en un ABB, retorna 0 en caso de no encontrarlo

        int size();        // cantidad de elementos en el árbol

        void inOrden();        // recorrido in-orden de un ABB

        void preOrden();        // recorrido pre-orden de un ABB

        void postOrden();        // recorrido post-orden de un ABB
};

/*****
* tABB
******
* Crea un ABB vacío
******
* Input:
* No requiere input
* .......
******
* Returns:
* 
*****/

tABB::tABB(){
    raiz = nullptr;
    nElems = 0;
};

//----------------------O------------------------

/*****
* Void clear
******
* Elimina los elementos del ABB
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/

void tABB::clear() {
    clearHelp(raiz);
    raiz = nullptr;
    nElems = 0;
};

void clearHelp(tNodoArbolBin *nodo) {
    if (nodo == nullptr) return; // árbol vacío, se detiene
    clearHelp(nodo->izq); // visita subárbol izquierdo recursivamente
    clearHelp(nodo->der); // visita subárbol derecho recursivamente
    delete nodo; // después de borrar subárboles, se borra a sí mismo
};

//----------------------O------------------------
/*****
* Void insert
******
* Inserta un elemento determinado en el ABB
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/

void tABB::insert(tipoElem item) {
    insertHelp(raiz, item);
    nElems++;
};

void insertHelp(tNodoArbolBin *nodo, tipoElem item) {
    if (nodo == nullptr) {
        nodo->info = item;
    } else {
        if (item < nodo->info) {
            insertHelp(nodo->izq, item);
        } else if(item > nodo->info) {
            insertHelp(nodo->der, item);
        };
    };
};
//----------------------O------------------------
/*****
* Void remove
******
* Elimina un tipoElem item del ABB
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tABB::remove(tipoElem item) {
    removeHelp(raiz, item);
    nElems--;
};

void removeHelp(tNodoArbolBin *nodo, tipoElem item) {

};

//----------------------O------------------------

/*****
* find
******
* Busca un 'tipoElem item' específico en el ABB
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
int tABB::find(tipoElem item) {
    return findHelp(raiz, item);
};
int findHelp(tNodoArbolBin *nodo, tipoElem item) {
    if (nodo == nullptr) {
        return 0;
    };
    if (nodo->info == item) {
        return 1;
    };
    if (item < nodo->info) {
        return findHelp(nodo->izq, item);
    } else {
        return findHelp(nodo->der, item);
    };
};
//----------------------O------------------------
/*****
* Funcion size
******
* Input:
* No requiere input
* .......
******
* Returns:
* Retorna el tamaño del arbol
*****/
int tABB::size() {
    return nElems;
};

//----------------------O------------------------
/*****
* Void inOrden
******
* Recorre inorden el ABB
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/

void tABB::inOrden () {
    inOrdenHelp (raiz);
};

void inOrdenHelp (tNodoArbolBin *nodo) {
    if (nodo == nullptr) return;
    inOrdenHelp (nodo->izq); // visita hijo izquierdo en in-orden
    procesar(nodo->info); // procesa nodo actual
    inOrdenHelp (nodo->der); // visita hijo derecho en in-orden
};

//----------------------O------------------------

/*****
* Void preOrden
******
* Recorre de manera preorden el ABB
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tABB::preOrden () {
    preOrdenHelp (raiz);
};

void preOrdenHelp (tNodoArbolBin *nodo) {
    if (nodo == nullptr) return;
    procesar(nodo->info); // procesa nodo actual
    preOrdenHelp (nodo->izq); // visita hijo izquierdo en in-orden
    preOrdenHelp (nodo->der); // visita hijo derecho en in-orden
};

//----------------------O------------------------

/*****
* Void postOrden
******
* Recorre de manera postorden el ABB
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tABB::postOrden () {
    postOrdenHelp (raiz);
};

void postOrdenHelp (tNodoArbolBin *nodo) {
    if (nodo == nullptr) return;
    postOrdenHelp (nodo->izq); // visita hijo izquierdo en in-orden
    postOrdenHelp (nodo->der); // visita hijo derecho en in-orden
    procesar(nodo->info); // procesa nodo actual
};

//----------------------O------------------------

void procesar(tipoElem info) {
    info;
};