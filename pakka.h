#ifndef PAKKA_H
#define PAKKA_H

#include "kortti.h"

#include <list>
#include <vector>




class pakka: public kortti
{
public:
    pakka();
    void luoPakka();
    void tulostaPakka();
    vector<kortti> krt;
    vector<kortti>kasi;
    void nostaKortti();
    void tulostaKasi();
    void vaihdakortti(int v);
    void tulostaUudetKortit();
    void varitarkistus();
    void suoratarkistus();
    void paritarkistus();


private:
    int idkasi=0;
    int luku;
    int varipisteet;
    bool suoracheck=false;
    bool paricheck=false;

};


#endif // PAKKA_H
