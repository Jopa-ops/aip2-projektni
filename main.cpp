#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string rijec;
    cout << "Unesi riječ koju treba pogoditi: ";
    cin >> rijec;

    string skrivena(rijec.length(), '_');
    int pokusaji = 6;

    while (skrivena != rijec && pokusaji > 0)
    {
        cout << "\nRiječ: " << skrivena << "\n";
        cout << "Preostali pokušaji: " << pokusaji << "\n";
        cout << "Unesite slovo: ";
        char slovo;
        cin >> slovo;

        slovo = tolower(slovo); // pretvori unos u malo slovo
        bool pogodak = false;

        for (int i = 0; i < rijec.length(); i++)
        {
            if (tolower(rijec[i]) == slovo && skrivena[i] == '_') // uspoređuj neovisno o veličini slova
            {
                skrivena[i] = rijec[i]; // zadrži originalno slovo (veliko ili malo)
                pogodak = true;
            }
        }

        if (!pogodak)
        {
            cout << "Promašaj!\n";
            pokusaji--;
        }
        else
        {
            cout << "Pogodak!\n";
        }
    }

    if (skrivena == rijec)
    {
        cout << "\n Čestitamo! Pogodio si riječ." << rijec << endl;
    }
    else
    {
        cout << "Izgubio si. Tražena riječ je bila:" << rijec << endl;
        return 0;
    }