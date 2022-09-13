#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones

    Fecha(int mes, int dia);
    int mes();
    int dia();

    void incrementar_dia();

    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    //Completar miembros internos
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {} ;

int Fecha::mes() {
  return this->mes_;
}

int Fecha::dia() {
  return this->dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

void Fecha::incrementar_dia() {
    if (dia_ < dias_en_mes(mes_)) {
        dia_++;
    } else {
    if (mes_==12){
      mes_=1;
      dia_=1;
    } else{
            dia_=1;
            mes_++;
        }
    }      
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia() && this->mes() == o.mes();
    // Completar iguadad (ej 9)
    return igual_dia;
}
#endif

// Ejercicio 11, 12

// Clase Horario

class Horario{
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator<(Horario h);

private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {
};

uint Horario::hora(){
    return hora_;
}

uint Horario::min(){
    return min_;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator<(Horario h) {
    bool menor_horario = (this->hora() == h.hora() && this->min() < h.min()) || (this->hora() < h.hora());
    // Completar iguadad (ej 9)
    return menor_horario;
}

// Ejercicio 13

// Clase Recordatorio

class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h, string mensaje);
    string mensaje();
    Fecha f();
    Horario h();

    bool operator<(Recordatorio r);


private:
    string mensaje_;
    Fecha f_;
    Horario h_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string mensaje) : f_(f), h_(h), mensaje_(mensaje) {
};

string Recordatorio::mensaje(){
    return mensaje_;
}

Fecha Recordatorio::f(){
    return f_;
}
Horario Recordatorio::h(){
    return h_;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.f() << " " << r.h();
    return os;
}

bool Recordatorio::operator<(Recordatorio r) {
    bool menor_recordatorio = (h_.hora() == r.h().hora() && h_.min() < r.h().min()) || (h_.hora() < r.h().hora());
    // Completar iguadad (ej 9)
    return menor_recordatorio;
}

// Ejercicio 14

// Clase Agenda

class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list <Recordatorio> recordatorios_de_hoy();
    Fecha hoy();
    void ordenar_recordatorios(list<Recordatorio> recs);

private:
    list<Recordatorio> recordatorios_de_hoy_;
    Fecha hoy_;
};

Agenda::Agenda(Fecha fecha_inicial) : hoy_(fecha_inicial){
};

Fecha Agenda::hoy(){
    return hoy_;
}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    recordatorios_de_hoy_.push_back(rec);
    recordatorios_de_hoy_.sort();
}

void Agenda::incrementar_dia() {
    hoy_.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy(){
    return recordatorios_de_hoy_;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;
    for(Recordatorio r : a.recordatorios_de_hoy()){
        if(r.f()==a.hoy()){
            os << r << endl;
        }
    }
    return os;
}
