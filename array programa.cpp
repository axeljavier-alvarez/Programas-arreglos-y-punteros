#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; // VARIABLE PARA EL NUMERO DE ESTUDIANTE
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // DECLARACION DE ARRAY
    int id[n];
    string nombre[n];
    string apellido[n];
    float notas[n][4];
    float promedio[n];

    // ENTRAR LOS DATOS DEL ESTUDIANTE Y SE VAN INCREMENTANDO
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;

        cout << "ID: ";
        cin >> id[i];

        cout << "Nombres: ";
        cin.ignore(); // MOSTRAR TODO EL NOMBRE
        getline(cin, nombre[i]);
        
        cout << "Apellidos: ";
        getline(cin, apellido[i]);

        // BUCLE PARA SOLO 4 NOTAS
        for (int j = 0; j < 4; j++) {
            cout << "Ingrese Nota " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }

    // PROMEDIO 
    for (int i = 0; i < n; i++) {
        float total = 0;
        for (int j = 0; j < 4; j++) {
            total += notas[i][j];
        }

        promedio[i] = total / 4;
    }

    // MOSTRAR RESULTADOS EN CONSOLA
    cout << "\n\nResultados:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "ID: " << id[i] << endl;
        cout << "Nombre: " << nombre[i] << endl;
        cout << "Apellido: " << apellido[i] << endl;
        cout << "Promedio: " << promedio[i] << endl;

        if (promedio[i] > 60) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
    }

    return 0;
}
