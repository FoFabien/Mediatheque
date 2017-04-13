#include "Instructions.h"
#include "Res_num.h"
#include "CD.h"
#include "DVD.h"
#include "Revue.h"
#include "main.h"

#include <fstream>

extern int count;

Instructions::Instructions()
{
    currentFile = " ";
    boucle = true;
    firstSearch = true;
    admin = false;
}

Instructions::~Instructions()
{

}


void Instructions::START()
{
    string commande, type;

    cout << "\t### Mediatheque ###" << endl;
    cout << "Bienvenue" << endl;
    USER();
    cout << "Entrez une commande" << endl;


    while(boucle)
    {
        cin >> commande;
        RELOAD();

        if (commande.find("ADD")== 0)
        {
            cin >> type;
            if(admin) ADD(type);
            else cout << "Droit insuffisant" << endl;
        }
        else if (commande.find("BYE")==0)
            BYE();
        else if (commande.find("LOAD")==0)
        {
            cin >> type;
            LOAD(type);
        }
        else if (commande.find("SAVE")==0)
        {
            cin >> type;
            if(admin) SAVE(type);
            else cout << "Droit insuffisant" << endl;
        }
        else if (commande.find("SEARCH")==0)
        {
            cin >> type;
            SEARCH(type);
        }
        else if (commande.find("CLEAR")==0)
        {
            CLEAR();
            cout << "Derniere recherche effacee" << endl;
        }
        else if (commande.find("LIST")==0)
            LIST();
        else if (commande.find("SHOW")==0)
        {
            try
            {
                cin >> type;
                SHOW(type);
            }
            catch(const string& chaine)
            {
                cerr << chaine << endl;
            }
        }
        else if (commande.find("DELETE")==0)
        {
            try
            {
                cin >> type;
                if(admin) DELETE(type);
                else cout << "Droit insuffisant" << endl;
            }
            catch(const string& chaine)
            {
                cerr << chaine << endl;
            }
        }
        else if (commande.find("RESET")==0)
        {
            if(admin) RESET();
            else cout << "Droit insuffisant" << endl;
        }
        else if (commande.find("EMPRUNTER")==0)
        {
            try
            {
                cin >> type;
                if(admin) EMPRUNTER(type);
                else cout << "Droit insuffisant" << endl;
            }
            catch(const string& chaine)
            {
                cerr << chaine << endl;
            }
        }
        else if (commande.find("RENDRE")==0)
        {
            try
            {
                cin >> type;
                if(admin) RENDRE(type);
                else cout << "Droit insuffisant" << endl;
            }
            catch(const string& chaine)
            {
                cerr << chaine << endl;
            }
        }
        else if (commande.find("HELP")==0)
        {
            cout << "\n\tHELP" << endl;
            if(admin) cout << "ADD type      - Pour ajouter un Media" << endl;
            cout << "LOAD filename - Pour charger une bibliotheque" << endl;
            if(admin) cout << "SAVE filename - Pour enregistrer une bibliotheque" << endl;
            cout << "SEARCH chaine - Pour recherche un mot" << endl;
            cout << "CLEAR         - Pour reinitialiser les recherches" << endl;
            cout << "LIST          - Pour afficher les elements" << endl;
            cout << "SHOW id       - Pour afficher un element" << endl;
            if(admin) cout << "DELETE id     - Pour effacer un element" << endl;
            if(admin) cout << "EMPRUNTER id  - Pour emprunter un element" << endl;
            if(admin) cout << "RENDRE id     - Pour rendre un element" << endl;
            cout << "BYE           - Pour quitter" << endl;
            if(admin) cout << "RESET         - Pour remettre a zero la base de donnees" << endl;
        }
        else cout << "Erreur - Tapez HELP pour la liste des commandes" << endl;
    }
    RESET();
}
void Instructions::BYE()
{
    boucle = false;
    cout << "Au revoir !" << endl;
}


void Instructions::ADD(string type)
{
    if (type.find("DVD")== 0)
        tab.push_back(new DVD()); // Rajoute une case au tableau tab
    else if (type.find("CD")==0)
        tab.push_back(new CD());
    else if (type.find("REVUE")==0)
        tab.push_back(new Revue());
    else if (type.find("BOOK")==0)
        tab.push_back(new Book());
    else if (type.find("VHS")==0)
        tab.push_back(new VHS());
    else if (type.find("FICHIER")==0)
        tab.push_back(new Res_num());
    else if (type.find("HELP")==0)
    {
        cout << "Fonction ADD - HELP" << endl;
        cout << "\tADD <type>" << endl;
        cout << "type :" << endl;
        cout << "DVD" << endl;
        cout << "CD" << endl;
        cout << "REVUE" << endl;
        cout << "BOOK" << endl;
        cout << "VHS" << endl;
        cout << "FICHIER" << endl;
        return;
    }
    else
    {
        cout << "Erreur - Type de Media inconnu" << endl;
        cout << "Tapez ADD HELP pour la liste des medias" << endl;
        return;
    }
    tab[tab.size() - 1]->input();
    cout << "Element ajoute a la mediatheque" << endl;
}


