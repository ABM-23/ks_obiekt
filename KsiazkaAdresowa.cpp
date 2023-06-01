#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenadzer.logowanieUzytkownika();
    if (uzytkownikMenadzer.czyUzytkownikZalogowany()){
     adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.podajIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMenadzer.wylogowanieUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::dodajAdresata(){
    adresatMenadzer -> dodajAdresata();
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMenadzer -> wyswietlWszystkichAdresatow();
}
