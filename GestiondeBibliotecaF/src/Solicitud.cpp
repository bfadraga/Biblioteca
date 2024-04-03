#include "Solicitud.h"
#include <iostream>

Solicitud::Solicitud(std::string tituloLibro, std::string nombreUsuario)
    : tituloLibro(tituloLibro), nombreUsuario(nombreUsuario), estado("pendiente") {}

void Solicitud::aceptarSolicitud() {
    estado = "aceptada";
}

void Solicitud::rechazarSolicitud() {
    estado = "rechazada";
}

void Solicitud::mostrarInfo() const {
    std::cout << "Titulo del libro: " << tituloLibro << "\nNombre del usuario: " << nombreUsuario << "\nEstado: " << estado << std::endl;
}

std::string Solicitud::getTituloLibro() const { return tituloLibro; }
