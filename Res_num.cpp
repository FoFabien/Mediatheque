#include "Res_num.h"

 Res_num::Res_num()
 {
    type = "FICHIER";
 }


 Res_num::~Res_num()
{

}

void Res_num::input(void)
{
    Media::input();
    cout << "Entrez le type : ";
    cin >> extension;
    cout << "Entrez la taille : ";
    cin >> taille;
    cout << "Entrez l'URL : ";
    cin >> url;
}

void Res_num::show()
{
    Media::show();
    cout << "type de fichier : " << extension << endl;
    cout << "taille du fichier : " << taille << endl;
    cout << "emplacement du fichier : " << url << endl;
}

bool Res_num::search(string chaine)
{
    if((extension.find(chaine) != string::npos) || (taille.find(chaine) != string::npos) || (url.find(chaine) != string::npos) || Media::search(chaine))
        return true;
    return false;
}

void Res_num::write(ofstream *fichier)
{
    Media::write(fichier);
    (*fichier) << extension << "\n" << taille << "\n" << url;
}

void Res_num::read(ifstream *fichier)
{
    Media::read(fichier);
    getline(*fichier, extension);
    getline(*fichier, taille);
    getline(*fichier, url);
}
