#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

int cantHabitantes (hogar const &h, eph_i const &ti){
    int habitantes = 0;
    for (individuo i: ti){
        if (i[INDCODUSU] == h[HOGCODUSU]){
            habitantes++;
        }
    }
    return habitantes;
}

int cantidadHogaresConCondiciones(eph_h const &th, eph_i const &ti){
    int hogares = 0;
    for (hogar const &h: th){

        if(h[II7] == 1 && h[II2] < cantHabitantes(h, ti) - 2){
            hogares++;
        }
    }
    return hogares;
}

int costoTotal(eph_h const &th, eph_i const &ti, int monto){
    return monto * cantidadHogaresConCondiciones(th,ti);
}
