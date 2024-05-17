#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_EMPLEADOS = 100; // Suponemos un máximo de 100 empleados

int main() {
    ifstream inputFile("horas_de_trabajo.txt");  // Archivo de entrada
    ofstream outputFile("informe_horas.txt"); // Archivo de salida

    // Verificar si los archivos se abrieron correctamente
    if (!inputFile.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    string nombres[MAX_EMPLEADOS];
    int horas_totales[MAX_EMPLEADOS] = {0}; // Inicializar todas las horas a 0

    int num_empleados = 0;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string nombre_empleado;
        int horas;
        char delim; 
        getline(iss, nombre_empleado, ',');
        iss >> horas >> delim;

        // Buscar si el empleado ya existe en el array de nombres
        int indice_empleado = -1;
        for (int i = 0; i < num_empleados; ++i) {
            if (nombres[i] == nombre_empleado) {
                indice_empleado = i;
                break;
            }
        }

        // Si el empleado no existe, agregarlo al array de nombres
        if (indice_empleado == -1) {
            nombres[num_empleados] = nombre_empleado;
            indice_empleado = num_empleados;
            num_empleados++;
        }

        // Actualizar las horas totales trabajadas por el empleado
        horas_totales[indice_empleado] += horas;
    }

    // Escribir el informe de horas en el archivo de salida
    for (int i = 0; i < num_empleados; ++i) {
        outputFile << nombres[i] << ", Horas Totales: " << horas_totales[i] << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "El informe de horas se ha guardado en 'informe_horas.txt'." << endl;

    return 0;
}
