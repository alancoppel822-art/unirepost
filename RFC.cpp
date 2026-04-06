/******************************************************************************
alan jesus portillo bernal
06/04/2026
calculo de RFC :D

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

//Palabras prohibidas 
const std::vector<std::string> palabrasProhibidas = {
    "PENE", "VAGO", "VAGA", "LOCO", "LOCA", "PUTO", "PUTA", "BOBO", "BOBA", "COLA", "CACA"
};

//verificar y modificar palabras prohibidas
std::string corregirRFC(const std::string& rfc) {
    for (const std::string& palabra : palabrasProhibidas) {
        if (rfc == palabra) {
            return rfc.substr(0, 3) + "X"; //remplazar ultima letra por X
        }
    }
    return rfc;
}

//funcion para obtener la primera vocal inter de una cadena
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'A' || c == 'E' ||c == 'I' ||c == 'O' ||c == 'U')
        return c;
    }
    return 'x'; //sin vocal interna se pondra X
}

//funcion para calcular rfc
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento) {
    
    //se declara variable para guardar rfc
    std::string rfc;
    
    // se obtiene letra inicial y 1ra vocal de Apaterno 
    char letraInicial = apellidoPaterno[0];
    char PrimeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    // se obtiene  inicial de aMaterno o se pone x
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    //s obtiene  inicial de primer nombre
    char inicialNombre = nombre[0];
    //2 ultimos digitos de anio de nacimiento
    std::string anio = fechaNacimiento.substr(2, 2);
    //mes y dia de nacimiento
    std::string mes = fechaNacimiento.substr(5,2);
    std::string dia = fechaNacimiento.substr(8,2);
    
    //se construye RFC con los datos
    rfc = letraInicial;
    rfc += PrimeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    //comparacion de palabras para filtro
    rfc = corregirRFC(rfc);
    //si se corrige se continua con la creacion del rfc
    rfc += anio;
    rfc += mes;
    rfc += dia;
    return rfc;
}
int main( ){
    //consola para datos
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Apellido Paterno: ";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "Apellido Materno: ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "Fecha de nacimiento (AAAA/MM/DD): ";
    std::getline(std::cin, fechaNacimiento);
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}