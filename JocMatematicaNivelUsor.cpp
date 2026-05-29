#include "JocMatematicaNivelUsor.h"
#include <ctype.h>
#include <iostream>

JocMatematicaUsor::JocMatematicaUsor(const std::string& profesorAdmin):Joc(profesorAdmin,"Matematica-Nivel Usor","Usor","Matematica") {}

int JocMatematicaUsor::joaca()
{
	int scor = 0;
	char raspuns;

	std::cout << "\n ~~~~Joc Matematica - Nivel Usor~~~~\n";
	std::cout << "Intr-o progresie geometrica (bn)n∈N* avem b5=24 si b2=3.Calculati b1*b6.\n";
	std::cout << "a) 8\n b) 27\n c) 72\n d) 73\n";
    std::cout << "Raspuns: ";
    std::cin >> raspuns;
    raspuns = static_cast<char>(tolower(static_cast<unsigned char>(raspuns)));
    if (raspuns == 'c')
    {
        std::cout << "Corect!\n";
        scor += 15;
    }
    else
    {
        char ras;
        std::cout << "Gresit! Raspuns corect: c\n";
        std::cout << "Doriti rezolvarea completa si corecta a exercitiului? (<Y> sau <N>)" << "\n";
        std::cin >> ras;
        ras = static_cast<char>(toupper(static_cast<unsigned char>(ras)));
        if (ras == 'Y')
        {
            std::cout << "Formula termenului general al progresiei geometrice: bn=b1*q^(n-1), unde b1=primul termen si q = rația progresiei\n";
            std::cout << "Pentru a calcula ratia, ne folosim de informatiile date:b2 si b5\n b2=b1*q\n b1*q=3 (1)\n b5=b1*q^4\n b1*q^4=24 (2)\n";
            std::cout << "Impartim ecuatia (2) la ecuatia (1): b1*q^4/b1*q=24/3=>q^3=8=>q=2\n";
            std::cout << "Din ecuatia (1): b1=3/q=3/2\n Calculam b6:\n b6=b1*q^5=3/2*2^5=(3/2)*32=48\n Calculam produsul: b1*b6=3/2*48=72\n RASPUNS FINAL: c) 72\n";
        }
    }
    if (scor == 15) std::cout << "Felicitari! Scorul obtinut este " << scor << "/15.\n";
    else
    {
        std::cout << "Imi pare rau!Scorul obtinut este " << scor << "/15,dar nu te ingrijora!\n";
        std::cout << "Am pregatit cateva link-uri utile pentru tine care sa te ajute cu studiul la matematica:\n";
        std::cout << "https://www.eduboom.ro - Platforma educativa in limba romana, cu lectii de matematica pentru gimnaziu si liceu, explicate clar si structurat.\n";
        std::cout << "https://www.pauzademate.ro - Site dedicat matematicii, cu exercitii rezolvate, explicatii pas cu pas si materiale utile pentru teste si examene.\n";
    }
    return scor;
}
