#include <iostream>
using namespace std;

struct estudiantes{
    string nombre = " ";
    bool asistencia;
    int carnet = 0, horasSociales = 0, nivelDeCarrera = 0;
};

struct nodo {
    estudiantes DatosEstudiantes;
    nodo *sig;
};

class manejoEstudiantes{
    private:
        nodo *pPila, *pCola;

        void pilaDatosIns(estudiantes es);
        void colaDatosIns(estudiantes es);

    public:
        manejoEstudiantes() {  //Constructor
            pPila = NULL;
            pCola = NULL;
        }

        ~manejoEstudiantes(){  //Destructor
            delete pPila;
            delete pCola;
        }

        void pilaDatos();
        void pilaDatosIns();
        void colaDatosIns();
        void busquedaCarnet(int carnet);
        void mostrarEstudiantesPila();
        void mostrarEstudiantesCola();
    };

void manejoEstudiantes::pilaDatos() {
    estudiantes es;
    int masDatos = 0;

    do {
        cout << "\nNombre: "; getline(cin, es.nombre);
        cout << "Carnet: "; cin >> es.carnet;
        cout << "Nivel de carrera: "; cin >> es.nivelDeCarrera;
        cout << "Horas sociales: "; cin >> es.horasSociales;
        cout << "Asistio presencialmente: (1 = SI, 0 = NO): "; cin >> es.asistencia;
        cin.clear(); cin.ignore();

        if(es.asistencia==1){
            pilaDatosIns(es);
            colaDatosIns(es);               
        }
        else
            pilaDatosIns(es);

        cout << "\nMas datos (0 = NO, 1 = SI) "; cin >> masDatos;
        cin.ignore();
    } while (masDatos==1);
}    

void manejoEstudiantes::pilaDatosIns(estudiantes es){
    nodo *nuevo = new nodo;
    nuevo->DatosEstudiantes = es;
    nuevo->sig = pPila;
    pPila = nuevo;
}

void manejoEstudiantes::colaDatosIns(estudiantes es){
    nodo *nuevo = new nodo;
    nuevo->DatosEstudiantes = es;
    nuevo->sig = NULL;

    if(!pCola)
        pCola = nuevo;
    else{
        nodo *aux = pCola;

        while(aux->sig)
            aux = aux->sig;

        aux->sig = nuevo;
    }
}

void manejoEstudiantes::busquedaCarnet(int carnet){
    bool encontrado = false;

    nodo *aux = pPila;

    while(aux) {
        if(aux->DatosEstudiantes.carnet == carnet){
            cout << "Nombre: " << aux->DatosEstudiantes.nombre << endl; 
            cout << "Nivel de carrera: " << aux->DatosEstudiantes.nivelDeCarrera << endl; 
            cout << "Horas sociales: " << aux->DatosEstudiantes.horasSociales << endl; 

            encontrado = true;
            break;
        }
        aux = aux->sig;
    }

    if(!encontrado)
        cout << "No se ha encontrado el estudiante" << endl;
}

void manejoEstudiantes::mostrarEstudiantesPila(){
    nodo *aux = pPila;

    while(aux) {
        cout << "Nombre: " << aux->DatosEstudiantes.nombre << endl; 
        cout << "Carnet: " << aux->DatosEstudiantes.carnet << endl;
        cout << "Nivel de carrera: " << aux->DatosEstudiantes.nivelDeCarrera << endl; 
        cout << "Horas sociales: " << aux->DatosEstudiantes.horasSociales << "\n\n";

        aux = aux->sig;
    }
}
void manejoEstudiantes::mostrarEstudiantesCola(){
    nodo *aux = pCola;

    while(aux) {
        cout << "Nombre: " << aux->DatosEstudiantes.nombre << endl; 
        cout << "Carnet: " << aux->DatosEstudiantes.carnet << endl;
        cout << "Nivel de carrera: " << aux->DatosEstudiantes.nivelDeCarrera << endl; 
        cout << "Horas sociales: " << aux->DatosEstudiantes.horasSociales << "\n\n";

        aux = aux->sig;
    }
}

int main(void){
    manejoEstudiantes es;
    int opcion = 0, carnetBuscar = 0;

    do {
        cout << "\n\tINGENIERIA INFORMATICA";
        cout << "\n1. Ingresar nuevo estudiante";
        cout << "\n2. Buscar por Carnet";
        cout << "\n3. Mostrar todos los estudiantes";
        cout << "\n4. Mostrar los estudiantes que asistieron presencialmente";
        cout << "\n0. Salir\n";
        cout << "Su opcion: "; cin >> opcion;

        cin.clear(); cin.ignore();
        
        switch (opcion) {
            case 1:
                es.pilaDatos();
                break;
            case 2:
                cout << "\nCarnet: "; cin >> carnetBuscar;
                es.busquedaCarnet(carnetBuscar);
                break;
            case 3:
                cout << "\nTODOS LOS ESTUDIANTES\n\n";
                es.mostrarEstudiantesPila();
            case 4:
                cout << "\nESTUDIANTES QUE ASISTIERON PRESENCIAL\n\n";
                es.mostrarEstudiantesCola();
                break;
            default:
                break;
        }
    } while (opcion!=0);
    
    cout << endl;
    return 0;
}