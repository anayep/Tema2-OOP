#include<iostream>
#include"MasinaDeSpalat.h"

masinaDeSpalat::masinaDeSpalat(int d, int sp, int cp, int t, bool i, bool D, bool u, bool g): masina(d,sp) {
    cmax = cp;
    tempSp = t;
    inchise = i;
    deschise = D;
    usoare = u;
    grele = g;
}

int masinaDeSpalat::getTempSp() {
    return tempSp;
}

void masinaDeSpalat::setTempSp(int x) {
    tempSp = x;
}

int masinaDeSpalat::getCapacitate() {
    return cmax;
}

void masinaDeSpalat::setCapacitate(int x) {
    cmax = x;
}

bool masinaDeSpalat::getInchise() {
    return inchise;
}

bool masinaDeSpalat::getDeschise() {
    return deschise;
}

bool masinaDeSpalat::getUsoare() {
    return usoare;
}

bool masinaDeSpalat::getGrele() {
    return grele;
}

void masinaDeSpalat::setInchise(bool x) {
    inchise = x;
}

void masinaDeSpalat::setDeschise(bool x) {
    deschise = x;
}

void masinaDeSpalat::setUsoare(bool x) {
    usoare = x;
}

void masinaDeSpalat::setGrele(bool x) {
    grele = x;
}

int masinaDeSpalat::getDurata() {
    return durata;
}

void masinaDeSpalat::setDurata(int x) {
    durata = x;
}

void masinaDeSpalat::afisInfo() {
    cout << "Durata masinii este " << durata << "s\n";
    cout << "Spatiul ocupat este " << spatiu << "\n";
    cout << "Capacitatea masinii de spalat este " << cmax << "g\n";
}
