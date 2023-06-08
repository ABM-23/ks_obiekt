#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenadzer.logowanieUzytkownika();
    if (uzytkownikMenadzer.czyUzytkownikZalogowany()){
     adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.podajIdZalogowanegoUzytkownika(), NAZWA_PLIKU_TYMCZASOWEGO);
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
bool KsiazkaAdresowa::czyUzytkownikZalogowany(){
    return uzytkownikMenadzer.czyUzytkownikZalogowany();
}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    adresatMenadzer -> wyszukajAdresatowPoImieniu();
}
void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    adresatMenadzer -> wyszukajAdresatowPoNazwisku();
}
void KsiazkaAdresowa::usunAdresata(){
    adresatMenadzer -> usunAdresata();
}
void KsiazkaAdresowa::edytujAdresata(){
    adresatMenadzer -> edytujAdresata();
}


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
