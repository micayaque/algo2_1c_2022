#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado

//1   //8

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c) {
    typename Contenedor::const_iterator res = c.begin();
    for(typename Contenedor::const_iterator it = c.begin(); it != c.end() ; it++){
        if(*it < *res){
            res = it;
        }
    }
        return *res;
}

//2

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::value_type suma = 0;
    int longitud = 0;
    for(typename Contenedor::const_iterator it = c.begin(); it != c.end() ; it++){
            suma += *it;
            longitud++;
        }
    return suma / longitud;
}

//3

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    Iterator res = desde;
    for(Iterator it = desde; it != hasta; it++){
        if(*it < *res){
            res = it;
        }
    }
    return *res;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    double suma = 0;
    int longitud = 0;
    for(Iterator it = desde; it != hasta; it++){
        suma += *it;
        longitud++;
    }
    return suma / longitud;
}

//4 ¿qué pasa con borrar it?

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem) {
    typename Contenedor::iterator it = c.begin();
    while(it != c.end()){
        if(*it==elem){
            it=c.erase(it);
        } else {
            ++it;
        }

    }
}

//5

template<class Contenedor>
bool ordenado(Contenedor &c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::const_iterator end = --c.end();
    bool res = true;
    while (it != end) {
        if (!(*it < *(++it))){
            res = false;
        }
    }
    return res;
}

//6

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem){
    std::pair<Contenedor, Contenedor> res;
    for(typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it){
        if(*it < elem){
            res.first.insert(res.first.end() , *it);
        } else {
            res.second.insert(res.second.end(), *it);
        }
    }
    return res;
}

//7

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    typename Contenedor::const_iterator it_1 = c1.begin();
    typename Contenedor::const_iterator it_2= c2.begin();
    while(it_1 != c1.end() && it_2 != c2.end()){
        if(*it_1 < *it_2){
            res.insert(res.end(), *it_1);
            ++it_1;
        } else {
            res.insert(res.end(), *it_2);
            ++it_2;
        }
    }
    if(it_2 == c2.end()){
        while(it_1 != c1.end()){
            res.insert(res.end(), *it_1);
            ++it_1;
        }
    } else {
        while(it_2 != c2.end()){
            res.insert(res.end(), *it_2);
            ++it_2;
        }
    }
}


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
