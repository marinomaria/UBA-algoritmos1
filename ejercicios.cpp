#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
	bool resp = false;
	
	// TODO
	
	return resp;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector < int > resultado = {-1, -1, -1, -1, -1, -1};
	
	// TODO
	
	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};
	// TODO
	
  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	bool resp = false;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
	int resp = -1;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	join_hi resp = {make_pair(h,i)};
	
	// TODO
	
  return  resp;
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

    set<int> todas_las_diferencias = obtenerDiferenciasDeIngresosEntreHogares(hogares_con_ingresos);
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
void corregirRegion( eph_h & th, eph_i ti ) {
	
	// TODO
	
	return;
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector < int > resp = {};
	
	// TODO
	
	return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
		
	// TODO
	
	return resp;
}
