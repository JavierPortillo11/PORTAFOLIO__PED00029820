//Resuelva el problema de calcular la suma de todos los dígitos de un número entero dado.
#include <iostream>
using namespace std;

int sumar(int num);
int num, suma= 0;

int main(void)
{

cout << "\nSUMA DE LOS DIGITOS DE UN NUMERO\n\n";
cout << "Digite un numero: "; cin >> num;
sumar(num);

cout << "\n\n";
return 0;
}

int sumar(int num){
    while (num>0){
        suma+= num % 10;
        num/= 10;
    }
    cout << "La suma de los numeros es: " << suma;
    return suma;
}