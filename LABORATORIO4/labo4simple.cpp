#include <iostream>
using namespace std;
 
struct nodo
{
    int dato = 0;
    nodo *sig;
};

class ListaSimple
{
private:
    nodo *pInicio;

public:
    ListaSimple();
    ~ListaSimple();

    void InsFinal(int);
    void InsertarEnLista();
    void MostrarListaSimple();
    int EliminarNumero(int);
    void MostrarPares();
    void MostrarImpares();
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

ListaSimple::~ListaSimple(void)
{
    nodo *p;

    while (pInicio)
    {
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaSimple::InsFinal(int dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if (!pInicio)
        pInicio = nuevo;

    else
    {
        nodo *s = pInicio;
        while (s->sig)
            s = s->sig;
        s->sig = nuevo;
    }
}

void ListaSimple::InsertarEnLista(void)
{
    int dato = 0, num = 0;

    cout << "\nCuantos numeros quiere ingresar: ";
    cin >> num;
    cout << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "Digite un entero: ";
        cin >> dato;
        InsFinal(dato);
    }
}

void ListaSimple::MostrarListaSimple(void)
{
    nodo *p;
    p = pInicio;

    if (!pInicio)
        cout << "\nLA LISTA ESTA VACIA\n";
    else
    {
        cout << "\nLos elementos de la lista son:\n\n";

        while (p)
        {
            cout << p->dato << endl;
            p = p->sig;
        }
    }
}

int ListaSimple::EliminarNumero(int num) {
   int datoref = 0;
   nodo* p, *aux = pInicio;

   while (aux != NULL) {
       if (pInicio->dato == datoref){
           p = pInicio;  
           pInicio = pInicio->sig;
           aux = pInicio;
           delete p;
       }
       else {
           if (aux->sig != NULL && aux->sig->dato == num){
               p = aux->sig;
               aux->sig = aux->sig->sig;
               delete p;
           }
           else
               aux = aux->sig;
       }
   }
}

void ListaSimple::MostrarPares(void)
{
    nodo *aux;
    aux = pInicio;

    if (!pInicio)
        cout << "\nLA LISTA ESTA VACIA";
    else
    {
        cout << "\nLOS ELEMENTOS PARES SON: ";

        while (aux != NULL)
        {
            if (aux->dato % 2 == 0)
                cout << aux->dato << "  ";

            aux = aux->sig;
        }
    }
    cout << endl;
}

void ListaSimple::MostrarImpares(void)
{
    nodo *aux;
    aux = pInicio;

    if (!pInicio)
        cout << "\nLA LISTA ESTA VACIA";
    else
    {
        cout << "\nLOS ELEMENTOS IMPARES SON: ";

        while (aux != NULL)
        {
            if (aux->dato % 2 != 0)
                cout << aux->dato << "  ";

            aux = aux->sig;
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{

    ListaSimple lista;
    int opcion = 0, datoref = 0;

    cout << "\nLISTA SIMPLE\n";
    do
    {
        cout << "\n1. Ingresar numeros a la lista";
        cout << "\n2. Mostrar la lista";
        cout << "\n3. Eliminar un numero";
        cout << "\n4. Mostrar los numeros pares";
        cout << "\n5. Mostrar los numeros impares";
        cout << "\n0. Salir";
        cout << "\n\nSu opcion es: ";
        cin >> opcion;
        cin.clear(), cin.ignore(1000, '\n');

        switch (opcion)
        {
        case 1:
            lista.InsertarEnLista();
            cin.clear();
            break;
        case 2:
            lista.MostrarListaSimple();
            break;
        case 3:
        cout << "\nDigite el numero a eliminar: "; cin >> datoref;
            lista.EliminarNumero(datoref);
            break;
        case 4:
            lista.MostrarPares();
            break;
        case 5:
            lista.MostrarImpares();
            break;
        case 0:
            cout << "\nSaliendo...\n\n";
        default:
            break;
        }
    } while (opcion != 0);

    return 0;
}