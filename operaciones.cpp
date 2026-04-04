/******************************************************************************

Alan Jesus Portillo Bernal
04/04/2026
Codigo operaciones basicas +/-*
*******************************************************************************/
#include <iostream>

int main(){
    float numero1, numero2;
    
    std::cout << "coloca el valor de a: ";
    std::cin >> numero1;
    
    std::cout << "coloca el valor de b: ";
    std::cin >> numero2;
    
    float suma= numero1+numero2;
    float resta= numero1-numero2;
    float multiplicacion= numero1*numero2;
    float division = numero1/numero2;
    
    std::cout << "a+b= " << suma << std::endl;
    std::cout << "a-b= " << resta << std::endl;
    std::cout << "a*b= " << multiplicacion << std::endl;
    std::cout << "a/b= " << division << std::endl;
    
    return 0;

}