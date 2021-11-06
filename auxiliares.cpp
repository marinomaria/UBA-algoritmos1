#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares Ejercicio 7
void ordenarTablaHogares(vector<vector<int>> &th) {
    // Counting sort + Bubble Sort
    // th.size() = n; conteo.size() = m

    int max = 44;
    int min = 1;
    int rango = max - min + 1;

    vector<int> conteo(rango);
    eph_h ordenado(th.size());
    for (hogar &h : th)                                         // n iteraciones
        conteo[h[REGION] - min]++;

    for (int i = 1; i < conteo.size(); i++)                     // m iteraciones
        conteo[i] += conteo[i - 1];

    for (int i = th.size() - 1; i >= 0; i--) {                  // n iteraciones
        ordenado[conteo[th[i][REGION] - min] - 1] = th[i];
        conteo[th[i][REGION] - min]--;
    }

    for (int i = 0; i < th.size(); i++) {                       // n iteraciones
        th[i] = ordenado[i];
    }

    for (int i = 1; i < th.size(); i++) {                       // n - 1 iteraciones
        if (th[i][REGION] == th[i - 1][REGION] && th[i][HOGCODUSU] < th[i - 1][HOGCODUSU]) {
            swap(th[i], th[i - 1]);
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
                    indiceEnTablaHogares(ti[j][INDCODUSU], th) < indiceEnTablaHogares(ti[j - 1][INDCODUSU], th) ||
                    (
                            indiceEnTablaHogares(ti[j][INDCODUSU], th) == indiceEnTablaHogares(ti[j - 1][INDCODUSU], th) &&
                            ti[j][COMPONENTE] < ti[j - 1][COMPONENTE]
                    )
                )
            {
                swap(ti[j], ti[j - 1]);
            }
        }
    }
}