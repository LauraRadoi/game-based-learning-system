#include "Leaderboard.h"
#include <iostream>
#include <algorithm>

void Leaderboard::adaugaScor(const ScorJoc& scorElev)
{
	scoruri.push_back(scorElev);
}

bool comparator(const ScorJoc& a, const ScorJoc& b)
{
    return a.scor > b.scor;
}

void Leaderboard::afiseazaCategorie(const std::string& categorie) const
{
    std::vector<ScorJoc> jocuriCategorie;
    for (const auto& s : scoruri) 
    {
        if (s.categorie == categorie) jocuriCategorie.push_back(s);
    }
    std::sort(jocuriCategorie.begin(), jocuriCategorie.end(), comparator);
    std::cout << "\n====================================\n";
    std::cout << "\n   LEADERBOARD~" << categorie << "\n";
    int loc = 1;
    for (const auto& scor1 : jocuriCategorie)
    {
        std::cout << "LOCUL " << loc++ << ":\n";
        std::cout << "  USER: " << scor1.username << "\n";
        std::cout << "  JOC: " << scor1.joc << "\n";
        std::cout << "  DIFICULTATE: " << scor1.dificultate << "\n";
        std::cout << "  SCOR: " << scor1.scor << "\n";
        std::cout << "------------------------------------\n";
    }
    if(jocuriCategorie.empty())
      std::cout << "\nNu exista jocuri jucate din aceasta categorie.\n";
}

void Leaderboard::afiseazaTot() const
{
    afiseazaCategorie("Matematica");
    afiseazaCategorie("Geografie");
}