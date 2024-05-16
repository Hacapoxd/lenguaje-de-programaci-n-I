#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits> // Para usar numeric_limits

using namespace std;

int main() {
    ifstream inputFile("temperaturas.txt");  // Archivo de entrada
    ofstream outputFile("temperaturas_extremas.txt"); // Archivo de salida

    // Verificar si los archivos se abrieron correctamente
    if (!inputFile.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    double temperatura_maxima = numeric_limits<double>::lowest();
    double temperatura_minima = numeric_limits<double>::max();
    string dia_maxima, dia_minima;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string fecha;
        double temperatura;
        char delim; 
        getline(iss, fecha, ',');
        iss >> temperatura >> delim;

        // Verificar si la temperatura es máxima o mínima
        if (temperatura > temperatura_maxima) {
            temperatura_maxima = temperatura;
            dia_maxima = fecha;
        }

        if (temperatura < temperatura_minima) {
            temperatura_minima = temperatura;
            dia_minima = fecha;
        }
    }

    // Escribir los días con temperaturas extremas en el archivo de salida
    outputFile << "Dia de temperatura máxima: " << dia_maxima << ", " << temperatura_maxima << endl;
    outputFile << "Dia de temperatura mínima: " << dia_minima << ", " << temperatura_minima << endl;

    inputFile.close();
    outputFile.close();

    cout << "Los dias con temperaturas extremas se han guardado en 'temperaturas_extremas.txt'." << endl;

    return 0;
}
