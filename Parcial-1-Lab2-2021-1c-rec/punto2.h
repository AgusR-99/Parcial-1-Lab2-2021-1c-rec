#include <iostream>
using namespace std;
#include "clases.h"

void punto2();
int obtenerAnioContrato(int dniEmpleado);

void punto2() {
    int pos = 0;
    int anioFiltro = 2020;
    Empleado regEmpleado;
    //Lectura secuencial
    while (regEmpleado.leerDeDisco(pos++)) {
        //Si el contrato es del anio pasado (2020) y el empleado esta activo, listar registro
        if (obtenerAnioContrato(regEmpleado.getDni()) == anioFiltro && regEmpleado.getEstado() == true) {
            regEmpleado.Mostrar();
        }
    }
}

int obtenerAnioContrato(int dni) {
    int pos = 0;
    Contrato regContrato;
    //Lectura secuencial
    while (regContrato.leerDeDisco(pos++)) {
        //Si hay coincidencia con el dni del empleado, devolver anio del contrato
        if (regContrato.getDniEmpleado() == dni) {
            return regContrato.fecha_contrato.getAnio();
        }
    }
}
