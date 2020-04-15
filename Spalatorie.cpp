#include<iostream>
#include<vector>
#include"Client.h"
#include"MasinaDeSpalat.h"
using namespace std;

int main() {
    vector<Client> v;
    Client::citireNobiecte(v);
    Client::distribuieHaine(v);
    /*masinaDeSpalat x;
    masina* p = &x;
    p->afisInfo();*/
    return 0;
}
