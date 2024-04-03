#ifndef SOLICITUD_H
#define SOLICITUD_H

#include <string>

class Solicitud {
private:
    std::string tituloLibro;
    std::string nombreUsuario;
    std::string estado;
public:
    Solicitud(std::string tituloLibro, std::string nombreUsuario);
    void aceptarSolicitud();
    void rechazarSolicitud();
    void mostrarInfo() const;
    std::string getTituloLibro() const;
};

#endif // SOLICITUD_H
