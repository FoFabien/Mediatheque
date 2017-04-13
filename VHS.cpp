#include "VHS.h"

VHS::VHS()
{
    type = "VHS";
}


VHS::~VHS()
{

}

void VHS::input(void)
{
    Media::input();
    cout << "Entrez la duree : ";
    cin >> duree;
    cout << "Entrez le nom de la maison de production : ";
    cin >> Maison_de_production;

}
void VHS::show()
{
    Media::show();
    cout << "duree : " << duree << endl;
    cout << "maison de production : " << Maison_de_production << endl;
}

bool VHS::search(string chaine)
{
    if((duree.find(chaine) != string::npos) || (Maison_de_production.find(chaine) != string::npos) || Media::search(chaine))
        return true;
    return false;
}

void VHS::write(ofstream *fichier)
{
    Media::write(fichier);
    (*fichier) << duree << "\n" << Maison_de_production;
}

void VHS::read(ifstream *fichier)
{
    Media::read(fichier);
    getline(*fichier, duree);
    getline(*fichier, Maison_de_production);
}
