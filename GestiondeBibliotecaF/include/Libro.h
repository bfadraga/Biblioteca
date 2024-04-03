#ifndef LIBRO_H
#define LIBRO_H
#include <string>


class Libro {
protected:
    std::string titulo;
    std::string autor;
    bool estaPrestado;
public:
    Libro(std::string titulo, std::string autor);
    virtual void mostrarInfo() const;
    virtual ~Libro();
    std::string getTitulo() const;
    bool isPrestado() const;
    void setPrestado(bool prestado);
    friend std::ostream& operator<<(std::ostream& os, const Libro& libro);
};


#endif // LIBRO_H
