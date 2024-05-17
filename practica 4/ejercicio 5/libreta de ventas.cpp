#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits> 

using namespace std;

int main() {
    ifstream inputFile("ventas.txt");  
    ofstream outputFile("resumen_ventas.txt"); 

    // Verificar si los archivos se abrieron correctamente
    if (!inputFile.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    int venta_total = 0;
    int venta_maxima = numeric_limits<int>::min();
    int venta_minima = numeric_limits<int>::max();
    string dia_maxima, dia_minima;
    int contador_dias = 0;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string fecha;
        int venta;
        char delim; 
        getline(iss, fecha, ',');
        iss >> venta >> delim;

    // Actualizar la venta total
        venta_total += venta;
        
    // Verificar si la venta es máxima o mínima
        if (venta > venta_maxima) {
            venta_maxima = venta;
            dia_maxima = fecha;
        }

        if (venta < venta_minima) {
            venta_minima = venta;
            dia_minima = fecha;
        }

        contador_dias++;
    }

    // Calcular el promedio de ventas
    double promedio_ventas = static_cast<double>(venta_total) / contador_dias;

    // Escribir el resumen de ventas en el archivo de salida
    outputFile << "Venta total: " << venta_total << endl;
    outputFile << "Promedio de ventas: " << fixed << promedio_ventas << endl;
    outputFile << "Día de mayor venta: " << dia_maxima << ", " << venta_maxima << endl;
    outputFile << "Día de menor venta: " << dia_minima << ", " << venta_minima << endl;

    inputFile.close();
    outputFile.close();

    cout << "El resumen de ventas se ha guardado en 'resumen_ventas.txt'." << endl;

    return 0;
}
