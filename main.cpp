/*

215465492 Saul Ezequiel García Ramos
219293548 Abel Alejandro villa Gonzalez
211721923 Jorge Luis Herrada Serrano 

Materia: Estructura de datos 2
Seccion: D12
Profesor: Dra. Graciela Lara Lopez

*/


#include<iostream>
#include "propietario.h"
using namespace std;

//FUNCIONES PARA VALIDACIÓN DE ENTRADAS
int tomarInt();//CONVIERTE LA CADENA A ENTERO
bool tipoIntValido(string numero); // CONFIRMA QUE LA CADENA CONTIENE UN ENTERO VALIDO

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
            //SI EL ENTERO NO FUE 1-4 LANZA SUGERENCIA Y SALE DEL SWITCH
            cout<<"Opcion invalida, intenta de nuevo con un entero entre 1 y 4."<<endl;
        }
        break;

        }
        system("pause"); //PAUSA Y ESPERA A TECLEO PARA CONTINUAR

    } while (opcion != 4); // CICLO DE MENÚ CONTINUA MIENTRAS NO SE ELIJA LA OPCION 4 PARA SALIR


    return 0;
}


//FUNCION PARA VALIDAR LA ENTRADA DE ENTEROS
//TOMA UNA CADENA, LA ANALISA Y SI ES VALIDA LA CONVIERTE A ENTERO
int tomarInt() {
    string numero; // CADENA PARA ALMACENAR ENTRADA DE CONSOLA
    bool esValido = false; //BOOLEANO DE CONFIRMACION

    while(! esValido) { 
        try {
            //cout<<"Ingrese un entero entre 1 y 4: ";
            getline(cin,numero);
            esValido = tipoIntValido(numero);//LLAMA A LA FUNCION PARA ASEGURAR QUE SON CARACTERES DE DIGITOS

            if(! esValido) {  // SI NO ES VALIDO NO CONTINUA
                throw numero;
            }
        } catch(string e) { //SI NO ES VALIDO DESPLIEGA MENSAJE Y REINICIA EL CICLO
            cout<<"\n\nEl entero: "<<e<<" no es valido."<<endl;
        }
    }//SI FUE VALIDO SALE DEL CICLO Y RETORNA EL ENTERO QUE ANTES ERA STRING
    return atoi(numero.c_str());//CONVIERTE STRING A ENTERO 
}


//FUNCION PARA VALIDAR ENTRADA DE ENTEROS
//RECIBE LA CADENA QUE INGRESA EL USUARIO Y ANALISA QUE
//CONTENGA SOLO NUMEROS VALIDOS, RETORNA TRUE SI ES VALIDO
bool tipoIntValido(string numero) {
    int inicio=0;
    if (numero.length()==0) //SI EL LARGO DE LA CADENA ES CERO, RETORNA FALSO
        return 0; //false
    // SI LA CADENA COMIENZA CON + Ó - LO DEJA PASAR Y LEERÁ A PARTIR DEL SEGUNDO CARACTER
    if(numero[0] == '+' || numero[0] == '-') { 
        inicio = 1;
        if (numero.length() == 1) //SI EL LARGO ES 1 (EL UNICO CARACTER ES + Ó -), RETORNA FALSO
            return 0;
    }
    //CHECA TODOS LOS CARACTERES DE LA CADENA Y SI NO SON DIGITO, RETORNA FALSE
    for (int i=inicio; i<numero.length(); i++) {
        if(! isdigit(numero[i]))
            return 0;
    }
    return 1; //SI PASÓ TODOS LOS FILTROS, CONFIRMA QUE SON CARACTERES DE DIGITOS Y RETORNA 1
}
