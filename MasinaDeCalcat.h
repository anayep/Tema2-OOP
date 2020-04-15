#ifndef MASINADECALCAT_H_INCLUDED
#define MASINADECALCAT_H_INCLUDED
#include<iostream>
#include<cstring>
#include"MasinaDeUscat.h"

class masinaDeCalcat: public masina {
private:
    int cmax;
    int lg;
    char* nume;
public:
    masinaDeCalcat(int d = 0, int sp = 0, int cp = 1, char const* p = "");
    ~masinaDeCalcat();
    masinaDeCalcat(const masinaDeCalcat&);
    masinaDeCalcat(masinaDeCalcat&&);
    masinaDeCalcat& operator=(masinaDeCalcat&);
    int getDurata();
    int getCapacitate();
    void setDurata(int x);
    void setCapacitate(int x);
    static void calcareHaine(vector<masinaDeUscat>& v, vector<Client>&);
};

#endif // MASINADECALCAT_H_INCLUDED
