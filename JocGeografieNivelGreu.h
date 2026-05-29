#pragma once
#include "Joc.h"

class JocGeografieGreu : public Joc
{
public:
	JocGeografieGreu(const std::string& profesorAdmin);
	int joaca() override;
};
