#ifndef JOC_H
#define JOC_H
#include <string>
#include <map>

class Elev;

class Joc
{
private:
    std::string nume;
    std::string categorie;   // "Matematica", "Geografie"
    std::string dificultate; // "Usor", "Mediu", "Greu"
    std::string profesorAdmin;
    std::map<const Elev*, int> scoruriElevi;

public:
    Joc(std::string profesorAdmin = "invalid", std::string nume="invalid", std::string dificultate="invalid", std::string categorie = "invalid");
    virtual ~Joc() = default; //destructor default-necesar polimorfism

    std::string getNume() const;
    std::string getCategorie() const;
    std::string getDificultate() const;
    std::string getprofesorAdmin() const;

    // polimorfism
    virtual int joaca() = 0; // returneaza scorul obtinut

    // adauga scorul unui elev
    void adaugaScor(const Elev* username, int scor);

    // supraincarcare operator +
    int operator+(int total) const;

    // scor total al jocului
    int getScorTotal() const;
};

#endif //JOC_H
