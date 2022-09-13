using namespace std;

template<class T>
T cuadrado(T x) {
    return x * x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    bool res = false;
    int i=0;
    while(i < s.size()){
        if(s[i]==c){
            res = true;
        }
        i++;
    }
    return res;
}

//3

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    bool res = true;
    int i = 0;
    if(a.size() < b.size()) {
        while (i < a.size()) {
            if(a[i] != b[i]){
                res = false;
            }
            i++;
        }
    }
    return res && (a.size() < b.size());
}

//4

template<class Contenedor, class Elem>
Elem maximo(Contenedor c) {
    Elem max = c[0];
    for(int i=1; i<c.size() ; i++){
        if(max < c[i]){
            max = c[i];
        }
    }
    return max;
}