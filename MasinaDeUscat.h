#ifndef MASINADEUSCAT_H_INCLUDED
#define MASINADEUSCAT_H_INCLUDED
#include<iostream>
#include<vector>
#include"MasinaDeStors.h"
#include"Client.h"

class masinaDeUscat : public masina {
private:
    int nrArticole; // capacitatea unei masini de stors este data de nr. de articole
public:
    masinaDeUscat(int d = masina::getDurataUscat(), int sp = 0, int cp = masina::getCapacitateUscat());
    int getNrArticole();
    void setNrArticole(int x);
    static void uscareHaine(vector<masinaDeStors>& v, vector<Client>&);
    int getDurata();
    void setDurata(int x);
};

#endif // MASINADEUSCAT_H_INCLUDED
