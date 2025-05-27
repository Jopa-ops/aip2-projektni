#include <iostream>
#include <string>
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
        bool pogodak = false;
        for (int i = 0; i < rijec.length(); i++)
        {
            if (rijec[i] == slovo)
            {
                skrivena[i] = slovo;
                pogodak = true;
            }
        } 
        if(!pogodak)
        {
            cout << "Promašaj!";
        }