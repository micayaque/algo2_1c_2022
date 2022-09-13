#include "Lista.h"

Lista::Lista() : primero_(), ultimo_(), longitud_(0) {
    primero_ = nullptr;
    ultimo_ = nullptr;
} // Completar

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::Nodo::Nodo(const int &elem) : valor(), siguiente(), anterior() {
    valor = elem;
    siguiente = nullptr;
    anterior = nullptr;
}

Lista::~Lista() {
    // Completar
    destruir_();
}

void Lista::destruir_() {
    Nodo *temp = this->primero_;
    while (temp != nullptr) {
        temp = temp->siguiente;
        delete (primero_);
        primero_ = temp;
        longitud_--;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    destruir_();
    int n = aCopiar.longitud_;
    if (n == 1) {
        primero_ = new Nodo((aCopiar.primero_)->valor);
        ultimo_ = primero_;
        longitud_++;
    } else if (n > 1) {
        primero_ = new Nodo((aCopiar.primero_)->valor);
        ultimo_ = primero_;
        longitud_++;
        Nodo *actual = (aCopiar.primero_)->siguiente;
        while (actual != nullptr) {
            agregarAtras(actual->valor);
            actual = actual->siguiente;
        }
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
	Nodo* nuevo = new Nodo(elem);
	if(longitud_==0){
		primero_=nuevo;
		ultimo_=nuevo;
	} else {
		//nuevo->anterior=nullptr;
		nuevo->siguiente=primero_;
		primero_->anterior=nuevo;
		primero_=nuevo;
	}
    longitud_++;
}

void Lista::agregarAtras(const int& elem) {
    // Completar
	Nodo* nuevo = new Nodo(elem);
	if(longitud_==0){
		primero_=nuevo;
		ultimo_=nuevo;
	} else {
		nuevo->anterior=ultimo_;
		ultimo_->siguiente=nuevo;
		ultimo_=nuevo;
	}
    longitud_++;
}

void Lista::eliminar(Nat i) { // Completar
	if(longitud_ == 1){
        delete(primero_);
        primero_ = nullptr;
        ultimo_ = nullptr;
    } else {
        if(i == 0){
            Nodo* eliminado = primero_;
            primero_ = primero_->siguiente;
            delete(eliminado);
        } else if(i == longitud_ - 1){
            Nodo* eliminado = ultimo_;
            ultimo_ = ultimo_->anterior;
            delete(eliminado);
        } else {
            Nodo *eliminado = primero_;
            for (int j = 0; j < i; j++){
                eliminado = eliminado->siguiente;
			}
            (eliminado->anterior)->siguiente = eliminado->siguiente;
            (eliminado->siguiente)->anterior = eliminado->anterior;
            delete (eliminado);
        }
    }
    longitud_--;
}

int Lista::longitud() const {
    // Completar
    return this->longitud_;

}

const int& Lista::iesimo(Nat i) const {
    // Completar
        Nodo* actual = primero_;
        for (int j = 0; j < i; j++) {
            actual = actual->siguiente;
        }
        return actual->valor;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* actual = primero_;
    for(int j=0;j<i;j++){
		actual=actual->siguiente;
	}
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
