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

int indiceEnTablaHogares(int idx, eph_h const &th) {
    // Linear search
    int res = -1;
    for (int i = 0; i < th.size(); i++) {
        if (th[i][HOGCODUSU] == idx) {
            res = i;
        }
    }
    return res;
}

void eliminarHogaresSinIndividuos(eph_i &ti, eph_h &th){
    eph_h th0 = th;
    int cant_borrados = 0;
    for (int i = 0; i < th0.size(); ++i) {
        if(cantHabitantes(th0[i], ti) == 0) {
            th.erase(th.begin() + i - cant_borrados);
            cant_borrados++;
        }
    }
}

bool cumpleConBusqueda(individuo i, vector<pair<int, dato>> busqueda){
    for (pair<int, dato> &b: busqueda) {
        if(i[b.first] != b.second) {
            return false;
        }
    }

    return true;
}


