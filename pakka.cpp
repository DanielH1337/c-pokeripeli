#include "pakka.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include "kortti.h"
#include <string>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
vector<kortti>kasi;
vector<kortti> krt;

//Pakka olion tyhja konstruktori
pakka::pakka()
{


}
//Luodaan pakka lisataan oikea arvo, ja vari korteille.
void pakka::luoPakka()
{

    luku = 1;
    for (int y = 0; y < 56; y++ ){

        kortti b = kortti(y,luku,"");
        if (b.id < 14){
            b.vari="pata";
            //luku +=1;
            luku = 2;
        }
        if (b.id > 13 && b.id < 28){
            b.vari="risti";
            //luku +=1;
            luku =2;
        }
        if(b.id > 27 && b.id < 42){
            b.vari = "ruutu";
            //luku +=1;
            luku = 14;
        }
        if(b.id > 41 && b.id < 56){
            b.vari = "hertta";
            luku+=1;

        }
        if(luku >14){
            luku = 1;
        }
        krt.push_back(b);
    }
}
// Funktio pakan tulostamiseen, ei kaytetä pelissa, mutta hyodyllinen mahdolliseen jatkokehitykseen.
void pakka:: tulostaPakka(){
    vector<kortti>::iterator it;
    for (it = krt.begin(); it != krt.end(); it++)
    {
        int id = it->id;
        int arvo = it->arvo;
        string name = it->vari;
        //Print the contents
        cout <<id<< " " <<name << " " << arvo << endl;
    }
}
//Nostaa kortin pakasta, ja laittaa uuden kortin kasi listaan.
void pakka :: nostaKortti(){
    srand((unsigned) time(0));
    int tulos = 1 + (rand() % krt.size());
    cout << krt[tulos].vari << " " << krt[tulos].arvo << endl;
    kortti uusi = kortti (idkasi,krt[tulos].arvo,krt[tulos].vari);
    kasi.push_back(uusi);
    idkasi ++;
    krt.erase(krt.begin()+tulos);
}
//Iteroi kasi listan ja tulostaa ne.
void pakka :: tulostaKasi(){
    vector<kortti>::iterator it;
    for (it = kasi.begin(); it != kasi.end(); it++)
    {
        //int id = it->id;
        int arvo = it->arvo;
        string name = it->vari;
        //Print the contents
        cout << name << " " << arvo  << endl;
    }
}
//Poistaa kortin kadesta ja tulostaa kortit uudestaan
void pakka :: vaihdakortti(int v){
    kasi.erase(kasi.begin()+v);
    tulostaKasi();
}
//Korvaa poistetut kortit uusilla korteilla.
void pakka :: tulostaUudetKortit(){
    while(true){
        if(kasi.size() < 5){
            nostaKortti();
        }else{
            break;
        }
    }
}
//Katsotaan onko vari kaikissa sama.
void pakka :: varitarkistus(){
    int varipisteet=0;
    string vari = kasi[0].vari;
    for(int x = 0; x < kasi.size() ; x++){
        if (kasi[x].vari==vari){
            varipisteet +=1;
        }
    }
    if (varipisteet == 5){
        cout << "Sait varin!" << endl;
    }
}
//Suoran tarkistus
void pakka :: suoratarkistus(){

    for (int y = 0; y < 4;y++){
        if(kasi[y+1].arvo - kasi[y].arvo == -1 ){
            continue;
        }else{
           suoracheck = false;
        }
    }
    if(suoracheck){
        cout << "Sait suoran!" << endl;
    }
}
// Tarkistetaan onko kadessä kaksoiskappaleita.
void pakka :: paritarkistus(){
    vector<kortti>::iterator it;
    int parilaskuri=0;
    bool kolmosetlaskuri=false;
    int kaksiparialaskuri;
    bool tauskasilaskuri=false;
    bool nelosetlaskuri=false;
    int arr[5];
    int var;
    int pos =0;
    //lisataan korttien arvot omaan listaan.
    for (it = kasi.begin(); it != kasi.end(); it++){
        int arvo = it ->arvo;
        arr[pos] = arvo;
        pos++;
    }
    // Järjestetaan lista pienimmasta suurimpaan.
    sort(arr, arr+5);
    //Tauskaden tarkistus
    if(arr[0] == arr[2] and arr[3] == arr[4]){
        tauskasilaskuri = true;
    }
    else if (arr[0] == arr[1] and arr[2] == arr[4]){
        tauskasilaskuri = true;
    }
    //Nelosen tarkistus
    else if (arr[0] == arr[3] and arr[3] != arr[4]){
        nelosetlaskuri = true;
    }
    else if(arr[0]!=arr[1] and arr[1] == arr[4]){
        nelosetlaskuri = true;
    }
    //Kaudaan lista lapi ja tehdaan tarkistus
    for(int n = 0; n < 5; n++){
        if(arr[n] == arr[n+1]){
            parilaskuri +=1;
            if(var != arr[n] ){
                kaksiparialaskuri += 1;
            }
            var = arr[n];

        }
        if(arr[n] == arr[n+2]){
            kolmosetlaskuri=true;
        }

    }
    //Vitosen tarkistus.
    if(parilaskuri == 4 ){
        cout << "Sait vitoset!" << endl;
    }
    else if (nelosetlaskuri){
        cout << "Sait neloset!" << endl;
    }

    //Tauskaden tarkistus
    else if(tauskasilaskuri){
        cout << "Sait tauskaden!" << endl;
    }
    //Kolmosten tarkistus
    else if(kolmosetlaskuri ){
        cout << "Sait kolmoset!" << endl;
    }

    //Kaksi paria tarkistus
    else if(kaksiparialaskuri==2){
        cout << "Sait kaksi paria!" << endl;
    }
    //Parin tarkistus
    else if(parilaskuri == 1){
        cout << "Sait parin !" << endl;
    }


}
