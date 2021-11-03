#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

int buscarEntero(vector<int> &arr, int x) {
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int buscarTuplaPorPrimerElemento(vector<pair<int, vector<hogar_con_ingresos>>> &arr, int x) {
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i].first == x) {
            return i;
        }
    }

    return -1;
}

vector<individuo> individuosDelHogar(eph_i &ti, hogar &h) {
    vector<individuo> res;
    for (individuo i: ti) {
        if(i[ItemInd::INDCODUSU] == h[ItemHogar::HOGCODUSU]) {
            res.push_back(i);
        }
    }

    return res;
}

int ingresosDelHogar(eph_i &ti, hogar &h) {
    int ingresos = 0;
    vector<individuo> inds = individuosDelHogar(ti, h);

    for (individuo i: inds) {
        ingresos += i[ItemInd::p47T] == -1 ? 0 : i[ItemInd::p47T];
    }

    return ingresos;
}

vector<hogar_con_ingresos> subseqMasLargaDeHogaresPorDifDeIngresos(vector<hogar_con_ingresos> &hci, int d) {
    vector<pair<int, vector<hogar_con_ingresos>>> m;
    pair<int, vector<hogar_con_ingresos>> tupla_inexistente = make_pair(-1, vector<hogar_con_ingresos>{});

    vector<hogar_con_ingresos> subseq_mas_larga;
    for (int i = 0; i < hci.size() ; i++) {
        // diferencia entre los ingresos del hogar y la diferencia recibida d
        int diff = hci[i].second - d;

        int tupla_diff_idx = buscarTuplaPorPrimerElemento(m, diff);
        pair<int, vector<hogar_con_ingresos>> tupla_diff = tupla_diff_idx != -1 ? m[tupla_diff_idx] : tupla_inexistente;

        // si existe una tupla con el valor de diff en su primer elemento
        if(tupla_diff.first != tupla_inexistente.first) {
            // agrego una tupla con el valor del ingreso del hogar como su primer elemento
            // y como segundo elemento los hogares con ingresos de tupla_diff + el hogar con ingreso actual
            vector<hogar_con_ingresos> c = tupla_diff.second;
            c.push_back(hci[i]);
            m.push_back(make_pair(hci[i].second, c));
        } else {
            // agrego una tupla con el valor del ingreso del hogar como su primer elemento
            // y como segundo elemento el hogar con ingreso actual
            m.push_back(make_pair(hci[i].second, vector<hogar_con_ingresos> {hci[i]}));
        }

        pair<int, vector<hogar_con_ingresos>> tupla_actual = m[buscarTuplaPorPrimerElemento(m, hci[i].second)];
        if(subseq_mas_larga.size() < tupla_actual.second.size()) {
            subseq_mas_larga = tupla_actual.second;
        }
    }

    return subseq_mas_larga;
}

vector<int> obtenerDiferenciasDeIngresosEntreHogares(vector<hogar_con_ingresos> &hogares_con_ingresos) {
    vector<int> todas_las_diferencias;

    // para cada hogar calculo la diferencia de ingresos con los otros hogares
    for (hogar_con_ingresos p1: hogares_con_ingresos) {
        for (hogar_con_ingresos p2: hogares_con_ingresos) {
            int diff = abs(p1.second - p2.second);
            if(todas_las_diferencias.size() == 0 || buscarEntero(todas_las_diferencias, diff) == -1) {
                todas_las_diferencias.push_back(diff);
            }
        }
    }

    return todas_las_diferencias;
}