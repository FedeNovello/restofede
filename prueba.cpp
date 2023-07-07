#include <iostream>
#include <fstream>

using namespace std;

class Objeto {
public:
    int parametro;

    Objeto(int parametro) {
        this->parametro = parametro;
    }
};

class Nodo {
public:
    Objeto* objeto;
    Nodo* siguiente;

    Nodo(Objeto* objeto) {
        this->objeto = objeto;
        this->siguiente = nullptr;
    }
};

class ListaEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaEnlazada() {
        cabeza = nullptr;
        cola = nullptr;
    }

    void insertar(Objeto* objeto) {
        Nodo* nuevoNodo = new Nodo(objeto);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    void guardarEnArchivo(const string& nombreArchivo) {
        ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            Nodo* actual = cabeza;

            while (actual != nullptr) {
                archivo << "Parametro: " << actual->objeto->parametro << endl;
                actual = actual->siguiente;
            }

            archivo.close();
            cout << "Archivo guardado exitosamente." << endl;
        } else {
            cout << "Error al abrir el archivo." << endl;
        }
    }
};

int main() {
    ListaEnlazada lista;

    // Crear y agregar objetos a la lista
    Objeto* objeto1 = new Objeto(10);
    lista.insertar(objeto1);

    Objeto* objeto2 = new Objeto(20);
    lista.insertar(objeto2);

    Objeto* objeto3 = new Objeto(30);
    lista.insertar(objeto3);

    // Guardar la lista en un archivo
    lista.guardarEnArchivo("lista_objetos.txt");

    // Liberar memoria
    delete objeto1;
    delete objeto2;
    delete objeto3;

    return 0;
}
