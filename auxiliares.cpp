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
