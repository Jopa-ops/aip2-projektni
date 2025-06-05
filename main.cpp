#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string rijec;
string skrivena;
int pokusaji;

void unesiRijec() {
    cout << "Unesi riječ koju treba pogoditi: ";
    cin >> rijec;
    skrivena = string(rijec.length(), '_');
    pokusaji = 6;
}

void zapocniIgru() {
    if (rijec.empty()) {
        cout << "Nijedna riječ nije unesena. Unesite riječ prvo.\n";
        return;
    }

    skrivena = string(rijec.length(), '_');
    pokusaji = 6;

    while (skrivena != rijec && pokusaji > 0) {
        cout << "\nRiječ: " << skrivena << "\n";
        cout << "Preostali pokušaji: " << pokusaji << "\n";
        cout << "Unesi slovo: ";
        char slovo;
        cin >> slovo;

        bool pogodak = false;
        for (int i = 0; i < rijec.length(); i++) {
            if (rijec[i] == slovo) {
                skrivena[i] = slovo;
                pogodak = true;
            }
        }

        if (!pogodak) {
            cout << "Promašaj!\n";
            pokusaji--;
        } else {
            cout << "Pogodak!\n";
        }
    }

    if (skrivena == rijec)
        cout << "\nČestitamo! Pogodio si riječ: " << rijec << endl;
    else
        cout << "\nIzgubio si. Tražena riječ je bila: " << rijec << endl;
}

void spremiIgru() {
    ofstream datoteka("game_save.txt");
    if (datoteka.is_open()) {
        datoteka << rijec << endl;
        datoteka << skrivena << endl;
        datoteka << pokusaji << endl;
        datoteka.close();
        cout << "Igra je spremljena.\n";
    } else {
        cout << "Greška pri spremanju igre.\n";
    }
}

void ucitajIgru() {
    ifstream datoteka("game_save.txt");
    if (datoteka.is_open()) {
        getline(datoteka, rijec);
        getline(datoteka, skrivena);
        datoteka >> pokusaji;
        datoteka.close();
        cout << "Igra je učitana.\n";
        zapocniIgru();
    } else {
        cout << "Greška pri učitavanju igre. Provjerite je li igra spremljena.\n";
    }
}

int main() {
    int izbor;

    do {
        cout << "\n--- Meni ---\n";
        cout << "1. Unesi novu riječ\n";
        cout << "2. Započni novu igru\n";
        cout << "3. Spremi igru\n";
        cout << "4. Učitaj spremljenu igru\n";
        cout << "5. Izlaz\n";
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1:
                unesiRijec();
                break;
            case 2:
                zapocniIgru();
                break;
            case 3:
                spremiIgru();
                break;
            case 4:
                ucitajIgru();
                break;
            case 5:
                cout << "Izlaz iz programa.\n";
                break;
            default:
                cout << "Nepoznata opcija. Pokušaj ponovo.\n";
        }
    } while (izbor != 5);

    return 0;
}