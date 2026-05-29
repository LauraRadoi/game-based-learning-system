#pragma once
#include "Joc.h"

class JocGeografieMediu : public Joc
{
public:
	JocGeografieMediu(const std::string& profesorAdmin);
	int joaca() override;
};
