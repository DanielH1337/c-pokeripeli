#include "kortti.h"

#include <iostream>
#include <string>

using namespace std;
int arvo;
int id;
string vari;



kortti::kortti(){

}
//Kortti olio id arvo ja vari.
kortti::kortti(int id,int arvo, string vari)
{
    this-> id = id;
    this-> arvo = arvo;
    this-> vari=vari;
}
