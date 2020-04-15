#include<iostream>
#include"MasinaDeUscat.h"
#include"Client.h"

masinaDeStors::masinaDeStors(int d, int sp, int cp): masina(d, sp) {
    cmax = cp;
}

int masinaDeStors::getCapacitate() {
    return cmax;
}

void masinaDeStors::setCapacitate(int x) {
    cmax = x;
}

int masinaDeStors::getDurata() {
    return durata;
}

void masinaDeStors::setDurata(int x) {
    durata = x;
}

void masinaDeStors::stoarcereHaine(vector<masinaDeSpalat>& v, vector<Client>& client) {
    vector<masinaDeStors> M;
    masinaDeStors x;
    masinaDeStors fictiv;
    string tipHaina;
    bool gasit;
    M.push_back(x);
    for(unsigned i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].getSize(); ++j) {
            tipHaina = v[i][j].getNume();
            // asezam haina curenta intr-o masina de stors
            gasit = false;
            for(unsigned k = 0; k < M.size() && !gasit; ++k) {
                if(tipHaina != "palton" && tipHaina != "geaca") {
                    if(v[i][j].getGreutate() + M[k].getSpatiu() <= M[k].getCapacitate()) {
                        M[k].setSpatiu(v[i][j].getGreutate());
                        v[i][j].addIstoric("Am fost adaugata in masina de stors nr. ");
                        v[i][j].addIstoric(to_string(k + 1));
                        v[i][j].addIstoric("\n");
                        v[i][j].setTimp(v[i][j].getTimp() + masina::getDurataStors());
                        M[k].addHaina(v[i][j]);
                        //cout << v[i][j].getIstoric() << "\n";
                        gasit = true;
                    }
                } else {
                    v[i][j].addIstoric("Fara stoarcere\n");
                    fictiv.addHaina(v[i][j]);
                    gasit = true;
                }
            }
            if(!gasit) {
                // presupunem ca greutatea hainei este <= decat cea a masinii de stors
                masinaDeStors y;
                y.setSpatiu(v[i][j].getGreutate());
                v[i][j].addIstoric("Am fost adaugata in masina de stors nr. ");
                v[i][j].addIstoric(to_string(M.size() + 1));
                v[i][j].addIstoric("\n");
                v[i][j].setTimp(v[i][j].getTimp() + masina::getDurataStors());
                y.addHaina(v[i][j]);
                M.push_back(y);
                //cout << v[i][j].getIstoric() << "\n";
            }
        }
    }
    // acum adaug masina de stors ~fictiva~ la vectorul M
    M.push_back(fictiv);
    masinaDeUscat::uscareHaine(M, client);
}
