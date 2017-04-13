#include "Media.h"
#include "main.h"

int count = 0;

Media::Media()
{
    id = count;
    count++;
    emprunt = false;
}

Media::~Media()
{

}

void Media::input(void)
{
    cout << "Entrez le nom : ";
    cin >> name;
    cout << "Entrez l'auteur : ";
    cin >> auteur;
    cout << "Entrez l'annee : ";
    cin >> date;
}

void Media::show()
{
    cout << type;
    if(emprunt) cout << " [EMPRUNTE]";
    cout << endl;
    cout << "nom : " << name << endl;
    cout << "auteur : " << auteur << endl;
    cout << "date : " << date << endl;
}

int Media::getId(void)
{
    return id;
}

void Media::list(void)
{
    cout << "#" << id << " " << type << " " << name << " " << auteur << " ";
    if(emprunt) cout << "[EMPRUNTE]";
    cout << endl;
}


bool Media::search(string chaine)
{
    if((name.find(chaine) != string::npos) || (auteur.find(chaine) != string::npos) || (date.find(chaine) != string::npos))
        return true;
    return false;
}

void Media::write(ofstream *fichier)
{
    (*fichier) << type << "\n" << emprunt << "\n" << name << "\n" << auteur << "\n" << date << endl;
}

void Media::read(ifstream *fichier)
{
    string tmp;
    getline(*fichier, tmp);
    if(conv_char_int((char*)tmp.data()) == 1) emprunt = true;
    else emprunt = false;

    getline(*fichier, name);
    getline(*fichier, auteur);
    getline(*fichier, date);
}

void Media::setEmprunt(bool booleen)
{
    emprunt = booleen;
}

bool Media::estEmprunter(void)
{
    return emprunt;
}
