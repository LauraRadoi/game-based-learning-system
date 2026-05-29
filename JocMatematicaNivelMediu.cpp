#include "JocMatematicaNivelMediu.h"
#include <ctype.h>
#include <fstream>
#include <iostream>

JocMatematicaMediu::JocMatematicaMediu(const std::string& profesorAdmin) :Joc(profesorAdmin, "Matematica-Nivel Mediu", "Mediu", "Matematica") {}

int JocMatematicaMediu::joaca()
{
    int scor = 0;

    std::ifstream fisier("matematica_mediu.txt");
    if (!fisier.is_open())
    {
        std::cout << "Eroare: Nu s-a putut deschide fisierul cu raspunsuri!\n";
        return 0;
    }

    char raspunsElev, cereRezolvare;

    std::cout << "\n ~~~~Joc Matematica - Nivel Mediu~~~~\n";

    std::cout << "Subpunctul a)\n";
    std::cout << "In triunghiul ABC, cu m(^A)=90', avem AB=12 si AC=5.\n";
    std::cout << "Atunci sin B - cos B este egal cu:\n";
    std::cout << "a) 7/13\n b) -7/13\n c) 17/13\n d) -17/13\n";

    fisier >> raspunsElev;
    raspunsElev = static_cast<char>(tolower(static_cast<unsigned char>(raspunsElev)));
    std::cout << "Raspuns: " << raspunsElev << "\n";

    if (raspunsElev == 'b')
    {
        std::cout << "Corect! (+20p)\n";
        scor += 20;
    }
    else
    {
        std::cout << "Gresit! Raspuns corect: b.\nDoriti rezolvarea completa si corecta a exercitiului?\n";
        fisier >> cereRezolvare;
        cereRezolvare = static_cast<char>(toupper(static_cast<unsigned char>(cereRezolvare)));
        std::cout << cereRezolvare << "\n";

        if (cereRezolvare == 'Y')
        {
            std::cout << "Triunghi dreptunghic in A => BC este ipotenuza\n";
            std::cout << "BC = sqrt(12^2 + 5^2) = 13\n";
            std::cout << "sin B = 5/13, cos B = 12/13\n";
            std::cout << "sin B - cos B = -7/13\n";
            std::cout << "RASPUNS FINAL: b) -7/13\n";
        }
    }

    // ---------------- Subpunctul b ----------------
    std::cout << "\n----------------------------------\n";
    std::cout << "Subpunctul b)\n";
    std::cout << "Fie x apartine intervalului (90',180') cu sin x = 2/5.\n";
    std::cout << "Atunci sin 2x este egal cu:\n";
    std::cout << "a) -4(radical din)21/25\n b) 4/5\n c) 4(radical din)21/25\n d) 0\n";

    fisier >> raspunsElev;
    raspunsElev = static_cast<char>(tolower(static_cast<unsigned char>(raspunsElev)));
    std::cout << "Raspuns: " << raspunsElev << "\n";

    if (raspunsElev == 'a')
    {
        std::cout << "Corect! (+20p)\n";
        scor += 20;
    }
    else
    {
        std::cout << "Gresit! Raspuns corect: a\nDoriti rezolvarea completa si corecta a exercitiului?\n";
        fisier >> cereRezolvare;
        cereRezolvare = static_cast<char>(toupper(static_cast<unsigned char>(cereRezolvare)));
        std::cout << cereRezolvare << "\n";

        if (cereRezolvare == 'Y')
        {
            std::cout << "cos^2x = 1 - sin^2x = 21/25\n";
            std::cout << "cos x = -(radical din)21/5 (cadranul II)\n";
            std::cout << "sin 2x = 2*sin x*cos x = -4(radical din)21/25\n";
            std::cout << "RASPUNS FINAL: a) -4(radical din)21/25\n";
        }
    }

    fisier.close();

    if (scor >= 20) std::cout << "Felicitari! Scorul obtinut este " << scor << "/40.\n";
    else
    {
        std::cout << "Imi pare rau!Scorul obtinut este " << scor << "/40,dar nu te ingrijora!\n";
        std::cout << "Am pregatit cateva link-uri utile pentru tine care sa te ajute cu studiul la matematica:\n";
        std::cout << "https://www.eduboom.ro - Platforma educativa in limba romana, cu lectii de matematica pentru gimnaziu si liceu, explicate clar si structurat.\n";
        std::cout << "https://www.pauzademate.ro - Site dedicat matematicii, cu exercitii rezolvate, explicatii pas cu pas si materiale utile pentru teste si examene.\n";
    }

    return scor;
}