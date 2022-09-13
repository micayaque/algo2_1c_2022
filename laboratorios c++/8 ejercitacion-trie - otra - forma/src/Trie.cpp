#include "Trie.h"

template <typename T>
string_map<T>::string_map(): raiz(NULL), _size(0) {}

template <typename T>
//string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() {
    string_map<T> copia;
    copia = aCopiar;
    *this = copia;
}

template<typename T>
void string_map<T>::valores(Nodo *nodo, vector<pair<string, T>> *valoresHastaAhora, string clave) const {
    if (nodo == NULL) return;
    for (int i = 0; i < nodo->siguientes.size(); ++i) {
        string siguienteClave = clave;
        siguienteClave.push_back(char(i));
        valores(nodo->siguientes[i], valoresHastaAhora, siguienteClave);
    }
    if (nodo->definicion != NULL) {
        valoresHastaAhora->emplace_back(make_pair(clave, *nodo->definicion));
    }
}

template <typename T>
vector<pair<string, T>> string_map<T>::trie_to_vec()const {
    vector<pair<string, T>> elementos;
    valores(raiz, &elementos, "");
    return elementos;
}

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    _size = 0;
    if (d.raiz == NULL) {
        raiz = NULL;
    } else {
        delete raiz;
        vector<pair<string, T>> valoresAAgregar;
        valores(d.raiz, &valoresAAgregar, "");
        raiz = new Nodo();
        for (pair<string, T> valor : valoresAAgregar) {
            insert(valor);
        }
    }
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    delete raiz;
}

template<typename T>
void string_map<T>::insert(const pair<string, T> &tupla) {
    if (raiz == NULL) {
        raiz = new Nodo();
    }
    string_map<T>::Nodo *nodo = raiz;
    for (char c: tupla.first) {
        Nodo *siguienteNodo = nodo->siguientes[int(c)];
        if (siguienteNodo == NULL) {
            siguienteNodo = new Nodo();
            nodo->siguientes[int(c)] = siguienteNodo;
        }
        nodo = siguienteNodo;
    }
    if (nodo->definicion == NULL) {
        _size++;
    } else {
        delete nodo->definicion;
    }
    nodo->definicion = new T(tupla.second);
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    if (raiz == NULL) {
        raiz = new Nodo();
    }
    string_map<T>::Nodo *nodo = raiz;
    for (char c: clave) {
        Nodo *siguienteNodo = nodo->siguientes[int(c)];
        if (siguienteNodo == NULL) {
            siguienteNodo = new Nodo();
            nodo->siguientes[int(c)] = siguienteNodo;
        }
        nodo = siguienteNodo;
    }
    if (nodo->definicion == NULL) {
        nodo->definicion = new T();
    }
    return *nodo->definicion;
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    string_map<T>::Nodo *nodo = raiz;
    for (int i = 0; i < clave.size() && nodo != NULL; ++i) {
        nodo = nodo->siguientes[int(clave[i])];
    }
    return nodo == NULL || nodo->definicion == NULL ? 0 : 1;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    string_map<T>::Nodo *nodo = raiz;
    for (char c: clave) {
        nodo = nodo->siguientes[int(c)];
    }
    return *nodo->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    string_map<T>::Nodo *nodo = raiz;
    for (char c: clave) {
        nodo = nodo->siguientes[int(c)];
    }
    return *nodo->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    stack < Nodo * > pila;
    string_map<T>::Nodo *nodo = raiz;
    for (char c: clave) {
        pila.push(nodo);
        nodo = nodo->siguientes[c];
    }
    if (nodo->tieneSiguiente()) {
        delete nodo->definicion;
        nodo->definicion = NULL;
    } else {
        delete nodo;
        for (int i = clave.size() - 1; i >= 0; --i, pila.pop()) {
            pila.top()->siguientes[int(clave[i])] = NULL;
            if (pila.top()->tieneSiguiente()) {
                break;
            } else {
                delete pila.top();
                if (i == 0) {
                    raiz = NULL;
                }
            }
        }
    }
    _size--;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template<typename T>
string_map<T>::Nodo::Nodo() : siguientes(256), definicion(NULL) {}

template<typename T>
string_map<T>::Nodo::~Nodo() {
    for (int i = 0; i < siguientes.size(); ++i) {
        Nodo *nodoABorrar = siguientes[i];
        if (nodoABorrar != NULL) delete nodoABorrar;
    }
    if (definicion != NULL) {
        delete definicion;
    }
}

template<typename T>
bool string_map<T>::Nodo::tieneSiguiente() {
    for (Nodo *nodo: siguientes) {
        if (nodo != NULL) {
            return true;
        }
    }
    return false;
}

template<typename T>
const map<string, T>& string_map<T>::trie_to_map() const {
    /*
    map<string, T> result;
    for(const auto &elem:this->trie_to_vec()) {
        result.insert(elem);
    }
    */
    auto* res = new map<string, T>;
    for(const auto &elem : this->trie_to_vec()) {
        res->insert(elem);
    }
    return *res;

}