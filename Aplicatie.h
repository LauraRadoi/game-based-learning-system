#pragma once
#include "headers.h"
#include "Joc.h"
#include "Leaderboard.h"
#include <vector>
#include <string>

class Aplicatie
{
private:
    std::vector<Elev*> elevi;
    std::vector<Profesor*> profesori;
    std::vector<Joc*> jocuri;
    Leaderboard leaderboard;

public:
    void ruleaza();
};
