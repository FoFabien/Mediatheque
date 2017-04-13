#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "Media.h"


class Book : public Media
{
    public:
        Book();
        virtual ~Book();
        virtual void input(void);
        virtual void show();
        bool search(string chaine);
        void write(ofstream *fichier);
        void read(ifstream *fichier);

    protected:
        string page;
        string collection;
        string resume;
};
#endif // BOOK_H_INCLUDED
