#include <iostream>
#include "pakka.h"
using namespace std;
void uusikierros();
int main()
{
    int korttiLaskuri=0;
    int vaihtoKortit=0;
    string vastaus;
    //Luodaan pakka olio pelia varten.
    pakka a = pakka();
    a.luoPakka();
    //Nostetaan kortit valitsemalla k/e
    while(true){
        cout << "Haluatko nostaa kortin? k/e ";
        cin >> vastaus;
        if(vastaus == "k"){
            a.nostaKortti();
            korttiLaskuri +=1;
        }
        else if (vastaus=="e" ){
            break;
        }
        if(korttiLaskuri == 5){
            break;
        }
    }
    system("CLS");
    cout <<"\n"<<"Tassa on nostamasi kortit" << "\n" << endl;
    //Nostetaan kortit ja tulostetaan uusi kasi
    a.tulostaKasi();
    cout << "\n" << endl;
    while(true){
        if(vaihtoKortit == 99){
            // Tyhjennetään näkymä ennen korttien tulostusta.
           system("CLS");
           cout << "Tassa on vaihdetut kortit" << endl;
           a.tulostaKasi();
           a.tulostaUudetKortit();
            break;
        }
        cout << "Minka kortin haluat vaihtaa? Valitse 0,1,2,3,4 yksi kerrallaan, lopeta valitsemalla numero 99:  ";
        cin >> vaihtoKortit;
        if(vaihtoKortit != 99){
            a.vaihdakortti(vaihtoKortit);

        }
        cout << "\n" << endl;
    }
 //Kaden tarkistukset
 a.varitarkistus();
 a.suoratarkistus();
 a.paritarkistus();
 string vas;
 cout << "Haluatko pelata uudestaan? k/e?" << endl;
 cin >> vas;
 if(vas  == "k"){
     system("CLS");
     uusikierros();
 }

 return 0;

}
//Funkio uudelle kierrokselle
void uusikierros(){
    main();
}
