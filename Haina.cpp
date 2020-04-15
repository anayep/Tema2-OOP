#include<iostream>
#include"Haina.h"
using namespace std;

Haina::Haina(string s, int g, int t, char c) {
    istoric = "";
    nume = s;
    greutate = g;
    temp = t;
    culoare = c;
    timp = 0;
    poz = 0;
}

int Haina::getId() {
    return id;
}

void Haina::nextId() {
    ++Haina::id;
}

int Haina::getIdHaina() {
    return idHaina;
}

void Haina::setIdHaina(int x) {
    idHaina = x;
}

string Haina::getNume() {
    return nume;
}

int Haina::getGreutate() {
    return greutate;
}

int Haina::getTemp() {
    return temp;
}

char Haina::getCuloare() {
    return culoare;
}

void Haina::setNume(string s) {
    nume = s;
}

void Haina::setGreutate(int x) {
    greutate = x;
}

void Haina::setTemp(int x) {
    temp = x;
}

void Haina::setCuloare(char x) {
    culoare = x;
}

string Haina::getIstoric() {
    return istoric;
}

void Haina::addIstoric(const string& s) {
    istoric += s;
}

void Haina::setIstoric(const string& s) {
    istoric = s;
}

double Haina::getTimp() {
    return timp;
}

void Haina::setTimp(double x) {
    timp = x;
}

void Haina::setPoz(int x) {
    poz = x;
}

int Haina::getPoz() {
    return poz;
}

int Haina::id = 0;
