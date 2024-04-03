#ifndef LIBRODIGITAL_H
#define LIBRODIGITAL_H

#include "Libro.h"

class LibroDigital : public Libro {
private:
    std::string formato;
public:
    LibroDigital(std::string titulo, std::string autor, std::string formato);
    ~LibroDigital() override;
    void mostrarInfo() const override;
};

#endif // LIBRODIGITAL_H
