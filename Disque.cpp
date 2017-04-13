#include "Disque.h"

Disque::Disque()
{

}

Disque::~Disque()
{

}

void Disque::input(void)
{
    VHS::input();
    cout << "Entrez le nombre de pistes : ";
    cin >> Nb_pistes;
}

void Disque::show()
{
    VHS::show();
    cout << "nombre de pistes : " << Nb_pistes << endl;

}

bool Disque::search(string chaine)
{
    if((Nb_pistes.find(chaine) != string::npos) || VHS::search(chaine))
        return true;
    return false;
}

void Disque::write(ofstream *fichier)
{
    VHS::write(fichier);
    (*fichier) << "\n" << Nb_pistes;
}

void Disque::read(ifstream *fichier)
{
    VHS::read(fichier);
    getline(*fichier, Nb_pistes);

}

