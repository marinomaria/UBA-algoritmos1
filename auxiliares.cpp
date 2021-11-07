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

float distanciaEuclideana(int lat1, int long1, int lat2, int long2){
    return sqrt(pow((lat1 - lat2), 2) + pow((long1 - long2), 2));
}

bool hogarEnAnillo(int dist_desde, int dist_hasta, pair<int, int> centro, hogar h){
    return dist_desde < distanciaEuclideana(centro.first, centro.second, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) &&
           distanciaEuclideana(centro.first, centro.second, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) <= dist_hasta;
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

bool esHogarTarget(hogar const &h, int r) {
    return (h[REGION] == r && h[IV1] == CASA && h[MAS_500] == 0);
}

float cantCasasTargetConHC(eph_h const &th, eph_i const &ti, int r) {
    float total = 0.0;
    for (hogar h : th) {
        if (esHogarTarget(h, r) && cantHabitantes(h, ti) > 3 * h[II2]) {
            total++;
        }
    }

    return total;
}

float cantCasasTarget(eph_h const &th, int r) {
    float total = 0.0;
    for (const hogar &h : th) {
        if (esHogarTarget(h, r)) {
            total++;
        }
    }
    return total;
}
