#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esMatrizNoVacia(vector<vector<dato>> m);
bool habitantesCorrectos(eph_h const &th, eph_i const &ti);
bool hayIndividuosSinHogares(eph_h const &th, eph_i const &ti);
bool hayIndRepetidos(vector<individuo> const &ti);
bool hayHogaresRepetidos(eph_h const &th);
bool mismoAnioYTrimestre(eph_h const &th, eph_i const &ti);
bool cantidadValidaDormitorios(eph_h const &th);
bool estanEnRangoHogares(eph_h const &th);
bool estanEnRangoIndividuos(eph_i const &ti);

float cantCasasTarget(eph_h const &th, int r);
float cantCasasTargetConHC(eph_h const &th, eph_i const &ti, int r);

float propTeleworking(eph_h const &th, eph_i const &ti);

int costoTotal(eph_h const &th, eph_i const &ti,int monto);

void ordenarTablaHogares(vector<vector<int>> &th);
void ordenarTablaIndividuos(eph_i &ti, eph_h &th);

int ingresosDelHogar(eph_i &ti, hogar &h);
vector<int> obtenerDiferenciasDeIngresosEntreHogares(vector<hogar_con_ingresos> &hogares_con_ingresos);
vector<hogar_con_ingresos> subseqMasLargaDeHogaresPorDifDeIngresos(vector<hogar_con_ingresos> &hci, int d);
void bubbleSortHogaresConIngresos(vector<hogar_con_ingresos> &hogares_con_ingresos);

bool cumpleConBusqueda(individuo i, vector<pair<int, dato>> const &busqueda);
int indiceEnTablaHogares(int idx, eph_h const &th);
void eliminarHogaresSinIndividuos(eph_i &ti, eph_h &th);

bool hogarEnAnillo(int dist_desde, int dist_hasta, pair<int, int> centro, hogar h);

#endif //SOLUCION_AUXILIARES_H
