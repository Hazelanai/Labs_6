#include <iostream>
#include <fstream>
using namespace std;

// Leer archivo
int leerArchivo(const char* nombre, int arr[]) {
    ifstream archivo(nombre);
    int n, i = 0;

    if (!archivo) {
        cout << "No se pudo abrir " << nombre << endl;
        return 0;
    }

    while (archivo >> n) {
        arr[i++] = n;
    }

    archivo.close();
    return i;
}

void guardarArchivo(const char* nombre, int arr[], int n) {
    ofstream archivo(nombre);
    for (int i = 0; i < n; i++)
        archivo << arr[i] << endl;
}

void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void mostrarArchivo(const char* nombre) {
    ifstream archivo(nombre);
    int n;

    cout << "Contenido de " << nombre << ":" << endl;
    while (archivo >> n)
        cout << n << " ";
    cout << endl;
}

int main() {

    int datos[100], pares[100], impares[100];
    int total, cp, ci;
    int opcion;

    do {
        cout << "---------- MENU -----------" << endl;
        cout << "| 1. Ver datos originales |" << endl;
        cout << "| 2. Clasificar numeros   |" << endl;
        cout << "| 3. Ver resultados       |" << endl;
        cout << "| 4. Salir                |" << endl;
        cout << "---------------------------" << endl;
        cin >> opcion;

        switch (opcion) {

        case 1: {
            int temp[100];
            int cant = leerArchivo("datos.txt", temp);

            cout << "Datos originales:" << endl;
            for (int i = 0; i < cant; i++)
                cout << temp[i] << " ";
            cout << endl;
            break;
        }

        case 2: {
            total = leerArchivo("datos.txt", datos);
            cp = ci = 0;

            for (int i = 0; i < total; i++) {
                if (datos[i] % 2 == 0)
                    pares[cp++] = datos[i];
                else
                    impares[ci++] = datos[i];
            }

            cout << endl << "Antes (sin ordenar)" << endl;

            cout << "Pares: " << endl;
            for (int i = 0; i < cp; i++)
                cout << pares[i] << " ";
            cout << endl;

            cout << "Impares: " << endl;
            for (int i = 0; i < ci; i++)
                cout << impares[i] << " ";
            cout << endl;

            // Ordenar ambos
            burbuja(pares, cp);
            burbuja(impares, ci);

            // Guardar archivos ordenados
            guardarArchivo("pares.txt", pares, cp);
            guardarArchivo("impares.txt", impares, ci);

            cout << endl << "Despues (ordenados)" << endl;

            cout << "Pares: ";
            for (int i = 0; i < cp; i++)
                cout << pares[i] << " ";
            cout << endl;

            cout << "Impares: ";
            for (int i = 0; i < ci; i++)
                cout << impares[i] << " ";
            cout << endl;

            break;
        }

        case 3:
            mostrarArchivo("pares.txt");
            mostrarArchivo("impares.txt");
            break;

        case 4:
            cout << "Saliendo" << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;

        }

    } while (opcion != 4);

    return 0;
}
