/*

215465492 Saul Ezequiel García Ramos
219293548 Abel Alejandro villa Gonzalez
211721923 Jorge Luis Herrada Serrano 

Materia: Estructura de datos 2
Seccion: D12
Profesor: Dra. Graciela Lara Lopez

*/

#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <iostream>
using namespace std;

class Propietario
{
private:
    string placa;       //CAMPO DE LA PLACA
    string nombre;      //CAMPO DE LA PLACA
    string domicilio;   //CAMPO DE LA PLACA
    string provincia;   //CAMPO DE LA PLACA
    size_t cont;        //CONTADOR
    int frecuencias[100];  // LISTA CONTADORA DE FRECUENCIAS
public:
    Propietario();      //CONSTRUCTOR
    ~Propietario();     //DESTRUCTOR

    // GETTERS AND SETTERS
    void set_placa(const string& pl);       //GUARDA LA PLACA
    string get_placa();                     //RETORNA LA PLACA
    void set_nombre(const string& nom);     //GUARDA EL NOMBRE
    string get_nombre();                    //RETORNA NOMBRE
    void set_domicilio(const string& dom);  //GUARDA DOMICILIO
    string get_domicilio();                 //RETORNA DOMICILIO
    void set_provincia(const string& prv);  //GUARDA PROVINCIA
    string get_provincia();                 //RETORNA PROVINCIA

    // METODO QUE LEE EL ARCHIVO Y APLICA FUNCION DE DISPERSION
    // PARA OBTENER DIRECCION BASE, GENERA ARCHIVO NUEVO CON LOS REGISTROS EN LAS
    // NUEVAS DIRECCIONES
    void funcion_de_dispersion();

    //PROCESA LA PLACA Y RETORNA LA DIRECCIÓN BASE 
    size_t calcular_direccion_base(const string& _placa);

    // ASIGNA LOS VALORES DE LA LISTA CONTADORA DE FRECUENCIAS EN 0
    void inicializar_lista();

    // SI ENCUENTRO UNA COINCIDENCIA LE SUMO 1 EN LA LISTA EN SU POSICION, RECIBO LA POSICION EN EL ARCHIVO
    void cuenta_frecuencias(size_t);

    //  IMPRIME EN PANTALLA Y ESCRIBE EN EL ARCHIVO LA LISTA DE FRECUENCIAS
    void imprime_frecuencia();

    //MOSTRAR RESULTADOS ORDENADOS DEJANDO VACIAS LAS DIRECCIONES NO GENERADAS
    void mostrar_resultado();
};

#endif //PROPIETARIO_H
