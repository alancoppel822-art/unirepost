/******************************************************************************
Alam Jesus Portillo Bernal
03/04/2026
codigo para validar edad :D

*******************************************************************************/
#include <iostream>

using namespace std;
int main() {
    int edad;
    cout << "coloca tu edad: ";
    cin >> edad;
    if (edad >=18 ){
        cout << "Eres mayor de edad :D" << endl;
    } else {
        cout << "eres menor de edad D:" << endl;
    }
    return 0;
}