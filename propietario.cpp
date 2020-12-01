#include "propietario.h"
#include <fstream>
#include <string.h>

Propietario::Propietario() { //CONSTRUCTOR
    //cont = 0; //NO RECURDO PARA QUÉ LO PUSE PERO CREO QUE PUEDE AYUDAR PARA LA OPCION 3 v:
}
Propietario::~Propietario() { //DESTRUCTOR

}


// METODO QUE LEE EL ARCHIVO Y APLICA FUNCION DE DISPERSION
// PARA OBTENER DIRECCION BASE, GENERA ARCHIVO NUEVO CON LOS REGISTROS EN LAS
// NUEVAS DIRECCIONES
void Propietario::funcion_de_dispersion() {
    ifstream archivo("AUTOS_PRO.TXT");//ABRIMOS ARCHIVO CON REGISTROS DE CONDUCTORES EN MODO LECTURA

    if(!archivo.is_open()) { // CONDICION PARA ASEGURAR QUE EL ARCHIVO SE ABRI� CORRECTAMENTE
        cout << "Error en apertura de archivo" << endl; // CASO EN QUE FALLA APERTURA DE ARCHIVO
    } else { // SI EL ARCHIVO SE ABRI� CORRECTAMENTE CONTINUAMOS
        //CREAMOS ARCHIVO PARA GUARDAR LOS REGISTROS UNA VEZ ORGANIZADOS
        ofstream archivo_organizado("Registros_Organizados.txt",ios::out); //ARCHIVO EN MODO ESCRITURA

        if(!archivo_organizado.is_open()) { // CONDICION PARA ASEGURAR QUE EL ARCHIVO SE ABRIÓ CORRECTAMENTE
            cout << "Error en apertura de archivo"<< endl; //CASO EN QUE FALLA APERTURA DE ARCHIVO
        } else { // SI EL ARCHIVO SE ABRIÓ CORRECTAMENTE CONTINUAMOS
            // ESCRIBIMOS LOS NUMEROS DE LOS REGISTROS EN EN EL ARCHIVO_ORGANIZADO
            // AGREGAMOS LOS ESPACIOS CORESPONDIENTES AL TAMAÑO MÁXIMO DE UN REGISTRO
            // POR LOS VALORES MÁXIMOS DE CADA CAMPO ESPECIFICADOS EN EL PDF
            for (size_t i = 0; i < 100; i++) {
                if(i < 10) {
                    archivo_organizado << i << "                                                                                        " << endl;
                } else {
                    archivo_organizado << i << "                                                                                       " << endl;
                }
            }

            string _placa, _nombre, _domicilio, _provincia;//VARIABLES TEMPORALES PARA EXTRAER DATOS DEL ARCHIVO
            size_t n = 30; //NUMERO DE PROPIETARIOS/REGISTROS A LEER EN EL ARCHIVO

            for (size_t i = 0; i < n; i++) {
                // getline(archivo, _placa_numeros, ' ');
                // getline(archivo, _placa_letras, '|');
                // _placa_completa = _placa_numeros + " " + _placa_letras;
                getline(archivo, _placa, '|');
                getline(archivo, _nombre, '|');
                getline(archivo, _domicilio, '|');
                getline(archivo, _provincia, '|');

                set_placa(_placa);
                // set_nombre(_nombre);
                // set_domicilio(_domicilio);
                // set_provincia(_provincia);


                // cout << get_placa() << " " << get_nombre() << " " << get_domicilio() << " " << get_provincia() << endl;

                // SE CALCULA DIRECCION BASE Y SE GUARDA EN VARIABLE
                size_t direccion_base = calcular_direccion_base(_placa);

                // OPERACION PARA CALCULAR LA POSICION EXACTA DONDE SE VA ESCRIBIR EL
                // REGISTRO SEGUN SU DIRECCION BASE
                direccion_base = (direccion_base * 91) + 3;

                // COLOCAMOS EL PUNTERO PARA ESCRIBIR EN LA POSICION QUE SE CALCUL� ANTERIORMENTE
                archivo_organizado.seekp(direccion_base, ios::beg);

                // ESCRIBIMOS LOS CAMPOS DEL REGISTRO EN EL ARCHIVO
                archivo_organizado << get_placa() << "|" << _nombre << "|" << _domicilio << "|" << _provincia << "|               ";

                // // PRUEBAS*******************ELIMINAR AL TERMINAR EL C�DIGO
                // ofstream PRUEBAS("PRUEBAS.TXT", ios::app);
                // for (size_t i = 0; i < _placa.length(); i++)
                // {
                //     PRUEBAS << _placa[i];
                // }
                // PRUEBAS << "******";
                // PRUEBAS.close();
            }
        }
        archivo.close(); // CERRAMOS ARCHIVO DE PROPIETARIOS ORIGINAL
        archivo_organizado.close(); // CERRAMOS ARCHIVO DE REGISTROS ORGANIZADOS

    }
}


