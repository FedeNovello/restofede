/*
PROYECTO RESTAURANTE
pizzas-lomos-empanadas-vevidas(alchool-gaseosa-agua)

A1 Ingresar codigo de empleado

-PANT.PRINCIPAL-

A MENU-PEDIDOS (objetos) colas
    1.NUEVO PEDIDO
        -Precios
        -Efectivo/tarjeta (descuento x usuario) =>monto
        -Delivery => direccion
        -Resto
    2.PENDIENTES
        1.resto -lista=> ver/borrar/volver..
        2.delivery-lista=> ver/borrar/volver..
        3.Volver..
    3.LISTA PEDIDOS REGISTRO
        -lista datos / volver
    5.volver..

B USUARIOS

    -CLIENTES
            -Nombre/apellido
            -DNI
            -Num.te
        1.NUEVO usuario.
        2.ELIMINAR usuario.
            Lista- eliminar/atras
        3.LISTA usuario.
            list => cambiar datos
        4.Volver..

    -EMPLEADOS
        1.NUEVO empleado.
            -Nombre/apellido
            -DNI
            -Num.tel
        2.ELIMINAR empleado.
            Lista- eliminar/atras
        3.LISTA de empleados.
            list => cambiar datos
        5.Volver..

    -ADMINISTRADOR

D-MENU

*/

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <fstream>
using namespace std;
// Clases

class Usuario
{
public:
    // atributos
    string nombre;
    string apellido;
    int id;
    int dni;
    int telefono;
    // metodos
    Usuario(string n, string a, int d, int tel, int ide)
    {
        this->nombre = n;
        this->apellido = a;
        this->dni = d;
        this->telefono = tel;
        this->id = ide;
    }
    string setUsuario()
    {
        return "Nombre: " + this->nombre + "\nApellido: " + this->apellido + "\nDni: " + to_string(this->dni) + "\nID: " + to_string(this->id) + "\nTelefono: " + to_string(this->telefono);
    }
};

//
class Nodo
{
public:
    Usuario *usuario;
    Nodo *siguiente;

    Nodo(Usuario *usuario)
    {
        this->usuario = usuario;
        this->siguiente = nullptr;
    }
};

class ListaEnlazada
{
private:
    Nodo *cabeza;
    Nodo *cola;

public:
    ListaEnlazada()
    {
        cabeza = nullptr;
        cola = nullptr;
    }

