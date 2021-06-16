typedef int tElemLista;

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

tLista::tLista() {
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
};

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

void tLista::moveToStart() {
    curr = head; pos = 0; 
    };

void tLista::moveToEnd() {
    curr = tail; 
    pos = listSize;
    };

void tLista::prev() {
    tNodo* temp;
    if (curr == head) return;
    temp = head;
    while (temp->sig != curr) temp = temp->sig;
    curr = temp;
    pos--;
};

void tLista::next() {
    if (curr != tail) {
        curr = curr->sig; pos++; 
    };
};

int tLista::length(){
    return listSize;
};

int tLista::currPos(){
    return pos;
};

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

tElemLista tLista::getValue(){
    return curr->info;
};