//PROCESA LA PLACA Y RETORNA LA DIRECCIÓN BASE 
size_t Propietario::calcular_direccion_base(const string& _placa) {
    string placa = _placa + "    "; //COMPLETA LOS ESPACIOS, PUES EL CAMPO DEBE DE TENER 12 CARACTERES DE LONGITUD

    char placa_char[12]; //CHAR PARA GUARDAR LA PLACA COMPLETA

    // CONVERTIR DE STRING A CHAR
    for (size_t i = 0; i < 12; i++) {
        placa_char[i] = placa[i];
    }

    // PLACA ORIGINAL AHORA EN CHAR
    //LINEAS DE PRUEBA
    // cout << placa_char[0] << placa_char[1] << placa_char[2] << placa_char[3] << placa_char[4] << placa_char[5] <<
    //         placa_char[6] << placa_char[7] << placa_char[8] << placa_char[9] << placa_char[10] << placa_char[11] << endl<<endl;


    // PASO 1.REPRESENTAR LA LLAVE EN FORMA NUMÉRICA
    int placa_int[12];

    //CHARACTER OF DIGIT TO DIGIT
    for (size_t i = 0; i < 4; i++) {
        placa_int[i] = placa_char[i] - '0';
    }


    // CHARACTER TO ITS ASCII VALUE
    for (size_t i = 4; i < 12; i++) {
        placa_int[i] = (int)placa_char[i];
    }

    // LINEAS DE PRUEBA
    // cout << "Numeros de placa en enteros y caracteres en entero segun su valor ASCII: " << endl;
    // for(int i = 0; i < sizeof(placa_char) ; i++)
    // {
    //     cout << placa_int[i] << " ";
    // }
    // cout << endl;

    // PASO 2. DESGLOSAR Y SUMAR

    int sumas[6];
    int j = 0;
    // cout << "Numeros concatenados y listos para sumarse: " << endl; //PRUEBA
    for (size_t i = 0; i < 6; i++) {
        if(placa_int[j+1] < 10) {
            sumas[i] = (placa_int[j] * 10) + placa_int[j+1];
        } else {
            sumas[i] = (placa_int[j] * 100) + placa_int[j+1];
        }

        j = j +2;
        // cout << sumas[i] << " + "; //PRUEBAS
    }

    size_t suma_final = 0; //ES LA QUE TERMINARÁ SIENDO LA NUEVA DIRECCION BASE
    // cout << "Suma de los valores anteriores y ahora nueva direccion base: " << endl; //PRUEBA
    for (size_t i = 0; i < 6; i++) {
        suma_final = suma_final + sumas[i];
        suma_final = suma_final % 20000;
    }
    // cout << suma_final << endl; //PRUEBA

    suma_final = (suma_final%101);

    if (suma_final == 100) {
        suma_final = 0;
    }

    cuenta_frecuencias(suma_final);  // CADA VEZ QUE SE ESCRIBE EN UNA POSICION, SE CONTARA UNO MAS EN LA FRECUENCIA


    // LINEAS DE PRUEBA
    // cout << "Direccion base, calculada con el numero anterior modulo(%) de 101 \n" << suma_final << endl;

    return suma_final;

}

