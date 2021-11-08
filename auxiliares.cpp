#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares Problema 4

bool esHogarValido(hogar const &h) {
    return (0 < h[IV1] && h[IV1] < 3 && h[MAS_500] == 1);
}

bool viveEnHogarValido(int hogarID, eph_h const &th) {
    for (hogar const &h : th) {
        if (h[HOGCODUSU] == hogarID && esHogarValido(h)) {
            return true;
        }
    }
    return false;
}


float cantTrabajadores(eph_h const &th, eph_i const &ti) {
    float cantTrabajadores = 0;
    for (individuo const &i : ti) {
        if (i[ESTADO] == OCUPADO && viveEnHogarValido(i[INDCODUSU], th)) {
            cantTrabajadores++;
        }
    }
    return cantTrabajadores;
}

bool viveEnHogarTargetConOficina(int hogarID, eph_h const &th) {
    for (hogar const &h : th) {
        if (h[HOGCODUSU] == hogarID && esHogarValido(h) && h[II3] == 1) {
            return true;
        }
    }
    return false;
}

float haciendoTeleworking(eph_h const &th, eph_i const &ti) {
    float totalHaciendoTeleworking = 0;
    for (individuo const &i : ti) {
        if (i[ESTADO] == OCUPADO && viveEnHogarTargetConOficina(i[INDCODUSU], th) && i[PP04G] == EN_ESTE_HOGAR) {
            totalHaciendoTeleworking++;
        }
    }
    return totalHaciendoTeleworking;
}

float propTeleworking(eph_h const &th, eph_i const &ti){
    return cantTrabajadores(th, ti) != 0 ? haciendoTeleworking(th, ti) / cantTrabajadores(th, ti) : 0.0;
}
