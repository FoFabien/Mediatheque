#ifndef VHS_H
#define VHS_H

#include "Media.h"


class VHS : public Media
{
    public:
        VHS();
        virtual ~VHS();
        virtual void input(void);
        virtual void show();
        virtual bool search(string chaine);
        virtual void write(ofstream *fichier);
        virtual void read(ifstream *fichier);

    protected:
        string duree;
        string Maison_de_production;
};

   #endif // VHS_H
