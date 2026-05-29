#include "Joc.h"

Joc::Joc(std::string profesorAdmin, std::string nume, std::string dificultate, std::string categorie)
    : profesorAdmin(profesorAdmin), nume(nume), dificultate(dificultate), categorie(categorie) {}

std::string Joc::getNume() const
{
    return nume;
}

std::string Joc::getCategorie() const
{
    return categorie;
}

std::string Joc::getDificultate() const
{
    return dificultate;
}

std::string Joc::getprofesorAdmin() const
{
    return profesorAdmin;
}

void Joc::adaugaScor(const Elev* username, int scor)
{
    auto it = scoruriElevi.find(username);
    if (it == scoruriElevi.end()) 
    {
        // elevul nu exista, adaugam scorul
        scoruriElevi[username] = scor;
    }
    else 
    {
        //se pastreaza scorul maxim
        if (scor > it->second)
            it->second = scor;
    }
}

int Joc::operator+(int total) const
{
    int suma = total;
    for (const auto& elev : scoruriElevi)
    {
        suma += elev.second;
    }
    return suma;
}

int Joc::getScorTotal() const {
    return *this + 0;
}