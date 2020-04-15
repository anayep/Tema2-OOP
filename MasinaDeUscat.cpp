#include<iostream>
#include<vector>
#include"MasinaDeCalcat.h"
#include"Client.h"

masinaDeUscat::masinaDeUscat(int d, int sp, int cp): masina(d, sp) {
    nrArticole = cp;
}

int masinaDeUscat::getNrArticole() {
    return nrArticole;
}

void masinaDeUscat::setNrArticole(int x) {
    nrArticole += x;
}

int masinaDeUscat::getDurata() {
    return durata;
}

void masinaDeUscat::setDurata(int x) {
    durata = x;
}

void masinaDeUscat::uscareHaine(vector<masinaDeStors>& v, vector<Client>& client) {
    vector<masinaDeUscat> M;
    masinaDeUscat x;
    M.push_back(x);
    bool gasit;
    for(unsigned i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].getSize(); ++j) {
            gasit = false;
            for(unsigned k = 0; k < M.size() && !gasit; ++k) {
                // verificam daca exista spatiu suficient in masina de uscat cu numarul k
                if(M[k].getSpatiu() < M[k].getNrArticole()) {
                    M[k].setSpatiu(1);
                    v[i][j].addIstoric("Am fost adaugata in masina de uscat nr. ");
                    v[i][j].addIstoric(to_string(k + 1));
                    v[i][j].addIstoric("\n");
                    v[i][j].setTimp(v[i][j].getTimp() + masina::getDurataUscat());
                    M[k].addHaina(v[i][j]);
                    gasit = true;
                }
            }
            if(!gasit) {
                masinaDeUscat y;
                y.setSpatiu(1);
                v[i][j].addIstoric("Am fost adaugata in masina de uscat nr. ");
                v[i][j].addIstoric(to_string(M.size() + 1));
                v[i][j].addIstoric("\n");
                v[i][j].setTimp(v[i][j].getTimp() + masina::getDurataUscat());
                y.addHaina(v[i][j]);
                M.push_back(y);
            }
        }
    }
    masinaDeCalcat::calcareHaine(M, client);
}
