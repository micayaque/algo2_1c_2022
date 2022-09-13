#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1
class Rectangulo {
    public:
        uint alto();
        uint ancho();
        float area();
        Rectangulo(uint alto, uint ancho);


    private:
        uint alto_;
        uint ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho)  {
}

uint Rectangulo::alto() {
    // Completar
    return this->alto_;
}

uint Rectangulo::ancho() {
    return this->ancho_;
}

float Rectangulo::area() {
    return alto_ * ancho_;
}
// Ejercicio 2

// Clase Elipse

class Elipse {
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();
        float PI = 3.14;

    private:
        uint r_a_;
        uint r_b_;
};

Elipse::Elipse(uint a, uint b) : r_a_(a), r_b_(b){

}

uint Elipse::r_a() {
    return this->r_a_;
}

uint Elipse::r_b() {
    return this->r_b_;
}

float Elipse::area() {
    return PI * this->r_a_ * this->r_b_;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    // Completar
    return this->r_.alto();
}

float Cuadrado::area() {
    return this->r_.alto() * this->r_.ancho();
}

// Ejercicio 4

// Clase Circulo

class Circulo {
    public:
        Circulo(uint radio);
        uint radio();
        float area();

    private:
        Elipse e_;
        float PI = 3.14;
};

Circulo::Circulo(uint radio) : e_(radio, radio){}

uint Circulo::radio() {
    return this->e_.r_a();
}

float Circulo::area() {
    return this->e_.r_a() * this->e_.r_a() * PI ; 
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho()<< ")";
    return os;
}

// ostream Elipse

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6

ostream& operator<<(ostream& os, Cuadrado cu) {
    os << "Cuad(" << cu.lado() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo ci) {
    os << "Circ(" << ci.radio() << ")";
    return os;
}