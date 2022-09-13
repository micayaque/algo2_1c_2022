template <class T>
Conjunto<T>::Conjunto() {
    // Completar
    _raiz = nullptr;
	_cardinal = 0;
}

template <class T>
Conjunto<T>::Nodo::Nodo(const T &v) {
    valor = v, izq = nullptr, der = nullptr;
}

template <class T>
void Conjunto<T>::_destruir(Nodo* n) {
    if (n != nullptr) {
        _destruir(n->izq);
        _destruir(n->der);
        delete (n);
    }
}

    // Completar
template <class T>
Conjunto<T>::~Conjunto() { 
    _destruir(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* it = _raiz;
    bool res = false;
    while (it != nullptr && !res) {
        if (clave == it->valor) {
            res = true;
        } else {
            if (clave < it->valor) {
                it = it->izq;
            } else {
                it = it->der;
            }
        }
    }
    return res;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (!pertenece(clave)) {
        Nodo* padre = nullptr;
        Nodo *it = _raiz;
		if(_raiz==nullptr){
			_raiz=new Nodo(clave);
		} else {
			while (it != nullptr) {
				if (clave < it->valor) {
					padre = it;
					it = it->izq;
				} else {
					padre = it;
					it = it->der;
				}
			}
			Nodo* nuevo = new Nodo(clave);
				if(clave < padre->valor){
					padre->izq = nuevo;
				} else {
					padre->der = nuevo;
				}
			}
		_cardinal++;
	}
}

/*template<class T>
int Conjunto<T>::Nodo::contarNodos() {
    if (this == nullptr) {
        return 0;
    } else {
        return contarNodos(this->izq) + contarNodos(this->der) + 1;
    }
}
//Pre: existe
template<class T>
const T& Conjunto<T>::iesimo(int i) {
    return iesimoAux(_raiz, i);
}
template<class T>
const T& Conjunto<T>::iesimoAux(Conjunto::Nodo* raiz, int i) {
    int nodosIzq = raiz->izq.contarNodos();
    if (nodosIzq < i) {
        return iesimoAux(raiz->der, i - nodosIzq -1);
    } else if (nodosIzq == i) {
        return raiz->valor;
    } else {
        return iesimoAux(raiz->izq, i);
    }
}*/

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo** pn = &_raiz;
    while ((*pn)->valor != clave){
        if(clave < (*pn)->valor) {
            pn = &((*pn)->izq);
        } else {
            pn = &((*pn)->der);
        }
    }
    Nodo* n = *pn;
    if (n->izq == nullptr && n->der == nullptr){
        delete (*pn);
        *pn = nullptr;
    } else if (n->izq == nullptr || n->der == nullptr) {
        Nodo* nonull= nullptr;
        if(n->izq == nullptr){
             nonull = (*pn)->der;
        } else{
             nonull = (*pn)->izq;
        }
        delete (*pn);
        *pn = nonull;
    } else {
        Nodo** pred= &((*pn)->izq);
        while ((*pred)->der != nullptr){
            pred = &((*pred)->der);
        }
        Nodo* izqDePred = (*pred)->izq;
        (*pn)->valor = (*pred)->valor;
        delete (*pred);
        *pred = izqDePred;
    }
    _cardinal--;
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* n = _raiz;
    Nodo* padre = nullptr;
    while (n->valor != clave) {
        if (n->valor < clave) {
            padre = n;
            n = n->der;
        }
        if (n->valor > clave) {
            padre = n;
            n = n->izq;
        }
    } // ¿¿¿caso nodo sin hijos???
    if(n->der != nullptr) {
        n = n->der;
        while (n->izq != nullptr) {
            n = n->izq;
        }
    } else
        if(padre->valor > n->valor){
            n = padre;
        }
    return n->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* it = _raiz;
    while(it->izq != nullptr){
        it = it->izq;
    }
    return it->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* it = _raiz;
    while(it->der != nullptr){
        it = it->der;
    }
    return it->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
	
}