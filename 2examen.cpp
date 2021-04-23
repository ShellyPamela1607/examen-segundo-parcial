// pr_c_mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Productos.h"
#include <iostream>
using namespace  std;

int main()
{
    string producto,id_marca, descripcion, imagen, precio_costo,  precio_venta,  fecha_ingreso;
    int existencia;

    cout << "Ingrese Producto:";
    getline(cin, producto);
    cout << "Ingrese Id Marca:";
    getline(cin, id_marca);
    cout << "Ingrese Descripcion:";
    getline(cin, descripcion);
    cout << "Ingrese Imagen:";
    getline(cin, imagen);
    cout << "Ingrese Precio Costo:";
    getline(cin, precio_costo);
    cout << "Ingrese Precio Venta:";
    getline(cin, precio_venta);
    cout << "Ingrese Existencia:";
    cin >> existencia;
    cin.ignore();
    cout << "Fecha Ingreso:";
    cin >> fecha_ingreso;

    Productos p = Productos(producto, id_marca, descripcion, imagen, precio_costo, precio_venta, fecha_ingreso);

    p.crear();
    p.leer();
    p.actualizar();
    p.eliminar();

    system("pause");
    return 0;

}
/*
#include <iostream>
#include <mysql.h>

using namespace std;

int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_examen", 3306, NULL, 0);
    
    if (conectar) {
        cout << "Conexion Exitosa" << endl;
    }
    else {
        cout << "Error al conectar" << endl;
    }
    
    
    system("pause");
    return 0;
}*/

