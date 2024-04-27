#include <iostream> 
using namespace std;

// PROMEDIO CON PUNTEROS
struct Estudiante{ 

    int *codigo; 
    string *nombre; 
    string *apellidos;
    int **notas; 
    float *promedio;
    
};

int main(){ 
    Estudiante estudiante; 
    int fila = 0; 
    int columna = 4; 
    // Cambiamos el número de notas por estudiante a 4

    cout<<"Cuantos Estudiantes desea Agregar: ";
    cin>>fila; 

    estudiante.codigo = new int [fila];
    estudiante.nombre = new string[fila];
    estudiante.apellidos = new string[fila];
    estudiante.notas = new int *[fila];

    for (int i=0; i<fila; i++){
        estudiante.notas[i] = new int[columna];
    }

    cout<<"Ingreso de notas __________"<<endl;

    for(int i=0; i<fila; i++){
        cout<<"Codigo[ "<<i<<"]: ";
        cin>>estudiante.codigo[i];
        cin.ignore();
        cout<<"Nombres Completo[ "<<i<<"]:";
        getline(cin, estudiante.nombre[i]);
        cout<<"Apellidos Completos[ "<<i<<"]:";
        getline(cin, estudiante.apellidos[i]);
    
        int total_score = 0;
        for (int ii = 0; ii < columna; ii++) {
            cout << "Ingrese Nota[" << ii << "] :";
            cin >> *(*(estudiante.notas + i) + ii);
            total_score += *(*(estudiante.notas + i) + ii);
        }
        cout<<"___________________"<<endl;
    }

    // Calcular promedio
    cout<<"_______Mostrar datos ________"<<endl;
    estudiante.promedio = new float[fila];

    for(int i=0; i<fila; i++){
        cout<<"Codigo[ "<<i<<"]: "<<estudiante.codigo[i]<<endl;
        cout<<"Nombre Completo[ "<<i<<"]:"<<estudiante.nombre[i]<<endl;
        cout<<"Apellidos Completos[ "<<i<<"]:"<<estudiante.apellidos[i]<<endl;
        estudiante.promedio[i] = 0;
        for(int ii=0; ii<columna; ii++ ){
            cout<<"Ingrese Nota["<<ii<<"] :"<<*(*(estudiante.notas+i)+ii)<<endl;
            estudiante.promedio[i] += *(*(estudiante.notas+i)+ii);
        }
        estudiante.promedio[i] /= columna;

        if(estudiante.promedio[i] >= 60){
            cout<<"Aprobado"<<endl;
        } else {
            cout<<"Desaprobado"<<endl;
        }
        cout<<"Promedio: "<<estudiante.promedio[i]<<endl;
        cout<<"___________________"<<endl;
    }

    for (int i=0; i<fila; i++){
        delete[] estudiante.notas[i];
    }

    delete [] estudiante.codigo; 
    delete [] estudiante.nombre;
    delete [] estudiante.apellidos;
    delete [] estudiante.notas;
    delete [] estudiante.promedio;

    system("pause");
    return 0;
}
