#ifndef INSTRUCTIONS_H_INCLUDED
#define INSTRUCTIONS_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Media;

class Instructions{

    public:
        Instructions();
        ~Instructions();
        void BYE();
        void ADD(string type);
        void LOAD(string type);
        void SAVE(string type);
        void SEARCH(string type);
        void CLEAR();
        void LIST();
        void DELETE(string id);
        void RESET();
        void START();
        void SHOW(string type);
        void RELOAD();
        void USER();
        void EMPRUNTER(string id);
        void RENDRE(string id);

    private:
        vector<Media*> tab;
        vector<Media*> tSearch;
        bool firstSearch;
        bool boucle;
        bool admin;
        string currentFile;
        time_t temps;
};

#endif // INSTRUCTIONS_H_INCLUDED
