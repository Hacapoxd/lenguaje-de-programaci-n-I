#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> 

using namespace std;

int main() {
    ifstream inputFile("productos.txt");  
    ofstream outputFile("precios_soles.txt");

    // Verificar si los archivos se abrieron correctamente
    if (!inputFile.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    // Tasa de conversión de dólares a soles
    const double tasa_conversion = 3.85;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string producto;
        double precio_dolares;
        char delim; 
        getline(iss, producto, ',');
        iss >> precio_dolares >> delim;
        
        // Convertir precio de dólares a soles
        double precio_soles = precio_dolares * tasa_conversion;

        // Escribir el producto y su precio convertido en soles en el archivo de salida
        outputFile << fixed << setprecision(2); // Establecer precisión de dos decimales
        outputFile << producto << ", " << precio_soles << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Los precios convertidos se han guardado en 'precios_soles.txt'." << endl;

    return 0;
}
