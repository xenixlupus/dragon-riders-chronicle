#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string plikNazwa = "kronika.txt";

// ================= DODAWANIE =================
void dodaj() {
    ofstream plik(plikNazwa, ios::app);

    string imie;
    string rod;
    string tytul;
    string smok;
    string kolor;
    string lata;
    string los;
    string przyczyna;

    cout << "\n===== DODAWANIE JEZDZCA =====\n";

    cout << "Imie: ";
    getline(cin, imie);

    cout << "Rod: ";
    getline(cin, rod);

    cout << "Tytul: ";
    getline(cin, tytul);

    cout << "Smok: ";
    getline(cin, smok);

    cout << "Kolor smoka: ";
    getline(cin, kolor);

    cout << "Lata: ";
    getline(cin, lata);

    cout << "Los (zyje/polegl/zaginiony): ";
    getline(cin, los);

    cout << "Przyczyna smierci: ";
    getline(cin, przyczyna);

    plik << imie << ";"
         << rod << ";"
         << tytul << ";"
         << smok << ";"
         << kolor << ";"
         << lata << ";"
         << los << ";"
         << przyczyna << endl;

    cout << "\n[✔] Dodano wpis do kroniki!\n";

    plik.close();
}

// ================= WYSWIETLANIE =================
void wyswietl() {
    ifstream plik(plikNazwa);
    string linia;

    cout << "\n=============================================\n";
    cout << "        KRONIKA SMOCZYCH JEZDCOW \n";
    cout << "=============================================\n\n";

    bool pierwszy = true;

    while (getline(plik, linia)) {

        // pomijanie naglowka
        if (pierwszy) {
            pierwszy = false;
            continue;
        }

        string dane[8];

        int start = 0;
        int koniec;
        int index = 0;

        while ((koniec = linia.find(';', start)) != string::npos) {
            dane[index++] = linia.substr(start, koniec - start);
            start = koniec + 1;
        }

        dane[index] = linia.substr(start);

        cout << "\n----------------------------------------\n";
        cout << "Imie              : " << dane[0] << endl;
        cout << "Rod               : " << dane[1] << endl;
        cout << "Tytul             : " << dane[2] << endl;
        cout << "Smok              : " << dane[3] << endl;
        cout << "Kolor smoka       : " << dane[4] << endl;
        cout << "Lata              : " << dane[5] << endl;
        cout << "Los               : " << dane[6] << endl;
        cout << "Przyczyna smierci : " << dane[7] << endl;
    }

    cout << "\n========================================\n";

    plik.close();
}

// ================= WYSZUKIWANIE =================
void szukaj() {
    ifstream plik(plikNazwa);
    string linia, szukane;

    cout << "Czego szukasz? ";
    getline(cin, szukane);

    cout << "\n===== WYNIKI =====\n";

    while (getline(plik, linia)) {
        if (linia.find(szukane) != string::npos) {
            cout << linia << endl;
        }
    }

    cout << "==================\n";
    plik.close();
}

// ================= USUWANIE =================
void usun() {
    ifstream plik(plikNazwa);
    ofstream temp("temp.txt");

    string linia, doUsuniecia;

    cout << "Podaj tekst do usuniecia: ";
    getline(cin, doUsuniecia);

    while (getline(plik, linia)) {
        if (linia.find(doUsuniecia) == string::npos) {
            temp << linia << endl;
        }
    }

    plik.close();
    temp.close();

    remove("kronika.txt");
    rename("temp.txt", "kronika.txt");

    cout << "\n[✔] Usunieto wpis(y)!\n";
}

// ================= MENU =================
void menu() {
    cout << "\n====================================\n";
    cout << "      KRONIKA SMOCZYCH JEZDCOW \n";
    cout << "====================================\n";
    cout << "1. Dodaj wpis\n";
    cout << "2. Wyswietl kronike\n";
    cout << "3. Wyszukaj\n";
    cout << "4. Usun wpis\n";
    cout << "5. Wyjscie\n";
    cout << "====================================\n";
    cout << "Wybor: ";
}

// ================= MAIN =================
int main() {
    int wybor;

    do {
        menu();
        cin >> wybor;
        cin.ignore(); // bardzo wazne!

        switch (wybor) {
            case 1:
                dodaj();
                break;
            case 2:
                wyswietl();
                break;
            case 3:
                szukaj();
                break;
            case 4:
                usun();
                break;
            case 5:
                cout << "Zamykanie kroniki...\n";
                break;
            default:
                cout << "Niepoprawny wybor!\n";
        }

    } while (wybor != 5);

    return 0;
}