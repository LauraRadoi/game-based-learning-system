#pragma once
#include "Joc.h"

class JocGeografieUsor : public Joc
{
public:
	JocGeografieUsor(const std::string& profesorAdmin);
	int joaca() override;
};