#include "Diccionario.hpp"
#include <vector>

using namespace std;

template<class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> o) const;

private:
    Diccionario<T, int> _dicc;
};

template<class T>
Multiconjunto<T>::Multiconjunto(): _dicc() {}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if (_dicc.def(x)){
         _dicc.definir(x, _dicc.obtener(x) + 1);
    } else {
        _dicc.definir(x, 1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    if(_dicc.def(x)){
        return _dicc.obtener(x);
    } else {
        return 0;
    }
}

//9

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const{
    bool res = true;
    int i=0;
    while(i < _dicc.claves().size()){
        T clave = _dicc.claves()[i];
        if(!(this->ocurrencias(clave) <= otro.ocurrencias(clave))){
            res = false;
        }
        i++;
    }
    return res;
}