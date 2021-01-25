//Resuelva el problema de calcular la suma de todos los dígitos de un número entero dado.
#include <iostream>
using namespace std;

int sumar(int num, int suma);
int num, suma= 0;

int main(void)
{

cout << "\nDigite un numero: "; cin >> num;
cout << "La suma es: " << sumar(num, suma);

cout << "\n\n";
system("pause");
return 0;
}


int sumar(int num, int suma){ // 123 0   12 3    1 5   0 6
    suma=suma+num%10;   //3  5   6
    num=num/10;        //12  1   0
    if(num==0){
       return suma;
    }
    else{
        return sumar(num, suma);     
    }
}