#include<iostream>
#include<vector>
#include<set>
#include<exception>
#include<stdexcept>
#include<cctype>
#include<cstdlib>
#include"MasinaDeStors.h"
#include"ExceptiaMea.h"
using namespace std;

Client::Client(string s1, string s2) {
    det = 0;
    nume = s1;
    prenume = s2;
}

Client::~Client() {
    h.clear();
    h.shrink_to_fit();
}

double Client::getDet() {
    return det;
}

void Client::setDet(double x) {
    det += x;
}

string Client::getNume() {
    return nume;
}

string Client::getPrenume() {
    return prenume;
}

Haina& Client::operator[](const int poz) {
    return h[poz];
}

int Client::getHsize() {
    return h.size();
}

istream& operator>>(istream& in, Client& cl) {
    char c;
    int cnt, g, t;
    string s;
    try {
        cin >> cl.nume;
        if(cl.nume.size() < 3) {
            throw logic_error("Numele persoanei trebuie sa aiba cel putin 3 litere!");
        }
        for(unsigned i = 0; i < cl.nume.size(); ++i)
            if(!isalpha(cl.nume[i]))
                throw logic_error("Numele persoanei trebuie sa contina doar litere!");
        cin >> cl.prenume;
        if(cl.prenume.size() < 3)
            throw logic_error("Prenumele persoanei trebuie sa aiba cel putin 3 litere!");
        for(unsigned i = 0; i < cl.prenume.size(); ++i)
            if(!isalpha(cl.prenume[i]))
                throw logic_error("Prenumele persoanei trebuie sa contina doar litere!");
        cin >> cnt;
        if(cnt <= 0)
            throw logic_error("Persoana trebuie sa aiba cel putin o haina!");
    }
    catch(logic_error &error) {
        cout << "A aparut o eroare la citire!\n";
        cout << error.what() << "\n";
        exit(1);
    }

    cout << "Introduceti datele despre cele " << cnt << " haine! ";
    for(int i = 0; i < cnt; ++i) {
        Haina x;
        try {
            cin >> s >> c >> g >> t;
            if(s != "pantaloni" && s != "rochie" && s != "camasa" &&
               s != "geaca" && s != "palton" && s != "costum")
                throw("Haina introdusa nu respecta restrictiile problemei!\n");
            if((c != 'I') && (c != 'D'))
                throw("Hainele trebuie sa fie inchise sau deschise!\n");
            if(g <= 0)
                throw("Greutatea hainei trebuie sa fie strict pozitiva!\n");
            if(g > 1500)
                throw("Greutatea hainei trebuie sa fie mai mica de 1500g!\n");
            if(t <= 0)
                throw("Temperatura de spalare trebuie sa fie strict pozitiva!\n");
            if(t > 70)
                throw("Temperatura de spalare trebuie sa fie sub 70*C");
        } catch(const char* error) {
            cout << "A aparut o eroare la citire!\n";
            cout << error;
            exit(1);
        }
        x.setIdHaina(Haina::getId());
        x.setPoz(i);
        x.setNume(s);
        x.setCuloare(c);
        x.setGreutate(g);
        x.setTemp(t);
        cl.h.push_back(x);
    }
    return in;
}

    ostream& operator<< (ostream& out, Client& cl) {
    cout << cl.nume << " " << cl.prenume << "\n";
    for(unsigned i = 0; i < cl.h.size(); ++i) {
        cout << cl.h[i].getNume() << " " << cl.h[i].getCuloare() << " "
             << cl.h[i].getGreutate() << "g " << cl.h[i].getTemp() << "C\n"
             << cl.h[i].getIstoric() << "\n";
    }
    return out;
}

    void Client::citireNobiecte(vector<Client>& v) {
    int cnt;
    cout << "Introduceti numarul de persoane : ";
    try {
        cin >> cnt;
        if(cnt <= 0)
            throw myException("Numarul de persoane trebuie sa fie strict pozitiv!");
    }
    catch(myException& e) {
        cout << "A aparut o eroare la citire!\n";
        cout << e.what() << "\n";
        exit(1);
    }
    for(int i = 0; i < cnt; ++i) {
        Client c;
        cout << "Introduceti numele, prenumele si numarul de haine pentru persoana " << i + 1 << " :\n";
        cin >> c;
        v.push_back(c);
        Haina::nextId();
    }

    for(unsigned i = 0; i < v.size(); ++i) {
        cout << "Clientul " << i + 1 << "\n";
        cout << v[i];
    }
}

    void Client::distribuieHaine(vector<Client>& client) {
    vector<masinaDeSpalat> M;
    masinaDeSpalat x;
    M.push_back(x);
    string tipHaina;
    string str;
    set<string> usoare, grele;
    usoare.insert("pantaloni");
    usoare.insert("rochie");
    usoare.insert("camasa");
    grele.insert("geaca");
    grele.insert("palton");
    bool gasit;
    double cant;
    char c;
    for(unsigned i = 0; i < client.size(); ++i) {
        for(unsigned j = 0; j < client[i].h.size(); ++j) {
            tipHaina = client[i].h[j].getNume();
            c = client[i].h[j].getCuloare();
            gasit = false;
            for(unsigned k = 0; k < M.size() && !gasit; ++k) {
                if((M[k].getSpatiu() + client[i].h[j].getGreutate() <= M[k].getCapacitate()) &&
                   M[k].getTempSp() >= client[i].h[j].getTemp()) {
                    // haina incape in masina cu indicele k
                    if(usoare.find(tipHaina) != usoare.end()) {
                        // haina curenta este usoara
                        if(M[k].getGrele()) // masina contine haine grele
                            continue;
                        if(c == 'D') { // haina este deschisa si verificam daca masina contine haine inchise
                            if(M[k].getInchise())
                                continue;
                        } else if(M[k].getDeschise()) // daca haina e inchisa, verificam daca sunt haine deschise in masina
                            continue;
                        // daca am ajuns aici inseamna ca pot adauga haina in masina
                        gasit = true;
                        M[k].setSpatiu(client[i].h[j].getGreutate());
                        client[i].h[j].addIstoric("Am fost adaugata in masina de spalat cu nr. ");
                        client[i].h[j].addIstoric(to_string(k + 1));
                        client[i].h[j].addIstoric("\n");
                        client[i].h[j].setTimp(client[i].h[j].getTimp() + masina::getDurataSpalat());
                        M[k].addHaina(client[i].h[j]);
                        cant = double(client[i].h[j].getGreutate()) / 1000.0;
                        if(client[i].h[j].getNume() == "pantaloni") {
                            if(c == 'D')
                                client[i].setDet(cant * masina::getCantDetUsoare());
                            else client[i].setDet(2.0 * cant * masina::getCantDetUsoare());
                        } else client[i].setDet(cant * masina::getCantDetUsoare());
                        M[k].setUsoare(true);
                        if(c == 'D')
                            M[k].setDeschise(true);
                        else M[k].setInchise(true);
                    } else if(grele.find(tipHaina) != grele.end() || tipHaina == "costum") {
                        if(M[k].getUsoare())
                            continue;
                        if(c == 'D') {
                            if(M[k].getInchise())
                                continue;
                        } else if(M[k].getDeschise())
                            continue;
                        // daca am ajuns pana aici, adaug haina in masina
                        gasit = true;
                        M[k].setSpatiu(client[i].h[j].getGreutate());
                        client[i].h[j].addIstoric("Am fost adaugata in masina de spalat cu nr. ");
                        client[i].h[j].addIstoric(to_string(k + 1));
                        client[i].h[j].addIstoric("\n");
                        client[i].h[j].setTimp(client[i].h[j].getTimp() + masina::getDurataSpalat());
                        M[k].addHaina(client[i].h[j]);
                        cant = double(client[i].h[j].getGreutate()) / 1000.0;
                        cant *= masina::getCantDetGrele();
                        client[i].setDet(cant);
                        M[k].setGrele(true);
                        if(c == 'D')
                            M[k].setDeschise(true);
                        else M[k].setInchise(true);
                    }
                }
            }
            // verificam daca nu am putut adauga haina in nicio masina
            if(!gasit) {
                masinaDeSpalat y;
                // presupunem ca haina incape in masina
                if(client[i].h[j].getGreutate() <= y.getCapacitate()) {
                    y.setSpatiu(client[i].h[j].getGreutate());
                    y.setTempSp(client[i].h[j].getTemp());
                    client[i].h[j].addIstoric("Am fost adaugata in masina de spalat cu nr. ");
                    client[i].h[j].addIstoric(to_string(M.size() + 1));
                    client[i].h[j].addIstoric("\n");
                    client[i].h[j].setTimp(client[i].h[j].getTimp() + masina::getDurataSpalat());
                    y.addHaina(client[i].h[j]);
                    cant = double(client[i].h[j].getGreutate()) / 1000.0;
                    if(usoare.find(tipHaina) != usoare.end()) {
                        y.setUsoare(true);
                        if(tipHaina == "pantaloni") {
                            if(c == 'D')
                                client[i].setDet(cant * masina::getCantDetUsoare());
                            else client[i].setDet(2.0 * cant * masina::getCantDetUsoare());
                        } else client[i].setDet(cant * masina::getCantDetUsoare());
                    } else { // altfel e haina grea sau costum
                        y.setGrele(true);
                        client[i].setDet(cant * masina::getCantDetGrele());
                    }
                    if(c == 'D')
                        y.setDeschise(true);
                    else y.setInchise(true);
                    M.push_back(y); // adaug o noua masina de spalat in vector
                }
            }
        }
    }
    masinaDeStors::stoarcereHaine(M, client);
}
