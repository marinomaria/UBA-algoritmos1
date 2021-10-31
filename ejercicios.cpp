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

// TODO: abstraer la implementación del bubble sort para ser DRY compliant

void ordenarTablaHogares(vector<vector<int>> &th) {
    // Implementa un bubble sort para este caso específico
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
    // TODO: is binary search over a table sorted by another value doable?
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

void ordenarRegionYCODUSU (eph_h &th, eph_i &ti) {
	ordenarTablaHogares(th);
    ordenarTablaIndividuos(ti, th);
}


// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO

    return  resp;
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
