#include "string_map.h"

template <typename T>
string_map<T>::string_map() : _size(0){
    raiz = new Nodo;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    borrar_siguientes(raiz);
    delete(raiz->definicion);

    int i = 0;
    for(const string clave : claves(d.raiz, "")){
        pair<string, T> elem;
        elem.first = clave;
        elem.second = d.at(clave);
        insert(elem);
    }
    return *this;
}

template <typename T>
const set<string> string_map<T>::claves() {
    const set<string> claves = claves(raiz, "");
    return claves;
}

template <typename T>
const set<string> string_map<T>::claves(Nodo* actual, string clave) {
    set<string> res;
    int i = 0;
    string c;
    if(actual->definicion != nullptr){
        res.insert(clave);
    }

    for(Nodo* sig : actual->siguientes){
        if(sig != nullptr){
            c = char(i);
            for(string cl : claves(sig, clave + c)){
                res.insert(cl);
            }
        }
        i++;
    }
    return res;
}

template <typename T>
string_map<T>::~string_map(){
    borrar_siguientes(raiz);
    delete(raiz);
}

template<typename T>
string_map<T>::Nodo::~Nodo() {
    delete(definicion);
    definicion = nullptr;
    for(int i=0; i<siguientes.size(); i++){
        if(siguientes[i] != nullptr){
            siguientes[i] = nullptr;
        }
    }

}

template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* nodo_actual = raiz;
    for(int i=0; i<clave.length(); i++){
        int idx = int(clave[i]);
        if((nodo_actual->siguientes)[idx] == nullptr){
            return 0;
        }
        else{
            nodo_actual = nodo_actual->siguientes[idx];
        }
    }
    if(nodo_actual->definicion == nullptr){
        return 0;
    }
    else{
        return 1;
    }

}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* nodo_actual = raiz;
    for(int i=0; i<clave.length(); i++){
        int idx = int(clave[i]);
        nodo_actual = nodo_actual->siguientes[idx];
    }
    return *(nodo_actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* nodo_actual = raiz;
    int idx;
    for(int i=0; i<clave.length(); i++){
        idx = int(clave[i]);
        nodo_actual = nodo_actual->siguientes[idx];
    }
    return *(nodo_actual->definicion);
}

template<typename T>
void string_map<T>::insert(const pair<string, T> &tupla) {
    string clave = tupla.first;
    T valor = tupla.second;
    Nodo* actual = raiz;
    for(int i=0; i<clave.size(); i++){
        int letra = int(clave[i]);
        if(actual->siguientes[letra] == nullptr){
            actual->siguientes[letra] = new Nodo();
        }
        actual = actual->siguientes[letra];
    }
    if(actual->definicion == nullptr){
        _size++;
    }else{
        delete(actual->definicion);
    }
    actual->definicion = new T(valor);
}

template <typename T>
void string_map<T>::borrar_siguientes(Nodo* actual) {
    for(Nodo* sig : actual->siguientes){
        if(sig != nullptr){
            borrar_siguientes(sig);
            delete(sig);
        }
    }
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = raiz;
    Nodo* anterior;
    bool act_no_tiene_siguientes, ant_no_tiene_siguientes;
    bool no_tiene_definicion;
    int letra;
    for(int i=0; i<clave.length(); i++){
        letra = int(clave[i]);
        anterior = actual;
        actual = actual->siguientes[letra];
    }
    act_no_tiene_siguientes = true;
    for(Nodo* sig : actual->siguientes){
        if(sig != nullptr){
            act_no_tiene_siguientes = false;
        }
    }
    if(actual->definicion != nullptr) {
        _size -= 1;
    }
    if(actual != raiz){
        no_tiene_definicion = true;
        no_tiene_definicion = anterior->definicion == nullptr;
        if(no_tiene_definicion){
            ant_no_tiene_siguientes = true;
            for(Nodo* sig : anterior->siguientes){
                if(sig != nullptr && sig != actual){
                    ant_no_tiene_siguientes = false;
                }
            }
            if(ant_no_tiene_siguientes && actual != raiz){
                erase(clave.substr(0, clave.size() - 1));

            }
        }
        if(act_no_tiene_siguientes){
            (anterior->siguientes)[letra] = nullptr;
            delete(actual);
        }
        else{
            delete(actual->definicion);
            actual->definicion = nullptr;
        }
    }
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}