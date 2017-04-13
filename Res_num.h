#ifndef RES_NUM_H_INCLUDED
#define RES_NUM_H_INCLUDED

#include "Media.h"


class Res_num : public Media
{
 public:
        Res_num();
        virtual ~Res_num();
        virtual void input(void);
        virtual void show();
        virtual bool search(string chaine);
        virtual void write(ofstream *fichier);
        virtual void read(ifstream *fichier);

 protected:
        string extension;
        string taille;
        string url;

};





#endif // RES_NUM_H_INCLUDED