// ASIGNA LOS VALORES DE LA LISTA CONTADORA DE FRECUENCIAS EN 0
void Propietario::inicializar_lista() {
    // POR CADA POSICION DE LA LISTA
    for (int i = 0; i < 100; i++) {
        frecuencias[i] = 0; // COLOCO 0 EN LA POSICION i
    }
}

// SI ENCUENTRO UNA COINCIDENCIA LE SUMO 1 EN LA LISTA EN SU POSICION, RECIBO LA POSICION EN EL ARCHIVO
void Propietario::cuenta_frecuencias(size_t suma_final) {
    frecuencias[suma_final] += 1;  // SUMO UNO EN LA POSICION RECIBIDA EN LA LISTA CONTADORA
}

//MOSTRAR RESULTADOS ORDENADOS DEJANDO VACIAS LAS DIRECCIONES NO GENERADAS
void Propietario::mostrar_resultado() { 
    system("cls");  // LIMPIAMOS PANTALLA
    ifstream archivo("Registros_Organizados.txt");  //ARCHIVO EN MODO ESCRITURA
	// SI NO SE PUDO ABRIR = ERROR
    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    
    else{
    	// SI NO LLEGA AL FINAL DEL ARCHIVO CONTINUA
        while(!archivo.eof()) {
        	
			string _placa, _nombre, _domicilio, _provincia;//VARIABLES TEMPORALES PARA EXTRAER DATOS DEL ARCHIVO
			int tam1;
			
			//EXTRAEMOS DATOS DEL ARCHIVO	
                getline(archivo, _placa, '|');
                getline(archivo, _nombre, '|');
                getline(archivo, _domicilio, '|');
                getline(archivo, _provincia, '|');
				
				//LONGITUD DEL NOMBRE PARA VALIDAR
                tam1=_nombre.length();

                //MOSTRAMOS EL REGISTRO EN PANTALLA SI RECIBIMOS UN VALOR EN LA POSICION DESPUES DEL NOMBRE
                if(tam1>1)
                {
                	cout << _placa << "|" << _nombre << "|" << _domicilio << "|" << _provincia << "|               ";
				}

		}
		cout <<endl;
	}
    archivo.close(); // CERRAMOS EL ARCHIVO
}


//  IMPRIME EN PANTALLA Y ESCRIBE EN EL ARCHIVO LA LISTA DE FRECUENCIAS
void Propietario::imprime_frecuencia() {
    system("cls");  // LIMPIAMOS PANTALLA
    ofstream archivo_frecuencias("Frecuencias.txt",ios::trunc);  //ARCHIVO EN MODO ESCRITURA

    cout << endl << "Frecuencias:" << endl << endl;
    // POR CADA POSICION EN LA LISTA, IMPRIMIMOS Y ESCRIBIMOS
    for (int i=0; i < 100; i++) {
        cout << i << " (" << frecuencias[i] << ")" << endl;  // IMPRIME LA FRECUENCIA DE LA POSICION
        archivo_frecuencias << i << " (" << frecuencias[i] << ")" << endl;  // ESCRIBE EN LA FRECUENCIA DE LA POSICION
    }

    archivo_frecuencias.close(); // CERRAMOS EL ARCHIVO
}

void Propietario::set_placa(const string& pl) {
    placa = pl;

    // // ELIMINANDO EL PRIMER CARACTER QUE ES UN SALTO DE LINEA Y CONSERVANDO LA PLACA
    placa[0] = '\0';

}

string Propietario::get_placa() {
    return placa;
}


void Propietario::set_nombre(const string& nom) {
    nombre = nom;
}
string Propietario::get_nombre() {
    return nombre;
}


void Propietario::set_domicilio(const string& dom) {
    domicilio = dom;
}
string Propietario::get_domicilio() {
    return domicilio;
}


void Propietario::set_provincia(const string& prv) {
    provincia = prv;
}
string Propietario::get_provincia() {
    return provincia;
}