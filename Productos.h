
#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Produc.h"


using namespace std;

class Productos : Produc {
private: string precio_costo, precio_venta, id_marca;
	   // constructor
public:
	Productos() {
	}
	Productos(string prod, string descrip, string imag, int exist, string fi, string pc, string pv, string idm) : Produc(prod, descrip, imag, exist,fi) {
		id_marca = idm;
		precio_costo = pc;
		precio_venta = pv;
	}

	// METODOS
	//set (modificar)

	void setProducto(string prod) { producto = prod; }
	void setDescripcion(string descrip) { descripcion = descrip; }
	void setMarca(string idm) { id_marca = idm; }
	void setImagen(string imag) { imagen = imag; }
	void setPrecioCosto(string pc) { precio_costo = pc; }
	void setPrecioVenta(string pv) { precio_venta = pv; }
	void setExistencia(int exist) { existencia = exist; }
	void setFecha_Ingreso(int fi) { fecha_ingreso = fi; }
	//get (mostrar)
	string getProducto() { return producto; }
	string getDescripcion() { return descripcion; }
	string getMarca() { return id_marca; }
	string getImagen() { return imagen; }
	string getPrecioCosto() { return precio_costo; }
	string getPrecioVenta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_Ingreso() { return fecha_ingreso; }

	// metodo
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idproducto;

			cout << "Ingrese ID del producto que desea eliminar: ";
			cin >> idproducto;
			string eliminar = "delete from productos where idProducto = (" + idproducto + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa" << endl;
			}
			else {
				cout << "Error al Eliminar" << endl;
			}
		}
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idproducto, productoaux, id_marcaaux, descripcionaux, imagenaux, precio_costoaux, precio_ventaaux, fecha_ingresoaux;
			int existenciaaux;

			cout << "Ingrese ID del producto que desea actualizar: ";
			cin >> idproducto;


			cout << "Ingrese Producto:";
			getline(cin, productoaux);
			cout << "Ingrese Id Marca:";
			getline(cin, id_marcaaux);
			cout << "Ingrese Descripcion:";
			getline(cin, descripcionaux);
			cout << "Ingrese Imagen:";
			getline(cin, imagenaux);
			cout << "Ingrese Precio Costo:";
			getline(cin, precio_costoaux);
			cout << "Ingrese Precio Venta:";
			getline(cin, precio_ventaaux);
			cout << "Ingrese Existencia:";
			cin >> existenciaaux;
			cin.ignore();
			cout << "Fecha Ingreso:";
			cin >> fecha_ingresoaux;
			string eaux = to_string(existenciaaux);
			string  actualizar = "UPDATE productos SET idProducto= " + idproducto + " (producto,idmarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES ('" + productoaux + "','" + id_marcaaux + "','" + descripcionaux + "','" + imagenaux + "','" + precio_costoaux + "','" + precio_ventaaux + "'," + eaux + ",'" + fecha_ingresoaux + "')";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa " << endl;
			}
			else {
				cout << "Error al Actualizar" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string e = to_string(existencia);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(producto,idmarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES ('" + producto + "','" + id_marca + "','" + descripcion + "','" + imagen + "','" + precio_costo + "','" + precio_venta + "'," + e + ",'" + fecha_ingreso + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de los Productos ------------" << endl;
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};