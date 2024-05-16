#include <iostream>
#include <string>

using namespace std;

//Definición de la funcion generarLenguaje con comentarios explicativos
void generarLenguaje(string alfabeto, string prefijo, int longitudMaxima) {
//Verifica si la longitud del prefijo supera la longitud máxima permitida
    if (prefijo.length() > longitudMaxima) {
//Si si, termina la función sin agregar mas palabras al lenguaje
        return;
    }

//Imprime el prefijo actual, que es una palabra en el lenguaje
    cout << prefijo << endl;

//Genera nuevas palabras agregando cada caracter del alfabeto al prefijo
    for (char c : alfabeto) {
        // Paso 2d: Concatena el caracter actual al prefijo
        string nuevoPrefijo = prefijo + c;
//Llama recursivamente a la funcion generarLenguaje con el nuevo prefijo
        generarLenguaje(alfabeto, nuevoPrefijo, longitudMaxima);
    }
}

int main() {
    int n;

//Solicita al usuario la cantidad de elementos del alfabeto
cout << "Ingrese la cantidad de elementos del alfabeto Σ: ";
    cin >> n;

    string alfabeto;

//Solicita al usuario los elementos del alfabeto
cout << "Ingrese los " << n << " elementos del alfabeto Σ separados por espacios: ";
    for (int i = 0; i < n; ++i) {
        string elemento;
        cin >> elemento;
        alfabeto += elemento;
    }


//Llama a la funcion generarLenguaje para generar e imprimir todas las palabras del lenguaje
    generarLenguaje(alfabeto, "", 5);
    
//Imprime la cantidad minima de palabras en el lenguaje, que siempre es 1
    cout << "Cantidad minima de palabras en el lenguaje: 1" << endl;

//Calcula la cantidad maxima de palabras en el lenguaje, que es n^5 si la longitud maxima es 5
    int maxPalabras = 1;
    for (int i = 0; i < 5; ++i) {
        maxPalabras *= n;
    }
//Imprime la cantidad maxima de palabras en el lenguaje
cout << "Cantidad maxima de palabras en el lenguaje: " << maxPalabras << endl;

    return 0;
}



