#ifndef MASINADESPALAT_H_INCLUDED
#define MASINADESPALAT_H_INCLUDED
#include<iostream>
#include"Masina.h"

class masinaDeSpalat : public masina {
private:
    int cmax;
    int tempSp;
    bool inchise;
    bool deschise;
    bool usoare;
    bool grele;
public:
    masinaDeSpalat(int d = masina::getDurataSpalat(), int sp = 0, int cp = masina::getCapacitateSpalat(), int t = masina::getTempSpalat(), bool i = false, bool D = false, bool u = false, bool g = false);
    int getCapacitate();
    void setCapacitate(int x);
    int getTempSp();
    void setTempSp(int x);
    bool getInchise();
    bool getDeschise();
    bool getUsoare();
    bool getGrele();
    void setInchise(bool x);
    void setDeschise(bool x);
    void setUsoare(bool x);
    void setGrele(bool x);
    int getDurata();
    void setDurata(int x);
    void afisInfo();
};

#endif // MASINADESPALAT_H_INCLUDED
