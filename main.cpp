#include "Instructions.h"


using namespace std;

int main()
{

    Instructions *Mediatheque = new Instructions();
    Mediatheque->START();

    delete Mediatheque;

    return 0;
}

int conv_char_int(char* s)
{
    int num = 0;
    bool booleen = true;

    while(booleen)
    {
        if(*s <'0' || *s > '9')
            booleen = false;
        else
            num = num * 10 + *s++ - '0';
    }
    return num;
}

int conv_char_int_exc(char* s)
{
    int num = 0;
    bool booleen = true;

    while(booleen)
    {
        if((*s <'0' || *s > '9') && *s!=0)
            {
                throw string("Erreur - Entrez un nombre");
            }
        else
            if (*s == 0) booleen = false;
            else num = num * 10 + *s++ - '0';
    }
    return num;
}
