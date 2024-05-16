#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string numeros = "numeros.txt";
    ifstream archivo(numeros);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << numeros << endl;
        return 1;
    }

    double suma = 0.0;
    int contador = 0;
    string linea;
    while (getline(archivo, linea)) {
        stringstream lineas(linea);
        double numero;
        while (lineas >> numero) {
            suma += numero;
            contador++;
        }
    }
    archivo.close();

    if (contador == 0) {
        cerr << "No se encontraron números en el archivo." << endl;
        return 1;
    }

    double promedio = suma / contador;

    string Promedio_total = "promedio.txt";
    
    ofstream archivoPromedio(Promedio_total);
    if (!archivoPromedio.is_open()) {
        cerr << "No se pudo abrir el archivo de promedio: " << Promedio_total << endl;
        return 1;
    }

    archivoPromedio<< "El promedio de los números en el archivo es: " << promedio << " de "
	<< contador << " elementos " << endl;
    archivoPromedio.close();

    cout << "Se ha calculado el promedio y se ha guardado en el archivo 'promedio.txt'." << endl;

    return 0;
}