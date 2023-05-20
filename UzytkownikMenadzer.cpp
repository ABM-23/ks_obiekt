#include "UzytkownikMenadzer.h"

void UzytkownikMenadzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login;
    string haslo;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);

    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenadzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikMenadzer::czyIstniejeLogin(string login) {
    for (int i = 0; i < (int)uzytkownicy.size(); i++) {
        if (uzytkownicy.at(i).pobierzLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie!" << endl;
             return true;
        }
    }
    return false;
}
void UzytkownikMenadzer::wypiszWszystkichUzytkownikow(){
    for (int i = 0; i < (int)uzytkownicy.size(); i++) {
        cout << uzytkownicy.at(i).pobierzId() << endl;
        cout << uzytkownicy.at(i).pobierzLogin() << endl;
        cout << uzytkownicy.at(i).pobierzHaslo() << endl << endl;
    }
}
void UzytkownikMenadzer::wczytajUzytkownikowZPliku(){
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
void UzytkownikMenadzer::logowanieUzytkownika(){
    idZalogowanegoUzytkownika = sprawdzLoginIHaslo();
}
void UzytkownikMenadzer::wylogowanieUzytkownika(){
    idZalogowanegoUzytkownika = 0;
}
int UzytkownikMenadzer::sprawdzLoginIHaslo()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return itr -> pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika) {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
void UzytkownikMenadzer::zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik> uzytkownicy){
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
