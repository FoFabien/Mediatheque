#ifndef DISQUE_H_INCLUDED
#define DISQUE_H_INCLUDED

#include "VHS.h"

class Disque : public VHS
{
    public:
        virtual ~Disque();
        virtual void input(void);
        virtual void show();
        virtual bool search(string chaine);
        virtual void write(ofstream *fichier);
        virtual void read(ifstream *fichier);

    protected:
        Disque();
        string Nb_pistes;
};


#endif // DISQUE_H_INCLUDED
