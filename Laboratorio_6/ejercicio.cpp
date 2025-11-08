#include <iostream>
#include <string>
using namespace std;

struct Direccion {
    string nom_calle;
    int num_casa;
    string nom_ciudad;
};

struct Estudiante {
    string nom_est;
    int edad;
    float notas[5];
    Direccion dir;
};

void ingresarDatos(Estudiante* lista, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << endl << "--- Estudiante " << i + 1 << " ---" << endl;

        cout << "Nombre del estudiante " << endl;
        cin >> lista[i].nom_est;

        cout << "Edad" << endl;
        cin >> lista[i].edad;

        cout << "Ingrese 5 notas" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "  Nota " << j + 1 << ": ";
            cin >> lista[i].notas[j];
        }

        cout << "Nombre de la calle " << endl;
        cin >> lista[i].dir.nom_calle;

        cout << "Numero de casa " << endl;
        cin >> lista[i].dir.num_casa;

        cout << "Nombre de la ciudad " << endl;
        cin >> lista[i].dir.nom_ciudad;

        cout << "Estudiante ingresado correctamente" << endl;
    }
}

void mostrarDatos(Estudiante* lista, int cant) {
    cout << endl << "--- LISTA DE ESTUDIANTES ---" << endl;
    for (int i = 0; i < cant; i++) {
        cout << endl << "Estudiante " << i + 1 << endl;
        cout << "Nombre " << lista[i].nom_est << endl;
        cout << "Edad " << lista[i].edad << endl;
        cout << "Notas ";
        for (int j = 0; j < 5; j++) {
            cout << lista[i].notas[j] << " ";
        }
        cout << endl;
        cout << "Direccion " << lista[i].dir.nom_calle << " "
             << lista[i].dir.num_casa << ", "
             << lista[i].dir.nom_ciudad << endl;
        cout << "-----------------------------" << endl;
    }
}

void buscarEstudiante(Estudiante* lista, int cant, string nom_buscar) {
    bool encontrado = false;

    for (int i = 0; i < cant; i++) {
        if (lista[i].nom_est == nom_buscar) {
            encontrado = true;
            cout << endl << "--- Estudiante encontrado ---" << endl;
            cout << "Nombre " << lista[i].nom_est << endl;
            cout << "Edad " << lista[i].edad << endl;
            cout << "Notas " << endl;
            for (int j = 0; j < 5; j++) {
                cout << lista[i].notas[j] << " ";
            }
            cout << endl;
            cout << "Direccion: " << lista[i].dir.nom_calle << " " 
                 << lista[i].dir.num_casa << ", "
                 << lista[i].dir.nom_ciudad << endl;
            cout << "-----------------------------" << endl;
            break;
        }
    }
    if (!encontrado)
        cout << "No se encontro al estudiante" << endl;
}

int main() {
    int cant_est, opcion;
    cout << "Cuantos estudiantes desea registrar " << endl;
    cin >> cant_est;

    Estudiante* lista = new Estudiante[cant_est];

    do {
        cout << endl;
        cout << "---- MENU DE GESTION DE ESTUDIANTES ----" << endl;
        cout << "| 1. Ingresar estudiantes              |" << endl;
        cout << "| 2. Mostrar estudiantes               |" << endl;
        cout << "| 3. Buscar estudiante                 |" << endl;
        cout << "| 4. Salir                             |" << endl;
        cout << "----------------------------------------" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarDatos(lista, cant_est);
                break;
            case 2:
                mostrarDatos(lista, cant_est);
                break;
            case 3: {
                string nom_buscar;
                cout << "Ingrese el nombre del estudiante a buscar " << endl;
                cin >> nom_buscar;
                buscarEstudiante(lista, cant_est, nom_buscar);
                break;
            }
            case 4:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opción invalida " << endl;
        }
    } while (opcion != 4);

    delete[] lista;
    return 0;
}
