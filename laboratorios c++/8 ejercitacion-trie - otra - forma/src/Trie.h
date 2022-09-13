#ifndef TP3_ALGO2LANDIA_TRIE_H
#define TP3_ALGO2LANDIA_TRIE_H

#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
class string_map {
public:
    /**
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    string_map();

    /**
    CONSTRUCTOR POR COPIA
    * Construye un diccionario por copia.
    **/
    string_map(const string_map<T>& aCopiar);

    /**
    OPERADOR ASIGNACION
     */
    string_map& operator=(const string_map& d);

    /**
    DESTRUCTOR
    **/
    ~string_map();

    /**
    INSERT
    * Inserta un par clave, valor en el diccionario
    **/
    void insert(const pair<string, T>&);

    /**
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/

    int count(const string &clave) const;

    /**
    AT
    * Dada una clave, devuelve su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    -- Versión modificable y no modificable
    **/
    const T& at(const string& clave) const;
    T& at(const string& clave);

    /**
    ERASE
    * Dada una clave, la borra del diccionario junto a su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    **/
    void erase(const string& clave);

    /**
     SIZE
     * Devuelve cantidad de claves definidas */
    int size() const;

    /**
     EMPTY
     * devuelve true si no hay ningún elemento en el diccionario */
    bool empty() const;

    /** OPTATIVO
    * operator[]
    * Acceso o definición de pares clave/valor
    **/
    T &operator[](const string &clave);

    vector<pair<string, T>> trie_to_vec() const;
    const map<string, T>& trie_to_map() const;

private:

    struct Nodo {
        Nodo();
        ~Nodo();
        bool tieneSiguiente();
        vector<Nodo*> siguientes;
        T* definicion;
    };

    Nodo* raiz;
    int _size;
    void valores(Nodo*, vector<pair<string, T>>*, string) const;

};

//#include "Trie.cpp"

#endif //TP3_ALGO2LANDIA_TRIE_H