    void insertar(Usuario *usuario)
    {
        Nodo *nuevoNodo = new Nodo(usuario);
        if (cabeza == nullptr)
        {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else
        {
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    void guardarArchivo(const string &nombreArchivo)
    {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open())
        {
            Nodo *actual = cabeza;
            while (actual != nullptr)
            {
                archivo << "Nombre: " << actual->usuario->nombre << endl;
                archivo << "Apellido: " << actual->usuario->apellido << endl;
                archivo << "DNI: " << actual->usuario->dni << endl;
                archivo << "Telefono: " << actual->usuario->telefono << endl;
                archivo << "ID: " << actual->usuario->id << endl;
                actual = actual->siguiente;
            }
            archivo.close();
            cout << "Archivo guardado exitosamente." << endl;
        }
        else
        {
            cout << "Error al abrir el archivo." << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    ListaEnlazada lista;
    int opcion = 1, telefono = 0, ide = 0, dni = 0;
    std::string nombre = "", apellido = "";
    // std::string comida[] = {"lomo clasico", "Lomo atun", "Lomo vegetariano", "hamburguesa clasica", "hamburguesa atun", "Hamburguesa vegana", "Pizza mozarella", "Pizza napolitana", "Pizza de atun", "Piza de anchoas"};
    // std::string vevida[] = {"Cerveza", "Vino", "Coca-cola", "fanta", "Agua con gas", "Agua sin gas"};
    do
    {
        cout << "1.USUARIOS\n"
             << endl;
        cout << "2.PEDIDOS\n"
             << endl;
        cout << "3.Menu\n"
             << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "1.CLIENTES\n"
                 << endl;
            cout << "2.EMPLEADOS\n"
                 << endl;
            cout << "3.ADMINISTRADOR\n"
                 << endl;
            cout << "4.Volver...\n"
                 << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "Nuevo cliente\n"
                     << endl;
                cout << "Eliminar cliente\n"
                     << endl;
                cout << "Lista de clientes\n"
                     << endl;
                cout << "Volver...\n"
                     << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                {
                    cout << "Ingrese los datos del cliente\n"
                         << endl;
                    cout << "Ingrese el NOMBRE:\n"
                         << endl;
                    cin >> nombre;
                    cout << "Ingrese el APELLIDO\n"
                         << endl;
                    cin >> apellido;
                    cout << "Ingrese el DNI\n"
                         << endl;
                    cin >> dni;
                    cout << "Ingrese el TELEFONO\n"
                         << endl;
                    cin >> telefono;
                    ide++;
                    Usuario *usuario1 = new Usuario(nombre, apellido, dni, telefono, ide);
                    lista.insertar(usuario1);
                    lista.guardarArchivo("Clientes.txt");
                    delete usuario1;
                    break;
                }
                case 2:
                    // func eliminar cliente
                    break;
                case 3:
                    // func lista de clientes
                    break;
                case 4:
                    break;
                default:
                    cout << "Error.Numero ingrsado no valido" << endl;
                    break;
                }
                break;
            case 2:
                cout << "Nuevo empleado\n"
                     << endl;
                cout << "Eliminar empleado\n"
                     << endl;
                cout << "Lista de empleado\n"
                     << endl;
                cout << "Volver...\n"
                     << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                {
                    cout << "Ingrese los datos del empleado\n"
                         << endl;
                    cout << "Ingrese el NOMBRE:\n"
                         << endl;
                    cin >> nombre;
                    cout << "Ingrese el APELLIDO\n"
                         << endl;
                    cin >> apellido;
                    cout << "Ingrese el DNI\n"
                         << endl;
                    cin >> dni;
                    cout << "Ingrese el TELEFONO\n"
                         << endl;
                    cin >> telefono;
                    ide++;
                    Usuario *usuario1 = new Usuario(nombre, apellido, dni, telefono, ide);
                    lista.insertar(usuario1);
                    lista.guardarArchivo("Empleados.txt");
                    delete usuario1;
                    break;
                }
                break;
                case 2:
                    // func eliminar empleadobash: git: command not found.
                    break;
                case 3:
                    // func lista de empleado
                    break;
                case 4:
                    break;
                default:
                    cout << "Error.Numero ingrsado no valido" << endl;
                    break;
                }
                break;
            case 3:
                cout << "Nuevo administrados\n"
                     << endl;
                cout << "Eliminar administrador\n"
                     << endl;
                cout << "Lista de administrador\n"
                     << endl;
                cout << "Volver...\n"
                     << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                {
                    cout << "Ingrese los datos del administrador\n"
                         << endl;
                    cout << "Ingrese el NOMBRE:\n"
                         << endl;
                    cin >> nombre;
                    cout << "Ingrese el APELLIDO\n"
                         << endl;
                    cin >> apellido;
                    cout << "Ingrese el DNI\n"
                         << endl;
                    cin >> dni;
                    cout << "Ingrese el TELEFONO\n"
                         << endl;
                    cin >> telefono;
                    ide++;
                    Usuario *usuario1 = new Usuario(nombre, apellido, dni, telefono, ide);
                    lista.insertar(usuario1);
                    lista.guardarArchivo("Administradores.txt");
                    delete usuario1;
                    break;
                }
                break;
                case 2:
                    // func eliminar administrador
                    break;
                case 3:
                    // func lista de administrador
                    break;
                case 4:
                    break;
                default:
                    cout << "Error.Numero ingrsado no valido" << endl;
                    break;
                }
                break;
            default:
                cout << "Error.Numero ingrsado no valido" << endl;
                break;
            }
            break;
        case 2:
            cout << "Nuevo pedido\n"
                 << endl;
            cout << "Eliminar pedido\n"
                 << endl;
            cout << "3.Lista de pedido\n"
                 << endl;
            cout << "4.Volver...\n"
                 << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                // funcion nuevo pedidio
                break;
            case 2:
                // funcion eliminar pedidio
                break;
            case 3:
                // funcion lista pedidio
                break;
            case 4:
                break;
            default:
                cout << "Error.Numero ingrsado no valido" << endl;
                break;
            }
            break;
        case 3:
            cout << "Desplegar menu" << endl;
            break;
        }
    } while (opcion != 0);
}