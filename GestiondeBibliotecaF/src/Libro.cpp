#include "Libro.h"
#include <string>
#include <iostream>



    Libro::Libro(std::string titulo, std::string autor) : titulo(titulo), autor(autor), estaPrestado(false) {}

    void Libro::mostrarInfo() const {
        std::cout << "Titulo: " << titulo << "\nAutor: " << autor << std::endl;
    }

    Libro::~Libro() {}

    std::string Libro::getTitulo() const { return titulo; }

    bool Libro::isPrestado() const { return estaPrestado; }

    void Libro::setPrestado(bool prestado) { estaPrestado = prestado; }

    std::ostream& operator<<(std::ostream& os, const Libro& libro) {
    libro.mostrarInfo();
    return os;
    }
