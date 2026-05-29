#include "headers.h"
#include <iostream>

//pentru clasa Utilizator
Utilizator::Utilizator(std::string nume, std::string prenume, std::string username, std::string password):nume(nume),prenume(prenume),username(username),password(password) {}

bool Utilizator::login(const std::string& username, const std::string& password) const
{
	return (this->username == username && this->password == password);
}
std::string Utilizator::getUsername() const
{
	return username;
}
//pentru clasa Elev
Elev::Elev(std::string nume, std::string prenume, std::string username, std::string password,int clasa) : Utilizator(nume,prenume,username,password), clasa(clasa) 
{
	scorGeografie = 0;
	scorMatematica = 0;
}
int Elev::getScorCategorie(const std::string& categorie) const
{
	if (categorie == "Geografie") return scorGeografie;
	if (categorie == "Matematica") return scorMatematica;
	return -1;//categorie adaugata invalida!
}

void Elev::afiseazaJocuriJucate()
{
	std::cout << "Jocuri jucate de elevul " << nume << " " << prenume << ":\n";
	for (auto joc : jocuriJucate)
	{
		int scor = getScorPeJoc(joc);
		std::cout << "- " << joc->getNume() << " [" << joc->getCategorie() << "]" << " <" << scor << ">\n";
	}
}
void Elev::joacaJoc(Joc* joc) 
{
	if (!joc) return; // verificare pointer valid

	int scor = joc->joaca();          // polimorfism: metoda joaca() difera pentru fiecare tip de joc
	jocuriJucate.push_back(joc);      // salveaza jocul in istoric
	auto it = scoruriPeJoc.find(joc);
	if (it == scoruriPeJoc.end())
	{
		scoruriPeJoc[joc] = scor;
	}
	else
	{
		if (scor > it->second)
			it->second = scor;
	}

	if (joc->getCategorie() == "Geografie")
		scorGeografie += scor;
	else if (joc->getCategorie() == "Matematica")
		scorMatematica += scor;
}
int Elev::getScorPeJoc(Joc* joc)
{
	if (!joc) return 0;
	auto it = scoruriPeJoc.find(joc);
	if (it != scoruriPeJoc.end())
		return it->second; //se returneaza scorul(int)

	return 0;
}

void Elev::sugestiiInvatare() const
{
	int scorTotal = getScorCategorie("Matematica") + getScorCategorie("Geografie");
	if (scorTotal < 65)
		std::cout << "La nivel general, sunteti la stadiul de incepator.\n"
		"Se recomanda sa rezolvati exercitiile simple de la ambele categorii si sa accesati link-urile sugerate in cadrul exercitiilor.\n";
	else if (scorTotal < 115)
		std::cout << "La nivel general, sunteti la stadiul de intermediar.\n"
		"Se recomanda sa rezolvati exercitiile de nivel mediu si greu de la ambele categorii de jocuri si sa accesati link-urile sugerate in cadrul exercitiilor pentru lucru suplimentar.\n";
	else
		std::cout << "Felicitari, sunteti la stadiul de avansat!\n"
		"Se recomanda in continuare sa rezolvati exercitiile de nivel dificil de la ambele categorii de jocuri si sa accesati link-urile sugerate in cadrul exercitiilor pentru lucru suplimentar.\n";
}

void Elev::sugestiiInvatare(const std::string& categorie) const
{
	int scorTotal = getScorCategorie(categorie);
	if (scorTotal < 15)
		std::cout << "La categoria " <<categorie << " sunteti la stadiul de incepator.\n"
		"Se recomanda sa rezolvati exercitiile simple si sa accesati link-urile sugerate in cadrul acestora.\n";
	else if (scorTotal < 45)
		std::cout << "La categoria " << categorie << " sunteti la stadiul de intermediar.\n"
		"Se recomanda sa rezolvati exercitiile de nivel mediu si sa accesati link-urile sugerate in cadrul acestora pentru lucru suplimentar.\n";
	else
		std::cout << "Felicitari, sunteti la stadiul de avansat!\n"
		"Se recomanda in continuare sa rezolvati exercitiile de nivel dificil si sa accesati link-urile sugerate in cadrul acestora pentru lucru suplimentar.\n";
}

//pentru clasa Profesor
Profesor::Profesor(std::string nume, std::string prenume, std::string username, std::string password, std::string subject) :Utilizator(nume, prenume,username, password), subject(subject) {}
void Profesor::adaugaJoc(Joc* joc)
{
	if (!joc) return;
	jocuriCreate.push_back(joc);
	std::cout << "Profesorul " << nume << " a adaugat jocul " << joc->getNume()<< "\n";
}

void Profesor::veziScoruriElevi(const std::vector<Elev*>& elevi)
{
	std::cout << "Scorurile elevilor pentru jocurile create de profesorul " << nume << " "<<prenume<< " sunt:\n";
	for (auto elev : elevi)
	{
		bool aJucat = false;
		int scorTotal = 0;

		for (auto joc : elev->getJocuriJucate())
		{
			for (auto jocProf : jocuriCreate)
			{
				if (joc == jocProf) //se compara pointerii
				{
					scorTotal += elev->getScorPeJoc(joc); //scor total al elevului la toate jocurile create de respectivul profesor
					aJucat = true;
				}
			}
		}
		if (aJucat)
		{
			std::cout << "-Elev: " << elev->getNume() << " " << elev->getPrenume() << " scor total pentru categoria de jocuri create de profesorul " 
				       << nume << " " << prenume <<" este "<<scorTotal<<"\n";
	    }
	}
}