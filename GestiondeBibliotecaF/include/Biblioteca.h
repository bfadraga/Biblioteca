#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Libro.h"
#include "Solicitud.h"

class Biblioteca {
private:
    std::vector<Libro*> libros;
    std::vector<Solicitud*> solicitudes;
public:
    void agregarLibro(Libro* libro);
    std::vector<Libro*> getLibros() const;
    std::vector<Solicitud*> getSolicitudes() const;
    void buscarLibro(const std::string& titulo);
    void mostrarTodosLosLibros();
    void agregarSolicitud(Solicitud* solicitud);
    void devolverLibro(const std::string& titulo);
    void eliminarLibro(const std::string& titulo);
};

#endif // BIBLIOTECA_H
