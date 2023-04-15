//Jeferson Alexis Suchite Chavez 0909-22-12681
#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

void crearArchivos(int cantidad);
int contarArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void mostrarDetalles();
void buscarArchivosPorNombre(std::string nombreArchivo);

using namespace std;

int main()
{
    int cantidad;
    string nombreArchivo;

    cout << "Cuantos archivos quiere crear \n";
    cin >> cantidad;
    crearArchivos(cantidad);
    cout << contarArchivosDeDirectorio();
    cout << endl;

    cout << "Ingrese el nombre del archivo que desea buscar: \n";
    getline(cin, nombreArchivo);
    buscarArchivosPorNombre(nombreArchivo);

    listarArchivosDeDirectorio();
    mostrarDetalles();

    cout << "Ingrese el nombre del archivo que desea buscar: \n";
    getline(cin, nombreArchivo);
    buscarArchivosPorNombre(nombreArchivo);

    return 0;
}

void crearArchivos(int cantidad) {
    string nombreArchivo="archivo";
    int i= cantidad;
    for(i=0; i<cantidad; i++){
        ofstream file;
        file.open("C:/Users/Usuario/Desktop/Manejo de Archivos/" + nombreArchivo + to_string(i) +".txt");
        file << "Texto De Prueba\n";
        file << "Hola, Mucho Gusto\n";
        file << "Mi nombre es Jack\n";
        file.close();
    }
    cout<<"Archivos creados : " + to_string(i);
}


void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    hFind = FindFirstFile("C:/Users/Usuario/Desktop/Manejo de Archivos/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    {
        cout << findFileData.cFileName << '\n'; //El primer archivo
        // Listamos todos los archivos

        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/Usuario/Desktop/Manejo de Archivos/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    std::filesystem::directory_iterator directoryIterator("C:/Users/Usuario/Desktop/Manejo de Archivos/");
    for (const auto& entry : directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                      << file_size(entry.path()) << std::endl;
        }
    }
}

void buscarArchivosPorNombre(string nombreArchivo) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    hFind = FindFirstFile("C:/Users/Usuario/Desktop/Manejo de Archivos/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    {
        cout << "Resultados de la busqueda:\n\n";
        while (FindNextFile(hFind, &findFileData) != 0) {
            string archivo = findFileData.cFileName;
            if (archivo.find(nombreArchivo) != string::npos) {
                cout << archivo << '\n';
            }
        }
    }
}