#include "Revue.h"
#include "main.h"

 Revue::Revue()
 {
     type = "REVUE";
 }


 Revue::~Revue()
{

}

void Revue::input(void)
{
    string tmp;
    bool numero = false;

    Book::input();
    cout << "Entrez le nom de l'editeur : ";
    cin >> editeur;

    while(!numero)
    {
        try
        {
            cout << "Entrez le nombre d'article : ";
            cin >> n;
            Nb_articles = conv_char_int_exc((char*)n.data());
            numero=true;
        }
        catch(const string& chaine)
        {
            cerr << chaine << endl;
        }
    }

    for(unsigned int i = 0;i < Nb_articles; i++)
    {
        cout << "Nom de l'article #" << (i+1) << " : ";
        cin >> tmp;
        article.push_back(tmp);
    }
}

void Revue::show()
{
    Book::show();
    cout << "editeur : " << editeur << endl;
    cout << "nombre d'articles : " << Nb_articles << endl;
    for(unsigned int i = 0;i < Nb_articles; i++)
        cout << "Nom de l'article #" << (i+1) << " : " << article[i] << endl;
}

bool Revue::search(string chaine)
{
    if((editeur.find(chaine) != string::npos) || (n.find(chaine) != string::npos) || Book::search(chaine))
        return true;

    for(unsigned int i = 0;i < Nb_articles; i++)
    {
        if(article[i].find(chaine) != string::npos) return true;
    }

    return false;
}

void Revue::write(ofstream *fichier)
{
    Book::write(fichier);
    (*fichier) << "\n" << editeur << "\n" << n;

    for(unsigned int i = 0;i < Nb_articles; i++)
        (*fichier) << "\n" << article[i];
}

void Revue::read(ifstream *fichier)
{
    string tmp;
    Book::read(fichier);
    getline(*fichier, editeur);
    getline(*fichier, n);

    try
    {
        Nb_articles = conv_char_int_exc((char*)n.data());
    }
    catch(const string& chaine)
    {
        Nb_articles = 0;
    }

    for(unsigned int i = 0;i < Nb_articles; i++)
    {
        getline(*fichier, tmp);
        article.push_back(tmp);
    }
}
