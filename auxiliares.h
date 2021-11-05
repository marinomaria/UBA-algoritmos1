#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

int indiceEnTablaHogares(int idx, eph_h const &th);
void eliminarHogaresSinIndividuos(eph_i &ti, eph_h &th);
bool cumpleConBusqueda(individuo i, vector<pair<int, dato>> busqueda);

#endif //SOLUCION_AUXILIARES_H
