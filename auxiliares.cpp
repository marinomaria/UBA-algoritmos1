#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares Ejercicio 7
// TODO: abstraer la implementación del bubble sort para ser DRY compliant

void ordenarTablaHogares(vector<vector<int>> &th) {
    // Bubble sort
    for (int i = 0; i < th.size(); i++) {
        for (int j = th.size() - 1; j > i; j--) {
            if (
                    th[j][REGION] < th[j - 1][REGION] ||
                    (
                            th[j][REGION] == th[j - 1][REGION] &&
                            th[j][HOGCODUSU] < th[j - 1][HOGCODUSU]
                    )
                    )
            {
                swap(th[j], th[j - 1]);
            }
        }
    }
}

int indiceEnTablaHogares(int idx, eph_h const &th) {
    // Linear search
    int res = 0;
    for (int i = 0; i < th.size(); i++) {
        if (th[i][HOGCODUSU] == idx) {
            res = i;
        }
    }
    return res;
}

void ordenarTablaIndividuos(eph_i &ti, eph_h &th) {
    // Bubble sort
    for (int i = 0; i < ti.size(); i++) {
        for (int j = ti.size() - 1; j > i; j--) {
            if (
                    indiceEnTablaHogares(ti[j][HOGCODUSU], th) < indiceEnTablaHogares(ti[j - 1][HOGCODUSU], th) ||
                    (
                            indiceEnTablaHogares(ti[j][HOGCODUSU], th) == indiceEnTablaHogares(ti[j - 1][HOGCODUSU], th) &&
                            ti[j][COMPONENTE] < ti[j - 1][COMPONENTE]
                    )
                    )
            {
                swap(ti[j], ti[j - 1]);
            }
        }
    }
}