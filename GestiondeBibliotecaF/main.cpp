#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Biblioteca.h"
#include "Libro.h"
#include "LibroDigital.h"
#include "Solicitud.h"
using namespace std;

int main() {
    Biblioteca biblioteca;
    int opcion;
    std::string titulo, autor, formato, nombreUsuario;
    cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    cout<< "           BIBLIOTECA\n";
    do {
        cout <<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        std::cout << "\n1. Agregar libro\n2. Buscar libro\n3. Mostrar todos los libros\n4. Pedir un libro\n5. Devolver un libro\n6. Eliminar Libro\n7. Salir\n";
        std::cin >> opcion;
        cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";

        switch (opcion) {
            case 1:
                std::cout << "Titulo: ";
                std::cin >> titulo;
                std::cout << "Autor: ";
                std::cin >> autor;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Formato (dejar en blanco para libro fisico): ";
                std::getline(std::cin, formato);
                if (formato.empty()) {
                    biblioteca.agregarLibro(new Libro(titulo, autor));
                } else {
                    biblioteca.agregarLibro(new LibroDigital(titulo, autor, formato));
                }
                break;
            case 2:
                std::cout << "Titulo del libro a buscar: ";
                std::cin >> titulo;
                biblioteca.buscarLibro(titulo);
                break;
            case 3:
                biblioteca.mostrarTodosLosLibros();
                break;
            case 4:
                std::cout << "Ingrese el titulo del libro a pedir: ";
                std::cin >> titulo;
                std::cout << "Ingrese su nombre: ";
                std::cin >> nombreUsuario;
                biblioteca.agregarSolicitud(new Solicitud(titulo, nombreUsuario));
                break;
            case 5:
                std::cout << "Ingrese el titulo del libro a devolver: ";
                std::cin >> titulo;
                biblioteca.devolverLibro(titulo);
                break;
            case 6:
                std::cout << "Ingrese el titulo del libro a eliminar: ";
                std::cin >> titulo;
                biblioteca.eliminarLibro(titulo);
                break;
            case 7:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    // Liberar memoria
    for (Libro* libro : biblioteca.getLibros()) {
        delete libro;
    }
    for (Solicitud* solicitud : biblioteca.getSolicitudes()) {
        delete solicitud;
    }

    return 0;
}


