#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login;
    string haslo;
    //uzytkownik.id = pobierzIdNowegoUzytkownika();
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
int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool KsiazkaAdresowa::czyIstniejeLogin(string login) {
    for (int i = 0; i < (int)uzytkownicy.size(); i++) {
        if (uzytkownicy.at(i).pobierzLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie!" << endl;
             return true;
        }
    }
    return false;
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    for (int i = 0; i < (int)uzytkownicy.size(); i++) {
        cout << uzytkownicy.at(i).pobierzId() << endl;
        cout << uzytkownicy.at(i).pobierzLogin() << endl;
        cout << uzytkownicy.at(i).pobierzHaslo() << endl << endl;
    }
}

