#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class AdresatMenadzer {
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    void dopiszAdresataDoPliku(Adresat adresat);
    void wyswietlDaneAdresata(Adresat adresat);


 public:
    AdresatMenadzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void ustawIdZalogowanegoUzytkownika(int noweId);
};
#endif
