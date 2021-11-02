#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"


int cantHabitantes (hogar const &h, eph_i const &ti) {
    int habitantes = 0;
    for (individuo i : ti) {
        if (i[INDCODUSU] == h[HOGCODUSU]) {
            habitantes++;
        }
    }
    return habitantes;
}

bool esHogarTarget(hogar const &h, int r) {
    if (h[REGION] == r && h[IV1] == CASA && h[MAS_500] == 0) {
        return true;
    } else {
        return false;
    }
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