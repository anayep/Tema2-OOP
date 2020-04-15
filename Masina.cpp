#include<iostream>
#include<vector>
#include"Masina.h"

masina::masina(int d, int sp) {
    durata = d;
    spatiu = sp;
}

masina::~masina() {
    m.clear();
    m.shrink_to_fit();
}

Haina& masina::operator[](const int poz) {
    return m[poz];
}

int masina::getSize() {
    return m.size();
}

void masina::addHaina(Haina& x) {
    m.push_back(x);
}

int masina::getSpatiu() {
    return spatiu;
}

void masina::setSpatiu(int x) {
    spatiu += x;
}

void masina::afisInfo() {
    cout << "Durata masinii este " << durata << "s\n";
    cout << "Spatiul ocupat este " << spatiu << "g\n";
}

const int masina::getDurataSpalat() {
    return DURATA_SPALAT;
}

const int masina::getDurataStors() {
    return DURATA_STORS;
}

const int masina::getDurataUscat() {
    return DURATA_USCAT;
}

const int masina::getDurataCamasa() {
    return DURATA_CAMASA;
}

const int masina::getDurataRochie() {
    return DURATA_ROCHIE;
}

const int masina::getDurataPantaloni() {
    return DURATA_PANTALONI;
}

const int masina::getDurataCostum() {
    return DURATA_COSTUM;
}

const int masina::getCapacitateSpalat() {
    return CAPACITATE_SPALAT;
}

const int masina::getCapacitateStors() {
    return CAPACITATE_STORS;
}

const int masina::getCapacitateUscat() {
    return CAPACITATE_USCAT;
}

const int masina::getCantDetUsoare() {
    return CANT_DET_USOARE;
}

const int masina::getCantDetGrele() {
    return CANT_DET_GRELE;
}

const int masina::getTempSpalat() {
    return TEMP_SPALAT;
}

const int masina::TEMP_SPALAT = 70;
const int masina::DURATA_SPALAT = 500;
const int masina::DURATA_STORS = 600;
const int masina::DURATA_USCAT = 1000;
const int masina::DURATA_CAMASA = 120;
const int masina::DURATA_ROCHIE = 100;
const int masina::DURATA_PANTALONI = 90;
const int masina::DURATA_COSTUM = 240;
const int masina::CAPACITATE_SPALAT = 1500;
const int masina::CAPACITATE_STORS = 1000;
const int masina::CAPACITATE_USCAT = 3;
const int masina::CANT_DET_USOARE = 40;
const int masina::CANT_DET_GRELE = 100;
