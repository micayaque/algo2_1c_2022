#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
  set<int> set_s;
  for(int i : s){
    set_s.insert(i);
  }
  vector<int> res;
  for(int i : set_s){
    res.push_back(i);
  }
  return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set_s;
    for(int i : s){
        set_s.insert(i);
    }
    vector<int> res;
    for(int i : set_s){
        res.push_back(i);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
  set<int> set_a;
  set<int> set_b;
  for(int i : a){
    set_a.insert(i);
  }
  for(int i : b){
    set_b.insert(i);
  }
  if(set_a==set_b){
    return true;
  } else{
    return false;
  }
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> set_a;
    set<int> set_b;
    for(int i : a){
        set_a.insert(i);
    }
    for(int i : b){
        set_b.insert(i);
    }
    if(set_a==set_b){
        return true;
    } else {
      return false;
    }
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
  map<int, int> cantidad_apariciones;
  for(int i : s){
    cantidad_apariciones[i]++;
  }
    return cantidad_apariciones;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
  vector<int> res;
  for(int i : s){
    if(contar_apariciones(s)[i]==1){
      res.push_back(i);
    }
  }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
  set<int> res;
  for(int i : a){
    if(b.count(i)==1){
      res.insert(i);
    }
  }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
  map<int, set<int>> res;
  for(int i : s){
    res[i % 10].insert(i);
  }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> dicc;
    for(pair<char, char> p : tr){
        dicc[p.first]=p.second;
    }
    vector<char> res;
    for(char c : str) {
        if (dicc.count(c) == 1) {
            res.push_back(dicc[c]);
        } else {
            res.push_back(c);
        }
    }
    return res;
}

// Ejercicio 10

bool integrantes_repetidos(vector<Mail> s) {
    map<LU, int> apariciones_lu;
  for(Mail m : s){
    for(LU l : m.libretas()){
      apariciones_lu[l]++;
    }
  }
  bool res = false;
  for(pair<LU, int> p : apariciones_lu){
    if(p.second>1){
        res = true;
      }
  }
    return res;
}

// Ejercicio 11

map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    vector<Mail> mails_con_adjunto;
    for(Mail m : s){
        if(m.adjunto()){
            mails_con_adjunto.push_back(m);
        }
    }
    map<set<LU>, set<Mail>> lu_mails;
    for(Mail m : mails_con_adjunto){
      lu_mails[m.libretas()].insert(m);
    }
    map<set<LU>, Mail> res;
    for(pair<set<LU>, set<Mail>> p : lu_mails){
        Fecha maxima = p.second.begin()->fecha();
        for(Mail m : p.second){
            if(maxima < m.fecha()){
                maxima = m.fecha();
                res[p.first]=m;
            }
        }
    }
    return res;
}