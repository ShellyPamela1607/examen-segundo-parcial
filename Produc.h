#pragma once
#include <iostream>
using namespace std;
class Produc
{
	// atributos
protected: string producto, descripcion, imagen, fecha_ingreso;
		 int existencia = 0;
		 // costructor
protected:
	Produc() {
	}
	Produc(string prod, string descrip, string imag, int exist, string fi) {
		producto = prod;
		descripcion = descrip;
		imagen = imag;
		existencia = exist;
		fecha_ingreso = fi;
	}




};