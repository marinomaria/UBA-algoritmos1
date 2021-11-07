#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
	bool resp = true;
	
	// TODO
	
	return resp;
}

// Implementacion Problema 2
vector <int> histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector <int> res;

    for (hogar h: th) {
        bool es_casa = h[ItemHogar::IV1] == 1;
        if(es_casa && h[ItemHogar::REGION] == region) {
            int cant_hab = h[ItemHogar::IV2];
            if(res.size() < cant_hab) {
                vector<int> rellenador(cant_hab - res.size(), 0);
                res.insert(res.end(), rellenador.begin(), rellenador.end());
            }

            res[cant_hab-1]++;
        }
    }
	
	return res;
}

// Implementacion Problema 3
vector<pair<int, float>> laCasaEstaQuedandoChica (eph_h th, eph_i ti) {

    vector<pair<int,float>> res = {
                                    make_pair(1,-1.0),
                                    make_pair(40, -1.0),
                                    make_pair(41, -1.0),
                                    make_pair(42,-1.0),
                                    make_pair(43,-1.0),
                                    make_pair(44,-1.0)
                                };

    for (int i = 0; i < CANTIDAD_DE_REGIONES; i++) {
        int region = res[i].first;
        float cantidadCasasTarget = cantCasasTarget(th, region);
        if (cantidadCasasTarget != 0.0) {
            res[i].second = cantCasasTargetConHC(th, ti, region) / cantidadCasasTarget;
        } else {
            res[i].second = 0.0;
        }
    }
    return res;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	bool resp = false;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){

  return  costoTotal(th, ti, monto);
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	join_hi join;
    for (hogar const &h : th){
        for (individuo const &i : ti){
            if(h[HOGCODUSU] == i[INDCODUSU]){
                join.push_back(make_pair(h,i));
            }
        }
    }
  return  join;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
	
	// TODO
	
	return;
}

// Implementacion Problema 8
vector <hogar> muestraHomogenea( eph_h &th, eph_i &ti ){
    vector<hogar_con_ingresos> hogares_con_ingresos;
    for (hogar h: th) {
        int ingresos = ingresosDelHogar(ti, h);

        // ignoro hogares sin ingresos
        if(ingresos > 0) {
            hogares_con_ingresos.push_back(make_pair(h, ingresos));
        }
    }

    // ordeno crecientemente los hogares por ingresos
    sort(hogares_con_ingresos.begin(), hogares_con_ingresos.end(),
              [](const pair<hogar, int> &a, const pair<hogar, int> &b) -> bool {
                  return a.second < b.second;
              });

    vector<int> todas_las_diferencias = obtenerDiferenciasDeIngresosEntreHogares(hogares_con_ingresos);
    vector<hogar_con_ingresos> subseq_mas_larga;
    for (auto d: todas_las_diferencias) {
        vector<hogar_con_ingresos> s = subseqMasLargaDeHogaresPorDifDeIngresos(hogares_con_ingresos, d);
        if(s.size() > subseq_mas_larga.size()) {
            subseq_mas_larga = s;
        }
    }

    vector <hogar> res;
    for (auto &h: subseq_mas_larga) {
        res.push_back(h.first);
    }

    return  res;
}

// Implementacion Problema 9
void corregirRegion(eph_h & th, eph_i ti) {
    for (hogar &h : th) {
        if (h[REGION] == GBA) {
            h[REGION] = PAMPEANA;
        }
    }
}


// Implementacion Problema 10
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda){
    eph_h rth = {};
    eph_i rti = {};
    pair<eph_h, eph_i> res = make_pair(rth, rti);

    eph_i ti0 = ti;

    for (int i = 0; i < ti0.size(); i++) {
        if (cumpleConBusqueda(ti0[i], busqueda)) {
            // si todavía no agregamos el hogar a res
            if (indiceEnTablaHogares(ti0[i][INDCODUSU], res.first) == -1) {
                res.first.push_back(th[indiceEnTablaHogares(ti0[i][INDCODUSU], th)]);
            }

            res.second.push_back(ti0[i]);
            ti.erase(ti.begin() + i - res.second.size() + 1);
        }
    }

    eliminarHogaresSinIndividuos(ti, th);

    return res;
}

// Implementacion Problema 11
vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias){
    vector<int> res = {};

    for (int i = 0; i < distancias.size(); ++i) {
        int cont = 0;
        int dist_desde = i == 0 ? 0 : distancias[i - 1];
        int dist_hasta = distancias[i];

        for (hogar h: th) {
            if (hogarEnAnillo(dist_desde, dist_hasta, centro, h)) {
                cont++;
            }
        }

        res.push_back(cont);
    }

    return res;
}

