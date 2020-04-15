#include"MasinaDeCalcat.h"

masinaDeCalcat::masinaDeCalcat(int d, int sp, int cp, char const* p): masina(d, sp) {
    cmax = cp;
    lg = strlen(p);
    nume = new char[lg + 1];
    strcpy(nume, p);
}

masinaDeCalcat::~masinaDeCalcat() {
    delete[] nume;
}

masinaDeCalcat::masinaDeCalcat(const masinaDeCalcat& a): masina(a) {
    this->cmax = a.cmax;
    this->lg = a.lg;
    this->nume = new char[lg + 1];
    strcpy(nume, a.nume);
}

masinaDeCalcat::masinaDeCalcat(masinaDeCalcat&& a) {
    cmax = a.cmax;
    lg = a.lg;
    nume = a.nume;
    a.lg = 0;
    a.nume = nullptr;
}

masinaDeCalcat& masinaDeCalcat::operator=(masinaDeCalcat& other) {
    if(this == &other)
        return *this;
    delete[] nume;
    cmax = other.cmax;
    lg = other.lg;
    nume = new char[lg + 1];
    strcpy(nume, other.nume);
    return *this;
}

int masinaDeCalcat::getDurata() {
    return durata;
}

int masinaDeCalcat::getCapacitate() {
    return cmax;
}

void masinaDeCalcat::setDurata(int x) {
    durata = x;
}

void masinaDeCalcat::setCapacitate(int x) {
    cmax = x;
}


void masinaDeCalcat::calcareHaine(vector<masinaDeUscat>& v, vector<Client>& client) {
    /*masinaDeCalcat a(0, 0, 1, "Philips");
    masinaDeCalcat b(move(a));
    strcpy(b.nume,"Samsung");
    cout << b.nume << "\n";
    masinaDeCalcat c(0, 0, 1, "Philips");
    masinaDeCalcat d(0, 0, 1, "Samsung");
    c = d;
    cout << c.nume << "\n";*/
    vector<masinaDeCalcat> M;
    string tipHaina;
    int cnt = 0;
    double t, maxim;
    for(unsigned i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].getSize(); ++j) {
            tipHaina = v[i][j].getNume();
            if(tipHaina != "palton" && tipHaina != "geaca") {
                masinaDeCalcat x(0, 0, 1, "Philips");
                x.setSpatiu(1); // masina este ocupata in intregime de haina curenta
                if(tipHaina == "camasa")
                    x.setDurata(masina::getDurataCamasa());
                else if(tipHaina == "rochie")
                    x.setDurata(masina::getDurataRochie());
                else if(tipHaina == "pantaloni")
                    x.setDurata(masina::getDurataPantaloni());
                else x.setDurata(masina::getDurataCostum());
                t = double(x.getDurata()) * (double(v[i][j].getGreutate()) / 1000.0);
                v[i][j].setTimp(v[i][j].getTimp() + t);
                v[i][j].addIstoric("Am fost adaugata in masina de calcat nr. ");
                v[i][j].addIstoric(to_string(cnt + 1));
                v[i][j].addIstoric("\n");
                ++cnt;
                x.addHaina(v[i][j]);
                M.push_back(x);
            } else v[i][j].addIstoric("Fara calcare\n");
            client[v[i][j].getIdHaina()][v[i][j].getPoz()].setIstoric(v[i][j].getIstoric());
            client[v[i][j].getIdHaina()][v[i][j].getPoz()].setTimp(v[i][j].getTimp());
        }
    }
    for(unsigned i = 0; i < client.size(); ++i) {
        cout << client[i];
        cout << "Cantitatea de detergent folosita este " << client[i].getDet() << "g\n";
        maxim = client[i][0].getTimp();
        for(int j = 1; j < client[i].getHsize(); ++j) {
            if(client[i][j].getTimp() > maxim)
                maxim = client[i][j].getTimp();
        }
        cout << "Timpul total petrecut in masini este " << maxim << "s\n";
    }
}
