#include <iostream>
#include "JocGeografieNivelUsor.h"
#include <cctype>

JocGeografieUsor::JocGeografieUsor(const std::string& profesorAdmin) :Joc(profesorAdmin, "Geografie-Nivel Usor", "Usor", "Geografie") {}

int returnScor(
    const std::string& intrebare,
    char raspunsCorect,
    const std::string& indiciu,
    const std::string& explicatie)
{
    char ras, raspuns;
    std::cout << intrebare;
    std::cin >> ras;
    ras = toupper(ras);
    if (ras == 'Y')
    {
        std::cout << indiciu;
    }
    std::cin >> raspuns;
    raspuns = static_cast<char>(toupper(static_cast<unsigned char>(raspuns)));
    if (raspuns == raspunsCorect)
    {
        std::cout << "Corect!\n";
        return 10;
    }
    else
    {
        char varianta;
        std::cout << "Gresit! Doriti explicatia pentru aceasta intrebare?(Y–Da/N–Nu)\n";
        std::cin >> varianta;
        varianta = static_cast<char>(toupper(static_cast<unsigned char>(varianta)));
        if (varianta == 'Y')
        {
            std::cout << explicatie;
        }
    }
    return 0;
}
int JocGeografieUsor::joaca()
{
    int scor = 0;
    std::cout << "\n ~~~~Joc Geografie - Nivel Usor(Adevarat sau Fals)~~~~\n";
    std::cout << "Raspundeti cu A(Adevarat) sau F(Fals) la urmatoarele afirmatii:\n";
    scor += returnScor(
        "1.Romania este traversata de paralela de 45° latitudine nordica.\nAveti nevoie de un indiciu pentru aceasta intrebare?(Y–Da/N–Nu)\n",
        'A',
        "Ganditi-va la pozitia Romaniei pe glob, intre Ecuator si Polul Nord.\n",
        "Paralela de 45° latitudine nordica trece prin centrul Romaniei, fiind un element important de pozitionare geografica.\nRaspunsul corect este A!\n"
    );
    scor += returnScor(
        "2.Clima Romaniei este predominant tropicala.\nAveti nevoie de un indiciu pentru aceasta intrebare ? (Y–Da / N–Nu)\n",
        'F',
        "Ganditi-va la anotimpuri si zona climatica in care este situata Romania pe glob\n",
        "Romania are o clima temperat-continentala, caracterizata prin veri calde si ierni reci, cu influente oceanice, continentale si mediteraneene, nu tropicale.\nRaspunsul corect este F!\n"
    );
    scor += returnScor(
        "3.Europa este continentul cu cea mai mare densitate a populatiei la nivel mondial.\nAveti nevoie de un indiciu pentru aceasta intrebare?(Y–Da/N–Nu)\n",
        'F',
        "Ganditi-va la continentul cu cea mai mare populație totală\n",
        "Asia are cea mai mare densitate si cel mai mare numar de locuitori, datorita populatiei foarte mari din state precum China si India.\nRaspunsul corect este F!\n"
    );
    scor += returnScor(
        "4.Podisurile sunt forme de relief mai joase decat campiile.\nAveti nevoie de un indiciu pentru aceasta intrebare ? (Y–Da / N–Nu)\n",
        'F',
        "Comparati altitudinea medie a campiilor cu cea a podisurilor.\n",
        "Podisurile sunt, in general, mai inalte decat campiile, dar au suprafete relativ plane.\nRaspunsul corect este F!\n"
    );
    scor += returnScor(
        "5.Clima mediteraneana se caracterizeaza prin veri calde si uscate si ierni blande si ploioase.\nAveti nevoie de un indiciu pentru aceasta intrebare?(Y–Da/N–Nu)\n",
        'A',
        "Ganditi-va cum sunt verile in Grecia, Italia sau Spania.\n",
        "Acest tip de clima este specific sudului Europei si influenteaza vegetatia de tip mediteranean.\nRaspunsul corect este A!\n"
    );

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