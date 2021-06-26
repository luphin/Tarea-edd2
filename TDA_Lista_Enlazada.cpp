struct monomio{
    int coeficiente;
    int exponente;
};

typedef monomio tElemLista; //era int, pero estoy probando algo para la 1

struct tNodo{
    tElemLista info;
    tNodo* sig;
};

class tLista {
    private:

        tNodo* head;
        tNodo* tail;
        tNodo* curr;
        unsigned int listSize;
        unsigned int pos; // posicion actual en la lista

    public:

        tLista();

        void clear();     // borra todos los elementos de la lista, reinicializándola vacía

        int insert(tElemLista item);         // inserta un elemento en la posición actual de la lista

        int append(tElemLista item);        // agrega un elemento al final de la lista

        tElemLista erase();        // borra el elemento actual y retorna su valor

        void moveToStart();        // mueve la posición actual al comienzo de la lista

        void moveToEnd();        // mueve la posición actual al final de la lista

        void next();        // mueve la posición actual al siguiente elemento de la lista. No produce cambios si está en la cola de la lista

        void prev();        // mueve la posición actual al elemento anterior de la lista. No produce cambios si está en la cabeza de la lista

        int length();        // retorna el número de elementos en la lista

        int currPos();        // retorna la posición del elemento actual

        void moveToPos(unsigned int pos);        // mueve la posición actual a una especificada

        tElemLista getValue();        // obtiene el valor del elemento actual de la lista
};

/*****
* tLista tLista
******
* Constructor de listas
******
* Input:
* No requiere input
* .......
******
* Returns:
* "Retorna" una nueva lista vacia
*****/
tLista::tLista() {
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
};

//----------------------O------------------------
/*****
* Void clear
******
* Elimina todos los elementos de la lista, dejandola vacia
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tLista::clear(){
    while (listSize != 0) {
        if (curr == head) {
            delete curr;
            listSize--;
        };
        tNodo* temp;
        temp = head;
        while (temp->sig != curr){
            temp = temp->sig;
        };
        delete curr;
        curr = temp;
    };
    head = tail = curr = new tNodo;
    pos = 0;
};

//----------------------O------------------------
/*****
* int insert
******
* Inserta un elemento en la posición actual en la lista
******
* Input:
* tElemLista item : El elemento a insertar en la lista
* .......
******
* Returns:
* int, La posición actual de la variable "pos" en la lista
*****/
int tLista::insert(tElemLista item) {
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = aux;
    if (curr == tail) {
        tail = curr->sig;
    };
    listSize++;
    return pos;
};

//----------------------O------------------------
/*****
* int append
******
* Añade un elemento al final de la lista
******
* Input:
* tElemLista item : El elemento a añadir en la lista
* .......
******
* Returns:
* int, La posición actual de la variable "pos" en la lista
*****/
int tLista::append(tElemLista item){
    while (curr != tail) {
        curr = curr->sig;
    };
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = nullptr;
    tail = curr->sig;
    listSize++;
    return pos;
};

//----------------------O------------------------
/*****
* tELemLista erase
******
* Borra el elemento actual de la lista (donde estan "curr" y "pos"), retornando su valor
******
* Input:
* No requiere input
* .......
******
* Returns:
* tElemLista, El elemento recién eliminado
*****/
tElemLista tLista::erase(){
    tElemLista final;
    if (curr == head) {
        head = curr->sig;
        final = curr->info;
        delete curr;
        curr = head;
        listSize--;
        return final;
    };
    tNodo* temp;
    temp = head;
    while (temp->sig != curr){
        temp = temp->sig;
    };
    final = curr->info;
    temp->sig = curr->sig;
    delete curr;
    curr = temp;
    return final;
};

//----------------------O------------------------
/*****
* Void moveToStart
******
* Mueve los elementos "curr" y "pos" al inicio de la lista
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tLista::moveToStart() {
    curr = head; pos = 0; 
};

//----------------------O------------------------
/*****
* Void moveToEnd
******
* Mueve los elementos "curr" y "pos" a la cola de la lista
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tLista::moveToEnd() {
    curr = tail; 
    pos = listSize;
};

//----------------------O------------------------
/*****
* Void prev
******
* Mueve los elementos "curr" y "pos" a la posicion anterior en la lista
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tLista::prev() {
    tNodo* temp;
    if (curr == head) return;
    temp = head;
    while (temp->sig != curr) temp = temp->sig;
    curr = temp;
    pos--;
};

//----------------------O------------------------
/*****
* Void next
******
* Mueve los elementos "curr" y "pos" a la posición siguiente en la lista
******
* Input:
* No requiere input
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tLista::next() {
    if (curr != tail) {
        curr = curr->sig; pos++; 
    };
};

//----------------------O------------------------
/*****
* int length
******
* Retorna el tamaño actual de la lista
******
* Input:
* No requiere input
* .......
******
* Returns:
* int, El tamaño de la lista
*****/
int tLista::length(){
    return listSize;
};

//----------------------O------------------------
/*****
* int currPos
******
* Retorna la posición actual de la lista
******
* Input:
* No requiere input
* .......
******
* Returns:
* int, La posicion actual en la lista
*****/
int tLista::currPos(){
    return pos;
};

//----------------------O------------------------
/*****
* Void moveToPos
******
* Mueve los elementos "curr" y "pos" a una posicion especificada
******
* Input:
* unsigned int posicion : La posición a la que se moveran "curr" y "pos"
* .......
******
* Returns:
* Al ser una funcion void, no posee return
*****/
void tLista::moveToPos(unsigned int posicion) {
    unsigned int i;
    if (posicion < 0 || posicion > listSize) return;
    curr = head;
    pos = 0;
    for (i = 0; i < posicion; i++) {
        curr = curr->sig;
        pos++;
    };
};

//----------------------O------------------------
/*****
* tElemLista getValue
******
* Retorna el valor de la posición actual en la lista
******
* Input:
* No requiere input
* .......
******
* Returns:
* tElemLista, La información del elemento actual de la lista
*****/
tElemLista tLista::getValue(){
    return curr->info;
};

//-----------------O-----------------------------
