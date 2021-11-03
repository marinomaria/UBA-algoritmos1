#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
vector<individuo> individuosDelHogar(eph_i &ti, hogar &h);
int ingresosDelHogar(eph_i &ti, hogar &h);
vector<hogar_con_ingresos> subseqMasLargaDeHogaresPorDifDeIngresos(vector<hogar_con_ingresos> &hci, int d);
vector<int> obtenerDiferenciasDeIngresosEntreHogares(vector<hogar_con_ingresos> &hogares_con_ingresos);

#endif //SOLUCION_AUXILIARES_H
