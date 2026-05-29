#include "JocGeografieNivelGreu.h"
#include <cctype>
#include <algorithm>
#include <iostream>
JocGeografieGreu::JocGeografieGreu(const std::string& profesorAdmin) :Joc(profesorAdmin, "Geografie-Nivel Greu", "Greu", "Geografie") {}

void verifica(std::string raspunsCorect, int& scor)
{
	std::string raspuns;
	std::getline(std::cin, raspuns);
	std::transform(raspuns.begin(), raspuns.end(), raspuns.begin(), ::toupper);
	if (raspunsCorect == raspuns)
	{
		std::cout << "Corect!(+5p)\n";
		scor += 5;
	}
	else
	{
		std::cout << "Gresit!(0p)\n";
	}
}

int JocGeografieGreu::joaca()
{
	int scor = 0;
	std::cout << "\n ~~~~Joc Geografie - Nivel Avansat(Completati spatiile libere)~~~~\n";
	std::cout << "Completati spatiile libere din afirmațiile de mai jos folosind noțiuni geografice corecte.\n";
	std::cout << "Afirmatia 1: Cel mai inalt varf muntos din Europa este ___(1)___, situat in lantul muntos ___(2)___, pe teritoriul statului ___(3)____.\n";
	std::cout << "(1): ";
	verifica("ELBRUS", scor);
	std::cout << "(2): ";
	verifica("CAUCAZ", scor);
	std::cout << "(3): ";
	verifica("RUSIA", scor);

	std::cout << "Afirmatia 2: Stramtoarea Bosfor face legatura intre Marea ____(1)____ si Marea ____(2)____.";
	std::cout << "\n(1): ";
	verifica("NEAGRA", scor);
	std::cout << "(2): ";
	verifica("MARMARA", scor);

	std::cout << "Afirmatia 3: Capitala statului ____(1)____ este orasul Bruxelles, situat pe continentul ____(2)____.";
	std::cout << "\n(1): ";
	verifica("BELGIA", scor);
	std::cout << "(2): ";
	verifica("EUROPA", scor);

	std::cout << "Afirmatia 4: Muntii ____(1)____ reprezinta cel mai inalt lant muntos de pe Glob si se afla pe continentul ____(2)____.";
	std::cout << "\n(1): ";
	verifica("HIMALAYA", scor);
	std::cout << "(2): ";
	verifica("ASIA", scor);

	std::cout << "Afirmatia 5: Insula Sardinia apartine statului ____(1)____ si este localizata in Marea ____(2)____.";
	std::cout << "\n(1): ";
	verifica("ITALIA", scor);
	std::cout << "(2): ";
	verifica("MEDITERANA", scor);

	if (scor >= 15) std::cout << "Felicitari!Scorul obtinut este " << scor << "/55.\n";
	else
	{
		std::cout << "Imi pare rau!Scorul obtinut este " << scor << "/55, dar nu te ingrijora!\n";
		std::cout << "Am pregatit cateva link-uri utile pentru tine care sa te ajute cu studiul la geografie:\n";
		std::cout << "<https://www.lectiigeografie.ro/> Site cu lectii, tutoriale video si ghiduri pentru elevi si profesori, organizate pe teme geografice (clima, relief, populatie etc.)\n";
		std::cout << "<https://www.amazon.com/Discovering-World-Geography-Student-McGraw/dp/0076686973> Manual complet de geografie mondiala (foarte util pentru aprofundare si context global).\n";
	}
	return scor;
}
