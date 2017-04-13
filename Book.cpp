#include "Book.h"

Book::Book()
{
    type = "BOOK";
}

Book::~Book()
{

}

void Book::input(void)
{
    Media::input();
    cout << "Entrez le nombre de pages : " ;
    cin >> page;
    cout << "Entrez la collection : " ;
    cin >> collection;
    cout << "Resume : " ;
    cin >> resume;
}

void Book::show()
{
    Media::show();
    cout << "nombre de pages : " << page << endl;
    cout << "de la collection : " << collection << endl;
    cout << "resume" << resume << endl;
}

bool Book::search(string chaine)
{
    if((page.find(chaine) != string::npos) || (collection.find(chaine) != string::npos) || (resume.find(chaine) != string::npos) || Media::search(chaine))
        return true;
    return false;
}

void Book::write(ofstream *fichier)
{
    Media::write(fichier);
    (*fichier) << page << "\n" << collection << "\n" << resume;
}

void Book::read(ifstream *fichier)
{
    Media::read(fichier);
    getline(*fichier, page);
    getline(*fichier, collection);
    getline(*fichier, resume);
}
