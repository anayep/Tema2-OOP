#ifndef MASINADESTORS_H_INCLUDED
#define MASINADESTORS_H_INCLUDED
#include<iostream>
#include<vector>
#include"MasinaDeSpalat.h"
#include"Client.h"
using namespace std;

class masinaDeStors : public masina {
private:
    int cmax;
public:
    masinaDeStors(int d = masina::getDurataStors(), int sp = 0, int cp = masina::getCapacitateStors());
    int getCapacitate();
    void setCapacitate(int x);
    static void stoarcereHaine(vector<masinaDeSpalat>& v, vector<Client>&);
    int getDurata();
    void setDurata(int x);
};

#endif // MASINADESTORS_H_INCLUDED
