#ifndef HAINA_H_INCLUDED
#define HAINA_H_INCLUDED
#include<iostream>
using namespace std;

class Haina {
private:
    static int id;
    string nume;
    string istoric;
    int idHaina;
    int greutate;
    int temp;
    int poz;
    char culoare;
    double timp;
public:
    Haina(string s = "", int g = 0, int t = 0, char c = 'D');
    static int getId();
    static void nextId();
    int getIdHaina();
    void setIdHaina(int x);
    string getNume();
    int getGreutate();
    int getTemp();
    int getPoz();
    char getCuloare();
    double getTimp();
    void setNume(string s);
    void setGreutate(int x);
    void setTemp(int x);
    void setCuloare(char x);
    string getIstoric();
    void addIstoric(const string& s);
    void setIstoric(const string& s);
    void setTimp(double x);
    void setPoz(int x);
};

#endif // HAINA_H_INCLUDED
