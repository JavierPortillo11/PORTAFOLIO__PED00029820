#include <iostream>
using namespace std;
int x, y;
int mcd(int x, int y);
int main(void)
{

    cout << "\nALGORITMO DE EUCLIDES RECURSIVO\n\n";
    cout << "Ingrese 2 numeros: "; cin >> x >> y;

    if(x<1 || y<1)
        cout << "\nAmbos numeros deben ser mayores de cero" << "\n\n";
        else if(x>=y)
                cout << "\nEl MCD de: " << x << " y " << y << " es: " <<  mcd(x, y) << "\n\n";
                    else if(x<y)
                            cout << "\nEl MCD de: " << x << " y " << y << " es: " <<  mcd(y, x) << "\n\n";
                        
return 0;
}

int mcd(int x, int y){
    if(y==0)
        return x;
    else
        return mcd(y, x%y);
}

/*La diferencia entre las 2 es que la función recursiva se resuelve llamandose a si misma las veces que sea necesario repitiendo el caso base 
de nuestra función y en cuestiones practicas me resultó mas fácil ya que es menos código y mas rápido*/