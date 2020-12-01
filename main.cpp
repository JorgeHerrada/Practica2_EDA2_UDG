/*

215465492 Saul Ezequiel García Ramos
219293548 Abel Alejandro villa Gonzalez
211721923 Jorge Luis Herrada Serrano 

Materia: Estructura de datos 2
Seccion: D12
Profesor: Graciela Lara Lopez

*/


#include<iostream>
#include "propietario.h"
using namespace std;

//FUNCIONES PARA VALIDACIÓN DE ENTRADAS
int tomarInt();
bool tipoIntValido(string numero);

int main()
{
    int opcion; // ENTERO PARA ALMACENAR LA OPCION DEL USUARIO
    Propietario propietario_n; // CREAMOS OBJETO

    // BANDERA PARA QUE NO SE REPITA INECESARIAMENTE LA FUNCIÓN DE DISPERSIÓN
    // SI ES FALSE, NO PERMITE ENTRAR A LAS OPCIONES 2 Y 3
    // SI ES TRUE, NO PERMITE ENTRAR A LA OPCION 1
    bool control_flag = false; 

    do {
        system("cls");
        // MENÚ
        cout<<"********************";
        cout<<"Base de datos del MINISTERIO DE FOMENTO DE ESPAÑA";
        cout<<"********************"<<endl<<endl<<endl;
        cout<<"Bienvenido, por favor seleccione una opción: "<<endl<<endl;
        cout<<"1.-Ejecutar la función de dispersión."<<endl;
        cout<<"2.-Mostrar resultados de función."<<endl;
        cout<<"3.-Mostrar numero de frecuencias."<<endl;
        cout<<"4.-SALIR"<<endl;

        opcion = tomarInt();//PEDIMOS AL USUARIO INGRESAR SU OPCION COMO ENTERO Y VALIDAMOS LA ENTRADA

        //ENTRAMOS AL CASO CORRESPONDIENTE SEGUN EL VALOR DE OPCION INGRESADO POR USUARIO
        switch(opcion) {
        case 1:
        {
            // SI LA BANDERA DE CONTROL ES TRUE, ENVIA MENSAJE: 
            // LA FUNCION DE DISPERSION HA SIDO APLICADA Y SALE DEL SWITCH
            if (control_flag) 
            {
                cout << "Ya se ha realizado la función de dispersión. Selecciona la opcion 2 o 3 para ver resultados." << endl;
                break;
            }
            else
            {
                // FUNCION_DE_DISPERSION
                // LLAMAMOS AL METODO QUE LEE EL ARCHIVO Y APLICA FUNCION DE DISPERSION
                // PARA OBTENER DIRECCION BASE, GENERA ARCHIVO NUEVO CON LOS REGISTROS EN LAS
                // NUEVAS DIRECCIONES
                propietario_n.inicializar_lista();
                propietario_n.funcion_de_dispersion();
                cout << "Se ha aplicado la función de dispersión con éxito.";
                cout << "Ahora los registros están organizados en su nueva dirección." << endl;
                // BANDERA DE CONTROL ACTIVA, YA NO DEJARÁ QUE SE ENTRE A ESTA PARTE DEL CÓDIGO
                control_flag = true; 
            }
        }
        break;

        case 2:
        {
            // SI LA BANDERA DE CONTROL ES FALSE, ENVIA MENSAJE: 
            // LA FUNCION DE DISPERSION NO HA SIDO APLICADA Y SALE DEL SWITCH
            if (control_flag)
            {
                //IMPRIMIR RESULTADO DE FUNCION_DE_DISPERSION
                propietario_n.mostrar_resultado();
            }
            else
            {
                // NO SE PUEDE DESPLEGAR RESULTADOS SIN HABER PASADO POR LA OPCION 1
                cout << "No se ha aplicado la función de dispersión. Selecciona la opcion 1." << endl;
            }
        }
        break;

        case 3:
        {
            // SI LA BANDERA DE CONTROL ES FALSE, ENVIA MENSAJE: 
            // LA FUNCION DE DISPERSION NO HA SIDO APLICADA Y SALE DEL SWITCH
            if (control_flag)
            {
                //MOSTRAR NUMERO DE FRECUENCIAS
                propietario_n.imprime_frecuencia();
            }
            else
            {
                // NO SE PUEDE DESPLEGAR RESULTADOS SIN HABER PASADO POR LA OPCION 1
                cout << "Aún no se ha aplicado la función de dispersión. Selecciona la opcion 1." << endl;
            }
        }
        break;

        case 4:
        {
            // SALIR
            cout << "Saliendo del programa." << endl<<endl;
        }
        break;

        default:
        {
            cout<<"Opcion invalida, intenta de nuevo con un entero entre 1 y 4."<<endl;
        }
        break;

        }
        system("pause");

    } while (opcion != 4);


    return 0;
}


//FUNCION PARA VALIDAR LA ENTRADA DE ENTEROS
//TOMA UNA CADENA, LA ANALISA Y SI ES VALIDA LA CONVIERTE A ENTERO
int tomarInt() {
    string numero;
    bool esValido = false;

    while(! esValido) {
        try {
            //cout<<"Ingrese un entero entre 1 y 4: ";
            getline(cin,numero);
            esValido = tipoIntValido(numero);

            if(! esValido) {
                throw numero;
            }
        } catch(string e) {
            cout<<"\n\nEl entero: "<<e<<" no es valido."<<endl;
        }
    }
    return atoi(numero.c_str());
}


//FUNCION PARA VALIDAR ENTRADA DE ENTEROS
//RECIBE LA CADENA QUE INGRESA EL USUARIO Y ANALISA QUE
//CONTENGA SOLO NUMEROS VALIDOS, RETORNA TRUE SI ES VALIDO
bool tipoIntValido(string numero) {
    int inicio=0;
    if (numero.length()==0)
        return 0; //false
    if(numero[0] == '+' || numero[0] == '-') {
        inicio = 1;
        if (numero.length() == 1)
            return 0;
    }
    for (int i=inicio; i<numero.length(); i++) {
        if(! isdigit(numero[i]))
            return 0;
    }
    return 1;
}
