#include "Aplicatie.h"
#include "JocGeografieNivelGreu.h"
#include "JocGeografieNivelMediu.h"
#include "JocGeografieNivelUsor.h"
#include "JocMatematicaNivelGreu.h"
#include "JocMatematicaNivelMediu.h"
#include "JocMatematicaNivelUsor.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Aplicatie::ruleaza()
{
    std::string linieDinFisier;

    // Citire profesori 
    std::ifstream fProf("Profesori.txt");
    while (std::getline(fProf, linieDinFisier))
    {
        std::stringstream ss(linieDinFisier);
        std::string nume, prenume, username, parola, subject;

        std::getline(ss, nume, ';');
        std::getline(ss, prenume, ';');
        std::getline(ss, username, ';');
        std::getline(ss, parola, ';');
        std::getline(ss, subject, ';');

        profesori.push_back(new Profesor(nume, prenume, username, parola, subject));
    }
    fProf.close();

    // Citire elevi
    std::ifstream fElev("Elevi.txt");
    while (std::getline(fElev, linieDinFisier))
    {
        std::stringstream ss(linieDinFisier);
        std::string nume, prenume, username, parola, clasaStr;
        int clasa;

        std::getline(ss, nume, ';');
        std::getline(ss, prenume, ';');
        std::getline(ss, username, ';');
        std::getline(ss, parola, ';');
        std::getline(ss, clasaStr, ';');
        clasa = std::stoi(clasaStr);

        elevi.push_back(new Elev(nume, prenume, username, parola, clasa));
    }
    fElev.close();

    //Citire jocuri
    std::ifstream fJoc("Jocuri.txt");
    while (std::getline(fJoc, linieDinFisier))
    {
        std::stringstream ss(linieDinFisier);
        std::string profesorAdmin, categorie, dificultate;

        std::getline(ss, profesorAdmin, ';');
        std::getline(ss, categorie, ';');
        std::getline(ss, dificultate, ';');

        Joc* joc = nullptr;

        if (categorie == "Geografie" && dificultate == "Greu")
            joc = new JocGeografieGreu(profesorAdmin);
        else if (categorie == "Geografie" && dificultate == "Mediu")
            joc = new JocGeografieMediu(profesorAdmin);
        else if (categorie == "Geografie" && dificultate == "Usor")
            joc = new JocGeografieUsor(profesorAdmin);
        else if (categorie == "Matematica" && dificultate == "Mediu")
            joc = new JocMatematicaMediu(profesorAdmin);
        else if (categorie == "Matematica" && dificultate == "Greu")
            joc = new JocMatematicaGreu(profesorAdmin);
        else if (categorie == "Matematica" && dificultate == "Usor")
            joc = new JocMatematicaUsor(profesorAdmin);

        if (joc)
        {
            jocuri.push_back(joc);

            // Asociere joc-profesor
            for (auto prof : profesori)
            {
                if (prof->getNume() + " " + prof->getPrenume() == profesorAdmin)
                {
                    prof->adaugaJoc(joc);
                }
            }
        }
    }
    fJoc.close();

    //Elevii joaca jocurile
    for (auto* elev : elevi)
    {
        for (auto* joc : jocuri)
        {
            elev->joacaJoc(joc);
            int scor = elev->getScorPeJoc(joc);
            joc->adaugaScor(elev, scor);

            ScorJoc scorLB;
            scorLB.username = elev->getUsername();
            scorLB.categorie = joc->getCategorie();
            scorLB.joc = joc->getNume();
            scorLB.dificultate = joc->getDificultate();
            scorLB.scor = scor;

            leaderboard.adaugaScor(scorLB);
        }
    }

    //Istoric + sugestii
    for (auto elev : elevi)
    {
        std::cout << "\n     ISTORIC " << elev->getNume() << " " << elev->getPrenume() << " =====\n";
        elev->afiseazaJocuriJucate();
        elev->sugestiiInvatare();
        elev->sugestiiInvatare("Matematica");
        elev->sugestiiInvatare("Geografie");
    }

    // Leaderboard
    leaderboard.afiseazaTot();

    //Scor total jocuri (operator + supraincarcat)
    for (auto joc : jocuri)
    {
        std::cout << "\nScor total pentru jocul "
            << joc->getNume() << " = "
            << joc->getScorTotal() << "\n";
    }

    //Profesori
    for (auto prof : profesori)
        prof->veziScoruriElevi(elevi);

    // ~Clean~
    for (auto joc : jocuri) delete joc;
    for (auto elev : elevi) delete elev;
    for (auto prof : profesori) delete prof;
}
