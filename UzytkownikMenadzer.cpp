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