void Instructions::LOAD(string type)
{
    ifstream fichier(type.data(), ios::in);
    string ligne;
    unsigned int i = 0;

    if(fichier.fail())
    {
        cerr << "Erreur d'ouverture\nLe fichier existe-t'il ?" << endl;
        return;
    }

    RESET();
    getline(fichier, ligne); // pour sauter la ligne de la date d'enregistrement
    temps = conv_char_int((char*)ligne.data());

    while(!fichier.eof())
    {
        getline(fichier, ligne);
        if (ligne.find("DVD")==0)
            tab.push_back(new DVD());
        else if (ligne.find("CD")==0)
            tab.push_back(new CD());
        else if (ligne.find("REVUE")==0)
            tab.push_back(new Revue());
        else if (ligne.find("BOOK")==0)
            tab.push_back(new Book());
        else if (ligne.find("VHS")==0)
            tab.push_back(new VHS());
        else if (ligne.find("FICHIER")==0)
            tab.push_back(new Res_num());
        else
        {
            cerr << "Erreur : Sauvegarde corrompue" << endl;
            RESET();
            fichier.close();
            return;
        }
        tab[i]->read(&fichier);
        i++;
    }

    fichier.close();
    cout << type << " charge avec succes" << endl;
    currentFile = type;
}

void Instructions::SAVE(string type)
{
    ofstream fichier(type.data(), ios::out | ios::trunc);

    if(fichier.fail())
    {
        cerr << "Erreur d'ecriture" << endl;
        return;
    }
    temps = time (NULL);
    fichier << temps << endl;

    for(unsigned int i = 0; i < tab.size(); i++)
        {
            tab[i]->write(&fichier);
            if(i < tab.size() - 1) fichier << endl;
        }

    fichier.close();

    currentFile = type;
    cout << type << " avec succes" << endl;
}

void Instructions::SEARCH(string type)
{
    if(firstSearch)
    {
        for(unsigned int i = 0; i < tab.size(); i++)
        {
            if(tab[i]->search(type))
                tSearch.push_back(tab[i]);
        }
        firstSearch = false;
    }
    else
    {
        for(unsigned int i = 0; i < tSearch.size();)
        {
            if(tSearch[i]->search(type))
                i++;
            else tSearch.erase(tSearch.begin() + i);
        }
    }
    cout << "Recherche terminee" << endl;
}

void Instructions::CLEAR()
{
    while(tSearch.size() > 0)
    {
        tSearch.erase(tSearch.begin());
    }
    firstSearch = true;
}

void Instructions::LIST()
{
    vector<Media*> *t;
    if(firstSearch) t = &tab;
    else t = &tSearch;

    for(unsigned int i = 0; i < t->size(); i++)
        (*t)[i]->list();
    if(t->size() == 0) cout << "Aucune element trouve" << endl;
}

void Instructions::DELETE(string id)
{

    int num = conv_char_int_exc((char*)id.data());

    if (num<count)
    {
        for(unsigned int i = 0; i < tab.size(); i++)
        {
            if(tab[i]->getId() == num)
            {
                    delete tab[i];
                    tab.erase(tab.begin()+i);
                    cout << "Element #" << num << " efface"<< endl;
                    return;
            }
        }
        cout << "Element non trouve"<< endl;
    }
    else cout << "Mauvais identifiant"<< endl;
}

void Instructions::RESET()
{
    CLEAR();
    currentFile = " ";
    while(tab.size() > 0)
    {
        delete tab[0];
        tab.erase(tab.begin());
    }
    count = 0;
}

void Instructions::SHOW(string type)
{
    int num = conv_char_int_exc((char*)type.data());

    if (num<count)
    {
        for(unsigned int i=0;i<tab.size();i++)
        {
            if(tab[i]->getId()== num)
            {
                cout << "Element #" << num << endl;
                tab[i]->show();
                i=tab.size();
                return;
            }
        }
        cout << "Element non trouve" << endl;
    }
    else cout << "Mauvais identifiant" << endl;
}

void Instructions::RELOAD()
{
    ifstream fichier(currentFile.data(), ios::in);
    string ligne;

    if(fichier.fail())
    {
        fichier.close();
        return;
    }

    getline(fichier, ligne);
    fichier.close();

    time_t num = conv_char_int((char*)ligne.data());
    if(num > temps)
    {
        cout << "Mise a jour du fichier ..." << endl;
        LOAD(currentFile);
    }
}

void Instructions::USER()
{
    string pass, in;
    ifstream fichier("dat", ios::in);
    if(!fichier.fail())
    {
    getline(fichier, pass);
    fichier.close();
    }
    else return;

    cout << "Password : ";
    cin >> in;
    if(pass.compare(in) == 0)
    {
        cout << "Session d'administrateur" << endl;
        admin = true;
    }
    else cout << "Session d'utilisateur" << endl;
}

void Instructions::EMPRUNTER(string id)
{
    int num = conv_char_int_exc((char*)id.data());

    if (num<count)
    {
        for(unsigned int i = 0; i < tab.size(); i++)
        {
            if(tab[i]->getId() == num)
            {
                    if(tab[i]->estEmprunter()) cout << "Ce media est deja emprunte" << endl;
                    else
                    {
                        tab[i]->setEmprunt(true);
                        cout << "Le media a ete emprunte" << endl;
                        return;
                    }
            }
        }
        cout << "Element non trouve"<< endl;
    }
    else cout << "Mauvais identifiant"<< endl;
}
void Instructions::RENDRE(string id)
{
    int num = conv_char_int_exc((char*)id.data());

    if (num<count)
    {
        for(unsigned int i = 0; i < tab.size(); i++)
        {
            if(tab[i]->getId() == num)
            {
                    if(!tab[i]->estEmprunter()) cout << "Ce media est deja rendu" << endl;
                    else
                    {
                        tab[i]->setEmprunt(false);
                        cout << "Le media a ete rendu" << endl;
                        return;
                    }
            }
        }
        cout << "Element non trouve"<< endl;
    }
    else cout << "Mauvais identifiant"<< endl;
}
