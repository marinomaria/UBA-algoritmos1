#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"


vector<individuo> individuosDelHogar(eph_i &ti, hogar &h) {
    vector<individuo> res = {};
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
    map<int, vector<hogar_con_ingresos>> m;

    vector<hogar_con_ingresos> subseq_mas_larga = {};
    for (int i = 0; i < hci.size() ; i++) {
        int diff = hci[i].second - d;

        // si existe una key con el valor de diff en el map
        if(m.find(diff) != m.end()) {
            vector<hogar_con_ingresos> c = m[diff];
            c.push_back(hci[i]);
            m[hci[i].second] = c;
        } else {
            m[hci[i].second] = {hci[i]};
        }

        if(subseq_mas_larga.size() < m[hci[i].second].size()) {
            subseq_mas_larga = m[hci[i].second];
        }
    }

    return subseq_mas_larga;
}

set<int> obtenerDiferenciasDeIngresosEntreHogares(vector<hogar_con_ingresos> &hogares_con_ingresos) {
    set<int> todas_las_diferencias = {};

    // para cada hogar calculo la diferencia de ingresos con los otros hogares
    for (hogar_con_ingresos p1: hogares_con_ingresos) {
        for (hogar_con_ingresos p2: hogares_con_ingresos) {
            todas_las_diferencias.insert(abs(p1.second - p2.second));
        }
    }

    return todas_las_diferencias;
}