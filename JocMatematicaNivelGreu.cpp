#include "JocMatematicaNivelGreu.h"
#include <ctype.h>
#include <fstream>
#include <iostream>

JocMatematicaGreu::JocMatematicaGreu(const std::string& profesorAdmin) :Joc(profesorAdmin, "Matematica-Nivel Greu", "Greu", "Matematica") {}


int returnScorDinFisier(
    std::ifstream& fisier,
    const std::string& subpunctCerinta,
    const std::string& varianteRaspuns,
    char variantaCorecta,
    const std::string& explicatie
)
{
    char raspunsElev;
    char cereExplicatie;

    std::cout << subpunctCerinta;
    std::cout << varianteRaspuns;

    fisier >> raspunsElev;
    raspunsElev = static_cast<char>(tolower(static_cast<unsigned char>(raspunsElev)));
    std::cout << "Raspuns elev: " << raspunsElev << "\n";

    if (raspunsElev == variantaCorecta)
    {
        std::cout << "Corect! (+30p)\n";
        return 30;
    }
    else
    {
        std::cout << "Gresit! Raspuns corect: " << variantaCorecta << "\n";
        std::cout << "Doriti rezolvarea completa si corecta a exercitiului? (<Y> sau <N>)" << "\n";
        fisier >> cereExplicatie;
        cereExplicatie = static_cast<char>(toupper(static_cast<unsigned char>(cereExplicatie)));
        std::cout << cereExplicatie << "\n";

        if (cereExplicatie == 'Y')
        {
            std::cout << explicatie;
        }
    }

    return 0;
}


int JocMatematicaGreu::joaca()
{
    int scor = 0;

    std::ifstream fisier("matematica_greu.txt");
    if (!fisier.is_open())
    {
        std::cout << "Eroare: nu s-a putut deschide fisierul cu raspunsuri!\n";
        return 0;
    }

    std::cout << "\n ~~~~Joc Matematica - Nivel Avansat~~~~\n";
    std::cout << "Calculati derivata fiecareia dintre urmatoarele functii:\n";

    scor += returnScorDinFisier(
        fisier,
        "Subpunctul a)\n f:(0,∞)->R, f(x)=ln(x)-x+1\n",
        "a) x^2+1\n b) x-1\n c) (1/x)-1\n",
        'c',
        "Rezolvare:\n (lnx)'=1/x\n (-x)'=-1\n RASPUNS FINAL: c) f'(x)=(1/x)-1\n"
    );

    scor += returnScorDinFisier(
        fisier,
        "Subpunctul b)\n f : R* ->R, f(x) = (x + 2) / x\n",
        "a) -2/x^2\n b) 2/x^2\n c) -x^2/2\n",
        'a',
        "Rezolvare:\n f(x)=1+2/x\n f'(x)=-2/x^2\n RASPUNS FINAL: a)\n"
    );

    scor += returnScorDinFisier(
        fisier,
        "Subpunctul c)\n f:R->R, f(n) = (n + 1)e^n\n",
        "a) (n+2)e^n\n b) n*e^n\n c) 1/n\n",
        'a',
        "Rezolvare:\n (u*v)'=u'*v+u*v'\n f'(n)=e^n(n+2)\n RASPUNS FINAL: a)\n"
    );

    fisier.close();

    if (scor >= 30) std::cout << "Felicitari! Scorul obtinut este " << scor << "/90.\n";
    else
    {
        std::cout << "Imi pare rau!Scorul obtinut este " << scor << "/90,dar nu te ingrijora!\n";
        std::cout << "Am pregatit cateva link-uri utile pentru tine care sa te ajute cu studiul la matematica:\n";
        std::cout << "https://www.eduboom.ro - Platforma educativa in limba romana, cu lectii de matematica pentru gimnaziu si liceu, explicate clar si structurat.\n";
        std::cout << "https://www.pauzademate.ro - Site dedicat matematicii, cu exercitii rezolvate, explicatii pas cu pas si materiale utile pentru teste si examene.\n";
    }
    return scor;
}