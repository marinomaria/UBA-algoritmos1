#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

vector<individuo> individuosDelHogar(eph_i &ti, hogar &h);
int ingresosDelHogar(eph_i &ti, hogar &h);
vector<hogar_con_ingresos> subseqMasLargaDeHogaresPorDifDeIngresos(vector<hogar_con_ingresos> &hci, int d);
vector<int> obtenerDiferenciasDeIngresosEntreHogares(vector<hogar_con_ingresos> &hogares_con_ingresos);
int costoTotal(eph_h const &th, eph_i const &ti,int monto);
bool hogarEnAnillo(int dist_desde, int dist_hasta, pair<int, int> centro, hogar h);
int indiceEnTablaHogares(int idx, eph_h const &th);
void eliminarHogaresSinIndividuos(eph_i &ti, eph_h &th);
bool cumpleConBusqueda(individuo i, vector<pair<int, dato>> busqueda);
float cantCasasTargetConHC(eph_h const &th, eph_i const &ti, int r);
float cantCasasTarget(eph_h const &th, int r);

#endif //SOLUCION_AUXILIARES_H