#ifndef REVUE_H_INCLUDED
#define REVUE_H_INCLUDED

#include "Book.h"
#include <vector>

class Revue : public Book
{
 public:
        Revue();
        ~Revue();
        void input(void);
        void show();
        bool search(string chaine);
        void write(ofstream *fichier);
        void read(ifstream *fichier);

 protected:
        string editeur;
        unsigned int Nb_articles;
        string n;
        vector<string> article;
};
#endif // REVUE_H_INCLUDED



