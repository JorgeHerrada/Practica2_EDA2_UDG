#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <iostream>
using namespace std;

class Propietario
{
private:
    string placa;
    string nombre;
    string domicilio;
    string provincia;
    size_t cont;
    int frecuencias[100];  // LISTA CONTADORA DE FRECUENCIAS
public:
    Propietario();
    ~Propietario();
    void set_placa(const string& pl);
    string get_placa();
    void set_nombre(const string& nom);
    string get_nombre();
    void set_domicilio(const string& dom);
    string get_domicilio();
    void set_provincia(const string& prv);
    string get_provincia();

    void funcion_de_dispersion();
    size_t calcular_direccion_base(const string& _placa);
    void inicializar_lista();
    void cuenta_frecuencias(size_t);
    void imprime_frecuencia();
    void mostrar_resultado();
};

#endif //PROPIETARIO_H
