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
