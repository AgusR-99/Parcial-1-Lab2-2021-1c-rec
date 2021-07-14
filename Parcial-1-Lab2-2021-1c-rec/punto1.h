#include <iostream>
using namespace std;
#include "clases.h"

void punto1();
int obtenerAnioContrato(int dniEmpleado);

void punto1() {
    int admin = 4;
    int pos = 0;
    char nombre[30];
    char apellido[30];
    int anioFiltro = 2020;
    Empleado regEmpleado;
    NoFirma regNoFirma;
    //Lectura secuencial
    while (regEmpleado.leerDeDisco(pos++)) {
        //Si el empleado es administrativo y es activo, realizar instrucciones
        if (regEmpleado.getCargo() == admin && regEmpleado.getEstado() == true) {
            //Si el empleado tiene un contrato no firmado en
            //2020, realizar instrucciones
            int dniEmpleado = regEmpleado.getDni();
            if (obtenerAnioContrato(dniEmpleado) != anioFiltro) {
                //Obtengo nombre y apellido
                strcpy(nombre, regEmpleado.getNombre());
                strcpy(apellido, regEmpleado.getApellido());
                //Grabo agregando registros en el EOF
                //Se presume que la clase esta declarada en el .h
                regNoFirma.setNombre(nombre);
                regNoFirma.setApellido(apellido);
                regNoFirma.setDni(dniEmpleado);
                regNoFirma.grabarEnDisco();
            }
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