#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"

using namespace std;

class KsiazkaAdresowa{
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer* adresatMenadzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_TYMCZASOWEGO;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowego) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_PLIKU_TYMCZASOWEGO(nazwaPlikuTymczasowego) {
        adresatMenadzer = NULL;
    };
    ~KsiazkaAdresowa() {
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    };
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata();
    void usunAdresata();
    void edytujAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyUzytkownikZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
};
#endif
