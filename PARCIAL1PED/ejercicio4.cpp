/*Elabore un programa que lea n números desde teclado y calcula la suma y el promedio de los mismos. Luego cree un archivo de texto 
en el que colocará, en la primera fila, la suma, en la segunda fila el promedio. No utilice arreglos en la solución de este problema.*/
#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
int n, i, numeros, suma=0, contador=0;
float promedio;

cout << "\nCuantos numeros quiere ingresar: "; cin >> n;

cout << endl;
for(i=0; i<n; i++){
    cout << i+1 << ". Digite un numero: "; cin >> numeros;
    suma+=numeros;
    contador++;
}

promedio= suma/contador;

ofstream archivo("texto.txt");

archivo << "Suma: " << suma << endl;
archivo << "Promedio: " << promedio;

archivo.close();

cout << endl;
return 0;
}