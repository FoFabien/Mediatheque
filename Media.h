#ifndef Media_H
#define Media_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Media
{
    public:
        virtual void input(void);
        virtual void show();
        virtual ~Media();
        virtual bool search(string chaine);
        int getId(void);
        void list(void);
        virtual void write(ofstream *fichier);
        virtual void read(ifstream *fichier);
        void setEmprunt(bool booleen);
        bool estEmprunter(void);

    protected:
         Media();
         string name;
         string auteur;
         string date;
         int id;
         string type;
         bool emprunt;
};

#endif //  Media_H
