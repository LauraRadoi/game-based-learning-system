#include "JocGeografieNivelMediu.h"
#include <algorithm> //random_shuffle
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <fstream>
#include <iostream>

JocGeografieMediu::JocGeografieMediu(const std::string& profesorAdmin) :Joc(profesorAdmin, "Geografie-Nivel Mediu", "Mediu", "Geografie") {}

int JocGeografieMediu::joaca()
{
    std::cout << "\n ~~~~Joc Geografie - Nivel Mediu(Intrebari aleatorii)~~~~\n";
    std::string intrebari[7] =
    {
      "1: Care este cel mai inalt varf muntos din Romania?\n a) Varful Omu\n b) Varful Moldoveanu\n c) Varful Negoiu\n",
      "2: Pe ce continent este situata Romania?\n a) Asia\n b) Africa\n c) Europa\n",
      "3: Care este capitala Canadei?\n a) Toronto\n b)Ottawa\n  c) Vancouver\n",
      "4: Muntii Himalaya se afla pe continentul:\n a) Asia\n b) America de Sud\n c) Europa\n",
      "5: Insula Sicilia apartine statului:\n a) Spania\n b) Grecia\n c) Italia\n",
      "6: Care dintre urmatoarele orase este capitala Australiei?\n a) Sydney\n b) Melbourne\n c) Canberra\n",
      "7: Care este cel mai inalt munte din lume, dupa altitudine?\n a) Mont Blanc\n b) Everest\n c) Kilimanjaro\n "
    };
    char raspunsCorect[7] = { 'b','c','b','a','c','c','b' };
    std::vector<int> indici = { 0,1,2,3,4,5,6 };
    int scor = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_shuffle(indici.begin(), indici.end());

    std::ifstream fisier("geografie_mediu.txt");
    if (!fisier.is_open())
    {
        std::cout << "Eroare: nu s-a putut deschide fisierul cu raspunsuri!\n";
        return 0;
    }

    for (int i = 0; i < 5; i++)
    {
        int idx = indici[i];
        std::cout << "\nIntrebarea " << intrebari[idx] << "\n";

        char raspunsElev;
        fisier >> raspunsElev;   // CITIRE DIN FISIER
        raspunsElev = static_cast<char>(tolower(static_cast<unsigned char>(raspunsElev)));

        std::cout << "Raspuns: " << raspunsElev << "\n";

        if (raspunsElev != 'a' && raspunsElev != 'b' && raspunsElev != 'c')
        {
            std::cout << "Raspuns invalid in fisier!\n";
            continue;
        }

        if (raspunsElev == raspunsCorect[idx])
        {
            std::cout << "Corect! (+10p)\n";
            scor += 10;
        }
        else
        {
            std::cout << "Gresit! Raspuns corect: " << raspunsCorect[idx] << "\n";
        }
    }

    fisier.close();
    if (scor >= 20) std::cout << "Felicitari!Scorul obtinut este " << scor << "/50.\n";
    else
    {
        std::cout << "Imi pare rau!Scorul obtinut este " << scor << "/50,dar nu te ingrijora!\n";
        std::cout << "Am pregatit cateva link-uri utile pentru tine care sa te ajute cu studiul la geografie.\n";
        std::cout << "<https://www.lectiigeografie.ro/> Site cu lectii, tutoriale video si ghiduri pentru elevi si profesori, organizate pe teme geografice (clima, relief, populatie etc.)\n";
        std::cout << "<https://www.amazon.com/Discovering-World-Geography-Student-McGraw/dp/0076686973> Manual complet de geografie mondiala (foarte util pentru aprofundare si context global).\n";
    }
    return scor;
}