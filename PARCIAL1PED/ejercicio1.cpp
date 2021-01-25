//Elabore un programa que lea una cadena desde teclado, invierta su contenido y muestre el resultado en pantalla.
#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
char cadena[100];

cout << "\nINVERTIR UNA CADENA\n\n";
cout << "Ingrese una frase: "; cin.getline(cadena, 100);

strrev(cadena);

cout << "\nLa cadena invertida es: " << cadena << "\n\n";

system("pause");
return 0;
}