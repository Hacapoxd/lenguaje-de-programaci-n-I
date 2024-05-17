#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_ERRORES = 100; 

int main() {
    ifstream inputFile("tipos_de_errores.txt");  
    ofstream outputFile("resumen_errores.txt"); 

    // Verificar si los archivos se abrieron correctamente
    if (!inputFile.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    string errores[MAX_ERRORES];
    int conteos[MAX_ERRORES] = {0}; 

    int num_errores = 0;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;
        iss >> token; // Leer la primera parte de la línea "ERROR"
        if (token == "ERROR") {
        // Leer el código de error
            string codigo_error;
            iss >> codigo_error;

        // Buscar si el código de error ya existe en el array de errores
            int indice_error = -1;
            for (int i = 0; i < num_errores; ++i) {
                if (errores[i] == codigo_error) {
                    indice_error = i;
                    break;
                }
            }

        // Si el código de error no existe, agregarlo al array de errores
            if (indice_error == -1) {
                errores[num_errores] = codigo_error;
                indice_error = num_errores;
                num_errores++;
            }

        // Incrementar el conteo del código de error correspondiente
            conteos[indice_error]++;
        }
    }

    // Escribir el resumen de errores en el archivo de salida
    for (int i = 0; i < num_errores; ++i) {
        outputFile <<"ERROR "<< errores[i] << ": " << conteos[i] << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "El resumen de errores se ha guardado en 'resumen_errores.txt'." << endl;

    return 0;
}
