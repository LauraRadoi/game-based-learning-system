#include <cstring>
#include <vector>
#include <map>
#include "Joc.h"
#ifndef HEADERS_H
#define HEADERS_H


class Utilizator
{
protected: //encapsulare
	std::string nume;
	std::string prenume;
	std::string username;
	std::string password;
public:
	Utilizator(std::string nume = "invalid", std::string prenume = "invalid", std::string username = "invalid", std::string password = "invalid");
	virtual ~Utilizator() = default; //destructor default-necesar polimorfism
	bool login(const std::string& username, const std::string& password) const;
	std::string getUsername()const;
	virtual std::string getRole()= 0;
};

class Elev :public Utilizator
{
private:
	int clasa;
	int scorMatematica; //scorul maxim al elevului la categoria matematica
	int scorGeografie; //scorul maxim obtinut la categoria geografie
	std::vector<Joc*> jocuriJucate;
	std::map<Joc*, int>scoruriPeJoc; //int-scor pe joc

public:
	Elev(std::string nume = "invalid", std::string prenume = "invalid", std::string username = "invalid", std::string password = "invalid", int clasa=-1);
	std::string getRole() override { return "Elev"; }
	// joaca un joc si actualizeaza scorul corespunzator
	void joacaJoc(Joc* joc);
	// returneaza scorul pe categorie
	int getScorCategorie(const std::string& categorie) const;
	// determina dificultatea
	void afiseazaJocuriJucate(); // afiseaza lista jocurilor jucate
	std::string getNume() const { return nume; }
	std::string getPrenume() const { return prenume; }
	std::string getUsername() const { return username; }
	int getClasa() const { return clasa; }

	int getScorPeJoc(Joc* joc);  // scor pe un joc specific
	std::vector<Joc*> getJocuriJucate() { return jocuriJucate; }

	void sugestiiInvatare() const; //sugestii generale(scor total)
	void sugestiiInvatare(const std::string& categorie)const;//sugestii pe categorie
};

class Profesor :public Utilizator
{
private:
	std::string subject;
	std::vector<Joc*>jocuriCreate; //lista joc. create de profesor
public:
	Profesor(std::string nume = "invalid", std::string prenume = "invalid", std::string username = "invalid", std::string password = "invalid", std::string subject = "invalid");
	void adaugaJoc(Joc* joc); //adauga un joc nou in lista profesorului
	std::string getRole() override { return "Profesor"; }
	void veziScoruriElevi(const std::vector<Elev*>& elevi); //
	std::vector<Joc*> getJocuriCreate() { return jocuriCreate; }
	std::string getNume() const { return nume; }
	std::string getPrenume() const { return prenume; }
};

#endif //HEADERS_H


