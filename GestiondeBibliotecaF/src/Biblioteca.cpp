#include "Biblioteca.h"
#include <iostream>
#include <algorithm>

void Biblioteca::agregarLibro(Libro* libro) {
    libros.push_back(libro);
}

std::vector<Libro*> Biblioteca::getLibros() const { return libros; }

std::vector<Solicitud*> Biblioteca::getSolicitudes() const { return solicitudes; }

void Biblioteca::buscarLibro(const std::string& titulo) {
    for (Libro* libro : libros) {
        if (libro->getTitulo() == titulo) {
            std::cout << *libro << std::endl;
            return;
        }
    }
    std::cout << "Libro no encontrado." << std::endl;
}

void Biblioteca::mostrarTodosLosLibros() {
    for (Libro* libro : libros) {
        std::cout << *libro << std::endl;
    }
}

void Biblioteca::agregarSolicitud(Solicitud* solicitud) {
    for (Libro* libro : libros) {
        if (libro->getTitulo() == solicitud->getTituloLibro() && !libro->isPrestado()) {
            libro->setPrestado(true);
            solicitud->aceptarSolicitud();
            std::cout << "Solicitud aceptada. El libro ha sido prestado.\n";
            return;
        }
    }
    solicitud->rechazarSolicitud();
    std::cout << "Solicitud rechazada. El libro ya está prestado.\n";
}

void Biblioteca::devolverLibro(const std::string& titulo) {
    for (Libro* libro : libros) {
        if (libro->getTitulo() == titulo) {
            libro->setPrestado(false);
            std::cout << "Libro devuelto con exito.\n";
            return;
        }
    }
    std::cout << "Libro no encontrado.\n";
}

void Biblioteca::eliminarLibro(const std::string& titulo) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if ((*it)->getTitulo() == titulo) {
            delete *it;
            libros.erase(it);
            return;
        }
    }
    std::cout << "Libro no encontrado." << std::endl;
}
