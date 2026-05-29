#pragma once
#include <string>
#include <vector>

struct ScorJoc
{
    std::string username;
    std::string categorie;
    std::string joc;
    std::string dificultate;
    int scor = 0;
};

class Leaderboard
{
private:
   std::vector<ScorJoc> scoruri;
public:
    void adaugaScor(const ScorJoc& scorElev);
    void afiseazaCategorie(const std::string& categorie) const;
    void afiseazaTot() const;
};