#ifndef KORTTI_H
#define KORTTI_H

#include <string>


using namespace std;
class kortti
{

public:
    kortti();
    kortti(int id,int arvo,string vari);
    void getkortti();
    int arvo;
    int id;
    string vari;

};

#endif // KORTTI_H
