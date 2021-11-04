#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"


float distanciaEuclideana(int lat1, int long1, int lat2, int long2){
    return sqrt(pow((lat1 - lat2), 2) + pow((long1 - long2), 2));
}

bool hogarEnAnillo(int dist_desde, int dist_hasta, pair<int, int> centro, hogar h){
    return dist_desde < distanciaEuclideana(centro.first, centro.second, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) &&
           distanciaEuclideana(centro.first, centro.second, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) <= dist_hasta;
}