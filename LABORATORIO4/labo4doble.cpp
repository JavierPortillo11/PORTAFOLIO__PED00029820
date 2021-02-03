#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *ant, *sig;
};

class ListaDoble{
    private:
        nodo *pInicio;

    public:
        ListaDoble(void);
        ~ListaDoble(void);
        void InsFinal(int);
        void InsertarEnLista(void);
        void Mostrar(void);
        void EliminarAnterior(int datoRef);
        bool EliminarAnterioraux(nodo *p, int datoRef);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::InsFinal(int dato){ 
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if (!pInicio){   
        pInicio = nuevo;
        pInicio->ant = NULL;
    }
    else{
        nodo *s = pInicio;
        while (s->sig)
            s = s->sig;
        s->sig = nuevo;
        nuevo->ant = s;
    }
}

void ListaDoble::InsertarEnLista(void) {
    int num = 0, dato = 0;

    cout << "\nCuantos numeros quiere ingresar: ";
    cin >> num;
    cout << endl;

    for (int i = 0; i < num; i++){
        cout << i+1 << ". Digite un entero: "; cin >> dato;
        InsFinal(dato);
    }
}

void ListaDoble::Mostrar(){

	nodo *aux = pInicio; 
    cout << "\nLos elementos de la lista son: \n\n";
	while (aux->sig){			
		cout << "  " << aux->dato;
		aux = aux->sig;	  
	}
	cout << "  " << aux->dato;
}

void ListaDoble::EliminarAnterior(int datoRef){
    if(EliminarAnterioraux(pInicio, datoRef))
        cout << "\nEl nodo se elimino";
    else
        cout << "\nEl nodo no se elimino";
}

bool ListaDoble::EliminarAnterioraux(nodo *p, int datoRef){
    nodo *s;

    if (p && (p->sig->dato != datoRef))
        EliminarAnterioraux(p->sig, datoRef);
    else if (p && (p->sig->dato == datoRef)){
        s = p->ant;
        s->sig = p->sig;
        s->sig->ant = p->sig->ant;
        delete p;
        return true;
    }    
    else
        return false;
}


int main(int argc, char const *argv[])
{
    int opcion = 0, datoref = 0;
    ListaDoble lista;

   cout << "\nLISTA DOBLE";
    do{
        cout << "\n\n1. Ingresar numeros a la lista";
        cout << "\n2. Mostrar la lista";
        cout << "\n3. Eliminar el numero anterior a referencia";
        cout << "\n0. Salir";
        cout << "\n\nSu opcion es: "; cin >> opcion;
       

        switch(opcion){
            case 1:
                lista.InsertarEnLista();
                cin.clear();
                break;
            case 2: 
                lista.Mostrar();
                break;
            case 3:
            cout << "\nDigite el numero de referencia: "; cin >> datoref;
                lista.EliminarAnterior(datoref);
                break;
            case 0:
                cout << "\nSaliendo...\n\n";
            default:
                break;
        }
    } while (opcion != 0);
    
    return 0;
}