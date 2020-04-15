#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include<iostream>
#include<vector>
#include"Haina.h"

class Client {
private:
    double det; // cantitatea de detergent folosita
    string nume;
    string prenume;
    vector<Haina> h; // fiecare client poate avea mai multe haine
public:
    Client(string s1 = "", string s2 = "");
    string getNume();
    string getPrenume();
    ~Client();
    int getTimp();
    int getHsize();
    void setTimp(int x);
    double getDet();
    void setDet(double x);
    Haina& operator[](const int poz);
    friend istream& operator>>(istream& in, Client& cl);
    friend ostream& operator<< (ostream& out, Client& cl);
    static void citireNobiecte(vector<Client>& v);
    static void distribuieHaine(vector<Client>& client);
};

#endif // CLIENT_H_INCLUDED
