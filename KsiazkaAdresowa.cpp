#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenadzer.logowanieUzytkownika();
    adresatMenadzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenadzer.podajIdZalogowanegoUzytkownika());
    adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMenadzer.wylogowanieUzytkownika();
    adresatMenadzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenadzer.podajIdZalogowanegoUzytkownika());
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::dodajAdresata(){
    adresatMenadzer.dodajAdresata();
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMenadzer.wyswietlWszystkichAdresatow();
}
