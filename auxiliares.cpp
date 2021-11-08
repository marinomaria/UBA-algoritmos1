#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares Generales

int cantHabitantes(hogar const &h, eph_i const &ti){
    int habitantes = 0;
    for (individuo i: ti){
        if (i[INDCODUSU] == h[HOGCODUSU]){
            habitantes++;
        }
    }
    return habitantes;
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

// Auxiliares Problema 1

bool esMatrizNoVacia(vector<vector<dato>> m) {
    bool res = true;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
            if(m[i].size() == 0 || m[i].size() != m[j].size()) {
                res = false;
            }
        }
    }
    return m.size() != 0 && res;
}

bool habitantesCorrectos(eph_h const &th, eph_i const &ti){
    for (hogar const &h : th){
        if (cantHabitantes(h, ti) == 0 || cantHabitantes(h, ti) > 21) {
            return false;
        }
    }
    return true;
}

bool hayIndividuosSinHogares(eph_h const &th, eph_i const &ti) {
    for (individuo const &i : ti) {
        if (indiceEnTablaHogares(i[INDCODUSU], th) == -1) {
            return true;
        }
    }
    return false;
}
  
bool mismoCodusuYComponente(individuo i1, individuo i2) {
    return i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] == i2[COMPONENTE];
}

bool hayIndRepetidos(eph_i const &ti) {
    for (int i = 0; i < ti.size(); ++i) {
        for (int j = i+1; j < ti.size(); ++j) {
            if(mismoCodusuYComponente(ti[i], ti[j])){
                return true;
            }
        }
    }

    return false;
}

bool hayHogaresRepetidos(eph_h const &th) {
    for (int i = 0; i < th.size(); ++i) {
        for (int j = i + 1; j < th.size(); ++j) {
            if (th[i][HOGCODUSU] == th[j][HOGCODUSU]) {
                return true;
            }
        }
    }
    return false;
}

bool mismoAñoYTrimestre(eph_h const &th, eph_i const &ti) {
    dato año = th[0][HOGANIO];
    dato trimestre = th[0][HOGTRIMESTRE];

    for (hogar const &h : th) {
        if (h[HOGANIO] != año || h[HOGTRIMESTRE] != trimestre) {
            return false;
        }
    }

    for (individuo const &i : ti) {
        if (i[INDANIO] != año || i[INDTRIMESTRE] != trimestre) {
            return false;
        }
    }

    return true;
}

bool cantidadValidaDormitorios(eph_h const &th) {
    for (hogar const &h: th) {
        if(h[IV2] < h[II2]) {
            return false;
        }
    }

    return true;
}

bool enRango(int n, int min, int max) {
    return (min < n && n < max);
}

bool estanEnRangoHogares(eph_h const &th){
    for (hogar const &h : th) {
        if (h[HOGCODUSU] < 0 || !enRango(h[HOGTRIMESTRE], 0, 5) || !enRango(h[II7], 0, 4) ||
            (h[REGION] != 1 && !enRango(h[REGION], 39, 45)) || !enRango(h[MAS_500], -1, 2) ||
            !enRango(h[IV1],0,6) || h[IV2] < 0 || h[II2] < 1 || !enRango(h[II3], 0, 3)) {
            return false;
        }
    }
    return true;
}

bool estanEnRangoIndividuos(eph_i const &ti){
    for (individuo const &i : ti) {
        if (i[INDCODUSU] < 0 || i[COMPONENTE] < 0 || !enRango(i[INDTRIMESTRE], 0, 5) ||
            !enRango(i[CH4], 0, 3) || i[CH6] < 0 || !enRango(i[ESTADO], -2, 2) ||
            !enRango(i[CAT_OCUP], -1, 5) || !enRango(i[PP04G], -1, 11) || i[p47T] < -1 ||
            !enRango(i[NIVEL_ED], -1, 2)) {
            return false;
        }
    }
    return true;
}

// Auxiliares Problema 3

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

// Auxiliares Problema 4

bool esHogarValido(hogar const &h) {
    return (0 < h[IV1] && h[IV1] < 3 && h[MAS_500] == 1);
}

bool viveEnHogarValido(int hogarID, eph_h const &th) {
    for (hogar const &h : th) {
        if (h[HOGCODUSU] == hogarID && esHogarValido(h)) {
            return true;
        }
    }
    return false;
}

float cantTrabajadores(eph_h const &th, eph_i const &ti) {
    float cantTrabajadores = 0;
    for (individuo const &i : ti) {
        if (i[ESTADO] == OCUPADO && viveEnHogarValido(i[INDCODUSU], th)) {
            cantTrabajadores++;
        }
    }
    return cantTrabajadores;
}

bool viveEnHogarTargetConOficina(int hogarID, eph_h const &th) {
    for (hogar const &h : th) {
        if (h[HOGCODUSU] == hogarID && esHogarValido(h) && h[II3] == 1) {
            return true;
        }
    }
    return false;
}

float haciendoTeleworking(eph_h const &th, eph_i const &ti) {
    float totalHaciendoTeleworking = 0;
    for (individuo const &i : ti) {
        if (i[ESTADO] == OCUPADO && viveEnHogarTargetConOficina(i[INDCODUSU], th) && i[PP04G] == EN_ESTE_HOGAR) {
            totalHaciendoTeleworking++;
        }
    }
    return totalHaciendoTeleworking;
}

float propTeleworking(eph_h const &th, eph_i const &ti){
    return cantTrabajadores(th, ti) != 0 ? haciendoTeleworking(th, ti) / cantTrabajadores(th, ti) : 0.0;
}


// Auxiliares Problema 5

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

// Auxiliares Problema 8

vector<individuo> individuosDelHogar(eph_i &ti, hogar &h) {
    vector<individuo> res;
    for (individuo i: ti) {
        if(i[INDCODUSU] == h[HOGCODUSU]) {
            res.push_back(i);
        }
    }

    return res;
}

int ingresosDelHogar(eph_i &ti, hogar &h) {
    int ingresos = 0;
    vector<individuo> inds = individuosDelHogar(ti, h);

    for (individuo i: inds) {
        ingresos += i[p47T] == -1 ? 0 : i[p47T];
    }

    return ingresos;
}

int buscarEntero(vector<int> &arr, int x) {
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] == x) {
            return i;
        }
    }

    return -1;
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

int buscarTuplaPorPrimerElemento(vector<pair<int, vector<hogar_con_ingresos>>> &arr, int x) {
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i].first == x) {
            return i;
        }
    }

    return -1;
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

// Auxiliares Problema 10

bool cumpleConBusqueda(individuo i, vector<pair<int, dato>> busqueda){
    for (pair<int, dato> &b: busqueda) {
        if(i[b.first] != b.second) {
            return false;
        }
    }

    return true;
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

// Auxiliares Problema 11

float distanciaEuclideana(int lat1, int long1, int lat2, int long2){
    return sqrt(pow((lat1 - lat2), 2) + pow((long1 - long2), 2));
}

bool hogarEnAnillo(int dist_desde, int dist_hasta, pair<int, int> centro, hogar h){
    return dist_desde < distanciaEuclideana(centro.first, centro.second, h[HOGLATITUD], h[HOGLONGITUD]) &&
           distanciaEuclideana(centro.first, centro.second, h[HOGLATITUD], h[HOGLONGITUD]) <= dist_hasta;
}
