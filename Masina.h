#ifndef MASINA_H_INCLUDED
#define MASINA_H_INCLUDED
#include<iostream>
#include<vector>
#include"Haina.h"

class masina {
private:
    static const int TEMP_SPALAT;
    static const int DURATA_SPALAT;
    static const int DURATA_STORS;
    static const int DURATA_USCAT;
    static const int DURATA_CAMASA;
    static const int DURATA_ROCHIE;
    static const int DURATA_PANTALONI;
    static const int DURATA_COSTUM;
    static const int CAPACITATE_SPALAT;
    static const int CAPACITATE_STORS;
    static const int CAPACITATE_USCAT;
    static const int CANT_DET_USOARE;
    static const int CANT_DET_GRELE;
protected:
    int durata;
    int spatiu;
    vector<Haina> m;
public:
    masina(int d = masina::getDurataSpalat(), int sp = 0);
    ~masina();
    Haina& operator[](const int poz);
    int getSize();
    void addHaina(Haina& x);
    int getSpatiu();
    void setSpatiu(int x);
    static const int getTempSpalat();
    static const int getDurataSpalat();
    static const int getDurataStors();
    static const int getDurataUscat();
    static const int getDurataCamasa();
    static const int getDurataRochie();
    static const int getDurataPantaloni();
    static const int getDurataCostum();
    static const int getCapacitateSpalat();
    static const int getCapacitateStors();
    static const int getCapacitateUscat();
    static const int getCantDetUsoare();
    static const int getCantDetGrele();
    virtual void afisInfo(); // functie virtuala
    virtual int getDurata() = 0; // functie virtuala pura
    virtual void setDurata(int x) = 0; // functie virtuala pura
};

#endif // MASINA_H_INCLUDED
