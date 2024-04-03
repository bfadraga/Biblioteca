#include "LibroDigital.h"

#include <iostream>

LibroDigital::LibroDigital(std::string titulo, std::string autor, std::string formato)
    : Libro(titulo, autor), formato(formato) {}

LibroDigital::~LibroDigital() {}

void LibroDigital::mostrarInfo() const {
    Libro::mostrarInfo();
    std::cout << "Formato: " << formato << std::endl;
}
