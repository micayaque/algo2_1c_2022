#include "vector"

template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    std::vector<Clave> claves() const;

private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {
}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

//8
template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave, Valor>::claves() const {

    //¿insertion sort?
    std::vector<Clave> c;

    int i = 0;
    while (i < _asociaciones.size()) {

        typename std::vector<Clave>::iterator it = c.begin();
        while (it != c.end() && *it <= _asociaciones[i].clave) {
            it++;
        }

        c.insert(it, _asociaciones[i].clave);
        i++;
    }

    return c;
}



    /*/1 ¿¿¿¿¿¿¿¿¿¿¿¿¿selection sort????????????????????
    std::vector<Clave> v1;
    std::vector<Clave> v2;
    for (int i = 0; i < _asociaciones.size(); i++) {
        v1.push_back(_asociaciones[i].clave);
    }
    //2 / 3
    while(v1.size()==0) {
        Clave minima = v1[0];
        for (int i = 1; i < v1.size(); i++) {
            if (v1[i] <= minima) {
                minima = v1[i];
            }
        }
        v2.push_back(minima);
        if(v1[v1.size() - 1] != minima) {
            Clave aux = v1[v1.size() - 1];
            v1[v1.size() - 1] = minima;
            minima = aux;
        }
        v1.pop_back();
    }
}*/